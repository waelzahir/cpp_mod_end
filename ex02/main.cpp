#include "PmergeMe.hpp"

int main(int ac, char   **av)
{
    if (ac < 3)
    {
        std::cout << "less than two numbers to compare\n";
        return 0;
    }
    PmergeMe    merge;
    try
    {
        merge.store_data(av + 1);
        merge.set_stamp();
        merge.sort_vec();
        merge.get_time(1);
        merge.set_stamp();
        merge.sort_deque();
        merge.get_time(2);
        merge.print_res(av + 1);
    }
    catch (const    char    *ex)
    {
        std::cerr << ex;
    }

}