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
	for (size_t i = 0; i < this->sorted.size(); i++)
	{
		std::cout << this->sorted[i] << " ";
	}
	std::cout << "\n";
	std::cout << "After: ";
	for (size_t i = 0; i < this->op2.size(); i++)
	{
		std::cout << this->op1[i] << " ";
	}
	std::cout << "\n";
	std::cout << "Time to process a range of " << this->op1.size() << " elements with std::vector : " << this->t1 <<  " microseconds"<<std::endl;
	std::cout << "Time to process a range of " << this->op2.size() << " elements with std::deque : " << this->t2 << " microseconds"<<std::endl;
}

void    PmergeMe::sort_vec()
{
	this->mergesort(this->op1);
	for (size_t i = 0; i < sorted.size(); i++)
	{
		std::cout  << "|" << sorted[i] << "|\n";
	}
}
void    PmergeMe::sort_deque()
{
	int i = 0;
	while (i < 2000)
		i++;
}
void     PmergeMe::mergesort(std::vector<int> vec)
{
	if (vec.size() < 3)
		{
			this->insert(vec);
			return ;
		}
	this->mergesort(std::vector<int>(vec.begin(), vec.begin() + (vec.size() / 2)));
	this->mergesort(std::vector<int>( vec.begin() + (vec.size() / 2), vec.end()));
}
void    PmergeMe::insert(std::vector<int> vec)
{
	size_t size = 0;
	if (vec.size() == 2 && vec[0] > vec[1])
		std::swap(vec[0], vec[1]);
	while (size != vec.size())
	{
		if (this->sorted.size())
		{
			std::vector<int>::iterator st = this->sorted.begin();
			std::vector<int>::iterator en = this->sorted.end();
			while ( st != en && vec[size] > *st)
			{
				st++;
			}
			this->sorted.insert(st, vec[size]);
			size++;
		}
		else
			{
				this->sorted.push_back(vec[size]);
				size++;
			}
		std::cout<< vec.size() << std::endl;
	}
	
}