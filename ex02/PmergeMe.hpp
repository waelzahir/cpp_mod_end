#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
class PmergeMe
{
    private:
        std::vector <int> vec;
        std::deque <int> deq;
         std::string str;
        int i;
    public:
    PmergeMe();
    PmergeMe(const PmergeMe &rhs);
    ~PmergeMe();
    void    parse(std::string str);
    int     get_number();
    void    iter();
    void    skip_spaces();
    char    cursor();
    void    is_valid();
};
#endif