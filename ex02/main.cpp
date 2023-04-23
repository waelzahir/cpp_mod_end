#include "PmergeMe.hpp"

int main(int ac, char   **av)
{
    PmergeMe al;
    double now;
    if (ac == 1)
        return (0);
    try
    { 
        al.parse(av[1]);
        al.print_vec("before")
        now = what_time();
        al.sort_vec();
        std::cout << what_time() - now<< " in us" <<std::endl;
        
        now = what_time();
        al.sort_deque();
        std::cout << what_time() - now<<  " in us" <<std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() ;
    }
}