#include "PmergeMe.hpp"


long	what_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + (tv.tv_usec ));
}

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(const  PmergeMe &rhs)
{
	*this = rhs;
}
PmergeMe    &PmergeMe::operator = (const  PmergeMe &rhs)
{
	this->op1 = rhs.op1;
	this->op2 = rhs.op2;
	return (*this);
}
void    PmergeMe::set_stamp(void)
{
	this->stamp = what_time();
}

void    PmergeMe::get_time(int i)
{
	if (i == 1)
		this->t1 = what_time() - this->stamp;
	if (i == 2)
		this->t2 = what_time() - this->stamp;
}
void	PmergeMe::not_valid(std::string str)
{
	if (!str.length())
		throw "Error empty argument\n";
	if (str[0] == '0' && str.size() != 1)
		throw "number cant start with 0\n";
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			throw "invalid character other than digits\n";
	}
	if (str.length() > 10)
		throw "number bigger than max int";
	long num = atol(str.c_str());
	if (num >=  2147483627)
		throw "number bigger or equal max int";
}
void    PmergeMe::store_data(char     **nums)
{
	for (int i = 0; nums[i]; i++)
	{
		this->not_valid(nums[i]);
		this->op1.push_back(atoi(nums[i]));
		this->op2.push_back(this->op1[this->op1.size() - 1]);	
	}
}

void    PmergeMe::print_res(char  **nums)
{
	std::cout << "Before: ";
	for (size_t i = 0; nums[i]; i++)
	{
		std::cout << nums[i] << " ";
	}
	std::cout << "\n";
	std::cout << "After: ";
	for (size_t i = 0; i < this->vector.size(); i++)
	{
		std::cout << this->vector[i] << " ";
	}
	std::cout << "\n";
	std::cout << "Time to process a range of " << this->vector.size() << " elements with std::vector : " << this->t1 <<  " microseconds"<<std::endl;
	std::cout << "Time to process a range of " << this->deque.size() << " elements with std::deque : " << this->t2 << " microseconds"<<std::endl;
}

void    PmergeMe::sort_vec()
{
	this->mergesort(this->op1);
}
void    PmergeMe::sort_deque()
{
	this->mergesort(this->op2);
}
void     PmergeMe::mergesort(std::vector<int> vec)
{
	if (vec.size() <= 2)
		{
			this->insert(vec);
			return ;
		}
	int divide;
	if (vec.size() % 3)
		divide  = 2;
	else
		divide = 3;
	this->mergesort(std::vector<int>(vec.begin(), vec.begin() + (vec.size() / divide)));
	this->mergesort(std::vector<int>( vec.begin() + (vec.size() / divide), vec.end()));
}
void    PmergeMe::insert(std::vector<int> vec)
{
	size_t size = 0;
	std::cout << "vec |" << vec.size() << "|"<< std::endl;
	if (vec.size() == 2 && vec[0] > vec[1])
		std::swap(vec[0], vec[1]);
	if (!this->vector.size())
	{
		this->vector.push_back(vec[size]);
		size++;
	}

	std::vector<int>::iterator en = this->vector.end();
	while (size != vec.size())
	{
			std::vector<int>::iterator st = this->vector.begin();
			while (st != en && vec[size] > *st)
				st++;
			this->vector.insert(st, vec[size]);
			size++;
	}
}
void     PmergeMe::mergesort(std::deque<int> deq)
{
	if (deq.size() <= 2)
		{
			this->insert(deq);
			return ;
		}
	int divide;
	if (deq.size() % 3)
		divide  = 2;
	else
		divide = 3;
	this->mergesort(std::deque<int>(deq.begin(), deq.begin() + (deq.size() / divide)));
	this->mergesort(std::deque<int>(deq.begin() + (deq.size() / divide), deq.end()));
}
void    PmergeMe::insert(std::deque<int> deq)
{
	size_t size = 0;	
	std::cout << "deque|" << deq.size() << "|"<< std::endl;
	if (deq.size() == 2 && deq[0] > deq[1])
		std::swap(deq[0], deq[1]);
	if (!this->deque.size())
	{
		this->deque.push_back(deq[size]);
		size++;
	}
	std::deque<int>::iterator en = this->deque.end();
	while (size != deq.size())
	{
			std::deque<int>::iterator st = this->deque.begin();
			while (st != en && deq[size] > *st)
				st++;
			this->deque.insert(st, deq[size]);
			size++;
	}
}