#include "RPN.hpp"

int main(int ac, char   **av)
{
    if (ac != 2)
        return (1);
    RPN rpn;
    try
    {
        rpn.parse_expretion(av[1]);
        std::cout << rpn.get_res() << std::endl;
    }
    catch (const char * e)
    {
        std::cerr << e << std::endl;
        return (0);
    }
}