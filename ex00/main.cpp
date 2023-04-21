#include "BitcoinExchange.hpp"

int main(int ac, char   **av)
{
    BTCdb db;
    if (ac != 2)
    {
        std::cout << "Usage: "<< av[0]<<" [file]" << std::endl;
        return 0;
    }
    try
    {
        db.set_main_db("data.csv");
        db.evaluate(av[1]);
    }
    catch (std::exception & e)
    {
        std::cout << e.what();
    }
}