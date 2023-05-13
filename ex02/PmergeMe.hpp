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

    private:
        long stamp;
        long t1;
        long t2;
        std::vector<int> op1;
        std::vector<int> sorted;
        std::deque<int>  op2;

};

long	what_time(void);
#endif