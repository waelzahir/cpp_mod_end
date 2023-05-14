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
void    BTCdb::check_date_format(std::string date, int line)
{
    int year;
    int month;
    int day;
    for (size_t    i = 0; i < date.length(); i++)
    {
        if (!isdigit(date[i]) && date[i] != '-')
            throw  "wrong charachter in date\n";
        if (date[i] == '-' && !(i ==  4 || i == 7))
        {
            std::cout << "on line " << line << " ";
         throw  "we expect the time to be 10 char in lenght, if you use one digit number please padd it with a zero\n\n";
        }  
    }
    year = atoi( date.substr(0 ,4).c_str());
    month = atoi(date.substr(5, 2).c_str());
    day = atoi(date.substr(8, 2).c_str());
    if (month > 12 || day > 31 || day == 0 || month == 0)
         throw  "month cant be bigger than 12 and days cant be bigger than 31\n";
    if (month == 2 && day > 28 && (year %4))
        {
            std::cout << "year " << year << " is not a leap year day " << day << " is incorect\n";
            throw "";
        }
}
double    BTCdb::check_amount_format(std::string amount)
{
    double aunt;
    int f;
    f = 0;
    for (size_t i = 0; i < amount.length(); i++)
    {
        if (!isdigit(amount[i]) && amount[i] != '.' )
            throw  "amout should have only numbers and a point for floats, spaces aren't accepted\n";
        if (amount[i] == '.')
            f++;
        if (f > 1)
            throw  "mltiple points are not allowed in values\n";

    }
    aunt = atof(amount.c_str());
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
    csvfile.open(file.c_str(), std::ios::in);
    if (!csvfile.is_open())
        throw  "coudn't open csv file\n";
    std::getline(csvfile, line);
    if (line != "date,exchange_rate")
        throw "the database header is not configured properly\n";
    int i = 1;
    while (std::getline(csvfile, line))
    {
        i++;
        if (line.length() < 12)
            throw "we expect the time to be 10 char in lenght, if you use one digit number please padd it with a zero\n";
        this->check_date_format(line.substr(0, 10), i);
        if (line[10] != ',')
            throw "expexted comma after the date\n";
        amount = this->check_amount_format(line.substr(11 , line.length() - 10));
        this->map.insert(std::pair<std::string, double>(line.substr(0, 10), amount ));
    }
    csvfile.close();
}
int BTCdb::check_exchange_date(std::string date)
{
    int year;
    int month;
    int day;
    for (size_t    i = 0; i < date.length(); i++)
    {
        if (!isdigit(date[i]) && date[i] != '-')
            return std::cout << "Error: bad input => " << date << std::endl, 1;
        if (date[i] == '-' && !(i ==  4 || i == 7))
        {
            return std::cout << "Error: bad input => " << date << std::endl, 1;
        }  
    }
    year = atoi( date.substr(0 ,4).c_str());
    month = atoi(date.substr(5, 2).c_str());
    day = atoi(date.substr(8, 2).c_str());
    if (month > 12 || day > 31 || day == 0 || month == 0)
         return std::cout << "Error: bad input => " << date << std::endl, 1;
    if (month == 2 && day > 28 && (year %4))
        {
            std::cout << "year " << year << " is not a leap year day " << day << " is incorect\n";
            return (1);
        }
    return (0);
}
void    BTCdb::evaluate(std::string file)
{
    std::ifstream csvfile;
    std::string     line;

    csvfile.open(file.c_str(), std::ios::in);
    if (!csvfile.is_open())
        throw  "coudn't open csv file\n";
    std::getline(csvfile, line);
    if (line != "date | value")
        throw "the input header is not configured properly\n";
    while (std::getline(csvfile, line))
    {
        if (!this->check_exchange_date(line.substr(0, 10)))
        {
            this->check_amount_to_calc(line.substr(10, line.length() - 10), line.substr(0, 10));
        }
    }
    csvfile.close();
}

int BTCdb::check_amount_to_calc(std::string str, std::string date)
{
    
    while (str[0] == ' ')
        str.erase(0, 1);
    if (str[0] ==  '|')
        str.erase(0, 1);
    else
        return std::cout << "please separate the amount and date with a pipe\n", 1;
    while (str[0] == ' ')
        str.erase(0, 1);
     while ( (str.length() - 1) && str[str.length() - 1] == ' ')
        str.erase(str.length() - 1, 1);
    if (!str.length())
                return std::cout << "the argument needs an amount\n", 1;
    if (str[0] == '-')
        return std::cout << "Error: not a positive number.\n", 1;
    int i = 0;
    int p = 0;
    while (str[i])
    {
        if (!isdigit(str[i]) && str[i] != '.')
            return std::cout << "config error\n", 1;
        if (str[i] =='.')
            p++;
        i++;    
    }
    if (p > 1)
        return std::cout << "you cant have more than a point in a value\n", 1;
       double aunt = atof(str.c_str());
    if (aunt > 1000)
        return std::cout << "Error: too large a number.\n", 1;
    
    try
    {
        if ((map.lower_bound(date))->first != date)
           {
            map.at((*(--map.lower_bound(date))).first);
            std::cout << date << " => "<< str << " => " << (--map.lower_bound(date))->second * aunt << std::endl;
           }
           else
                std::cout << date << " => "<< str << " => " << (map.lower_bound(date))->second * aunt << std::endl;


    }
    catch(...)
    {
        std::cerr << "Error" << '\n';
    }
    
    return (0);
}