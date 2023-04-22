#ifndef BTCEXCHANGE 
# define BTCEXCHANGE 
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>


class   BTCdb
{
    private:
    
    public:

    BTCdb();
    BTCdb(const BTCdb& rhs);
    BTCdb &operator= (const BTCdb &rhs);
    ~BTCdb();
    int check_csv(std::string &file);
    void    set_main_db(std::string file);
    void    evaluate(std::string file);
    void    check_date_format(std::string date, int i);
    double    check_amount_format(std::string amount);
};
#endif