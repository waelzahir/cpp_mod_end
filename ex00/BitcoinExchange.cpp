#include "BitcoinExchange.hpp"


BTCdb::BTCdb(){}
BTCdb::BTCdb(const BTCdb &rhs){(void)rhs;}
BTCdb &BTCdb::operator= (const BTCdb &rhs){(void)rhs;return *this;}
BTCdb::~BTCdb(){}

int BTCdb::check_csv(std::string &file)
{
    std::string ext = &file[file.length() - 4];
    if (ext == ".csv")
        return (0);
    return (1);
}

void    BTCdb::set_main_db(std::string file)
{
    std::ifstream csvfile;
    std::string     line;

    if (file.length() < 4 || this->check_csv(file))
        throw  std::runtime_error("database file is not csv\n");
    csvfile.open(file, std::ios::in);
    if (!csvfile.is_open())
        throw  std::runtime_error("coudn't open csv file\n");
    std::getline(csvfile, line);
    if (line != "date,exchange_rate")
        throw std::runtime_error("the database header is not configured properly\n");
    while (std::getline(csvfile, line))
    {
        if (line.length() < 12)
            throw std::runtime_error("string lenght dosn't match the exected input\n");
        
    }
    csvfile.close();
}
void    BTCdb::evaluate(std::string file)
{
    std::ifstream csvfile;
    std::string     line;

    csvfile.open(file, std::ios::in);
    if (!csvfile.is_open())
        throw  std::runtime_error("coudn't open csv file\n");
    std::getline(csvfile, line);
    if (line != "date | value")
        throw std::runtime_error("the input header is not configured properly\n");
    while (std::getline(csvfile, line))
    {
        
    }
    csvfile.close();
}
