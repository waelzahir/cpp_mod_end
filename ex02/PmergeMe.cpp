#include "PmergeMe.hpp"




PmergeMe::PmergeMe(){i = 0;}
PmergeMe::PmergeMe(const PmergeMe &rhs){*this = rhs;}
PmergeMe::~PmergeMe(){}
void    PmergeMe::parse(std::string str)
{
    this->str = str;
    int num;
    while (this->cursor())
    {
        this->skip_spaces();
        if (!this->cursor())
            break ;
        num = this->get_number();
        std::cout << num<<std::endl;
        vec.push_back(num);
        this->is_valid();
    }
}
void    PmergeMe::iter()
{
    this->i++;
}
void    PmergeMe::skip_spaces()
{
    while (str[i] == ' ')
        i++;
}

char    PmergeMe::cursor()
{
    return (str[i]);
}

int     PmergeMe::get_number()
{
    int start = i;
    int size = 0;
    while (isdigit(this->cursor()))
    {
        size++;
        this->iter();
    }
    return (atoi(str.substr(start, size).c_str()));
}
void    PmergeMe::is_valid()
{
    if (this->cursor() == 0)
        return ;
    if (this->cursor() == '-')
        throw std::runtime_error("negative number\n");
    if (this->cursor() != ' ' && !isdigit(this->cursor()))
        throw std::runtime_error("unknown character\n");

}
