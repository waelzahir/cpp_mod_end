#ifndef BTCEXCHANGE 
# define BTCEXCHANGE 
#include <iostream>
#include <fstream>
#include <string.h>



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
};
#endif