#include "BitcoinExchange.hpp"


BTCdb::BTCdb(){}
BTCdb::BTCdb(const BTCdb &rhs){(void)rhs;}
BTCdb &BTCdb::operator= (const BTCdb &rhs){(void)rhs;return *this;}
BTCdb::~BTCdb(){}
void    BTCdb::printmap()
{
}

int BTCdb::check_csv(std::string &file)
{
    std::string ext = &file[file.length() - 4];
    if (ext == ".csv")
        return (0);
    return (1);
}
void    BTCdb::check_date_format(std::string date, int line)
{
    int year;
    int month;
    int day;
    for (size_t    i = 0; i < date.length(); i++)
    {
        if (!isdigit(date[i]) && date[i] != '-')
            throw  std::runtime_error("wrong charachter in date\n");
        if (date[i] == '-' && !(i ==  4 || i == 7))
        {
            std::cout << "on line " << line << " ";
         throw  std::runtime_error("we expect the time to be 10 char in lenght, if you use one digit number please padd it with a zero\n\n");
        }  
    }
    year = atoi( date.substr(0 ,4).c_str());
    month = atoi(date.substr(5, 2).c_str());
    day = atoi(date.substr(8, 2).c_str());
    if (month > 12 || day > 31)
         throw  std::runtime_error("month cant be bigger than 12 and days cant be bigger than 31\n");
    if (month == 2 && day > 28 && (year %4))
        {
            std::cout << "year " << year << " is not a leap year day " << day << " is incorect\n";
            throw  std::runtime_error("");
        }
}
double    BTCdb::check_amount_format(std::string amount)
{
    double aunt;
    char    *end;
    int f;
    f = 0;
    for (size_t i = 0; i < amount.length(); i++)
    {
        if (!isdigit(amount[i]) && amount[i] != '.' )
            throw  std::runtime_error("amout should have only numbers and a point for floats\n");
        if (amount[i] == '.')
            f++;
        if (f > 1)
            throw  std::runtime_error("mltiple points are not allowed in values\n");

    }
    aunt = strtod(amount.c_str(), &end);
    return aunt;
}
int BTCdb::date_toNum(std::string date)
{
    date.erase(7, 1);
    date.erase(4, 1);
    return ( atoi(date.c_str()));
}

void    BTCdb::set_main_db(std::string file)
{
    std::ifstream csvfile;
    std::string     line;
    double   amount;
    if (file.length() < 4 || this->check_csv(file))
        throw  std::runtime_error("database file is not csv\n");
    csvfile.open(file.c_str(), std::ios::in);
    if (!csvfile.is_open())
        throw  std::runtime_error("coudn't open csv file\n");
    std::getline(csvfile, line);
    if (line != "date,exchange_rate")
        throw std::runtime_error("the database header is not configured properly\n");
    int i = 1;
    while (std::getline(csvfile, line))
    {
        i++;
        if (line.length() < 12)
            throw std::runtime_error("we expect the time to be 10 char in lenght, if you use one digit number please padd it with a zero\n");
        this->check_date_format(line.substr(0, 10), i);
        if (line[10] != ',')
            throw std::runtime_error("please use comma directly after the date \n");
        amount = this->check_amount_format(line.substr(11 , line.length() - 10));
        this->map.insert({this->date_toNum(line.substr(0, 10)), amount });
    }
    csvfile.close();
}
void    BTCdb::evaluate(std::string file)
{
    std::ifstream csvfile;
    std::string     line;

    csvfile.open(file.c_str(), std::ios::in);
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
