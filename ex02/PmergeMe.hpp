#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <sys/time.h>


class PmergeMe
{

    public:
        PmergeMe();
        PmergeMe(const  PmergeMe &rhs);
        PmergeMe &operator = (const  PmergeMe &rhs);
        void    set_stamp(void);
        void    get_time(int i);
        void    store_data(char     **nums);
        void    not_valid(std::string str);
        void    sort_vec();
        void    sort_deque();
        void    print_res(char  **nums);
        void    mergesort(std::vector<int> vec);
        void    insert(std::vector<int> vec);
        void    mergesort(std::deque<int> vec);
        void    insert(std::deque<int> vec);
    
    private:
        std::clock_t stamp;
        std::clock_t t1;
        std::clock_t t2;
        std::vector<int> op1;
        std::vector<int> vector;
        std::deque<int>  op2;
        std::deque<int>  deque;

};

long	what_time(void);
#endif