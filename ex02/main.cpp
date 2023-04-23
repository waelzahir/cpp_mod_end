#include "PmergeMe.hpp"

int main(int ac, char   **av)
{
    PmergeMe al;
    if (ac == 1)
        return (0);
    try
    { 
        al.parse(av[1]);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() ;
    }
}