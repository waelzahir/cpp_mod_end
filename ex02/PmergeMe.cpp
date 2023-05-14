#include "PmergeMe.hpp"


long	what_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000000) + (tv.tv_usec ));
}

template <typename T>
void	insertion_sort(T &data)
{
	if (data.size() < 2)
		return ;
	typename T::iterator start = data.begin();
	typename T::iterator current = start;
	typename T::iterator end = data.end();
	while (current  != end - 1)
	{
		current++;
		typename T::iterator iter = current - 1;
		int val = *current;
		while (iter >= start && *iter > val)
		{
			typename T::iterator temp = iter + 1;
			std::swap(*iter, *temp);
			iter--;
		}
	}
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
		throw "Error\n";
	if (str[0] == '0' && str.size() != 1)
		throw "Error\n";
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			throw "Error\n";
	}
	if (str.length() > 10)
		throw "Error\n";
	long num = atol(str.c_str());
	if (num >=  2147483627)
		throw "Error\n";
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
	std::cout << "After: ";
	for (size_t i = 0; i < this->deque.size(); i++)
	{
		std::cout << this->deque[i] << " ";
	}
	std::cout << "\n";
	std::cout << "Time to process a range of " << this->vector.size() << " elements with std::vector : " << this->t1 <<  " microseconds"<<std::endl;
	std::cout << "Time to process a range of " << this->deque.size() << " elements with std::deque : " << this->t2 << " microseconds"<<std::endl;
}

void    PmergeMe::sort_vec()
{
	if (std::is_sorted(this->op1.begin() , this->op1.end()))
		{
			this->vector.insert(this->vector.begin(), this->op1.begin(), this->op1.end());
			return ;
		}
	this->mergesort(this->op1);
}
void    PmergeMe::sort_deque()
{
	if (std::is_sorted(this->op2.begin() , this->op2.end()))
		{
			this->deque.insert(this->deque.begin(), this->op2.begin(), this->op2.end());
			return ;
		}
	this->mergesort(this->op2);
}
void     PmergeMe::mergesort(std::vector<int> vec)
{
	if (vec.size() <= 10)
		{
			this->insert(vec);
			return ;
		}
	this->mergesort(std::vector<int>(vec.begin(), vec.begin() + 10));
	this->mergesort(std::vector<int>( vec.begin() +  10, vec.end()));
}
void    PmergeMe::insert(std::vector<int> vec)
{
	insertion_sort(vec);
	if (!this->vector.size())
	{
		this->vector.insert(this->vector.begin(), vec.begin(), vec.end());
		return ;
	}
	int index = 0;
	std::vector<int>::iterator vstart = vec.begin();
	std::vector<int>::iterator vend = vec.end();
	for(; vstart != vend; vstart++)
	{
		for (; (this->vector.begin() + index) != this->vector.end() && *vstart  >= *(this->vector.begin() + index); index++);
		this->vector.insert(this->vector.begin() + index, *vstart);
	}
}

void     PmergeMe::mergesort(std::deque<int> deq)
{
	if (deq.size() <= 10)
		{
			this->insert(deq);
			return ;
		}
	this->mergesort(std::deque<int>(deq.begin(), deq.begin() + 10));
	this->mergesort(std::deque<int>(deq.begin()  + 10, deq.end()));
}

void    PmergeMe::insert(std::deque<int> deq)
{
	insertion_sort(deq);
	if (!this->deque.size())
	{
		this->deque.insert(this->deque.begin(), deq.begin(), deq.end());
		return ;
	}
	int index = 0;
	std::deque<int>::iterator start = deq.begin();
	std::deque<int>::iterator end = deq.end();
	for (; start != end; start++)
	{
		for (; this->deque.begin() + index != this->deque.end() && *start >= *(this->deque.begin() + index) ; index++);
		this->deque.insert(this->deque.begin() + index, *start);
	}
}