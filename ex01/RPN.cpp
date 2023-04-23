#include "RPN.hpp"

RPN::RPN()
{
    i = 0;
}
RPN::RPN(const RPN &rhs)
{
    i = 0;
    *this = rhs;
}
RPN::~RPN()
{

}
char    RPN::cursor()
{
    return (expr[i]);
}
void    RPN::skip_spaces()
{
    while (expr[this->i] == ' ')
        this->i++;
}

std::string RPN::get_token()
{
    int start;
    int size;

    start = this->i;
    size = 0;
    if (chars(this->cursor()))
        return (this->i++, expr.substr(start, 1));
    while (isdigit(this->cursor()))
    {
        this->i++;
        size++;
    }
    return (expr.substr(start, size));
}

int     RPN::is_valid()
{
    if (!this->cursor())
        return (0);
    if (!chars(this->cursor()) && !isdigit(this->cursor()) && this->cursor() != ' ')
        return (1);
    return (0);
}

void    RPN::parse_expretion(std::string line)
{
    this->expr = line;
    while (this->cursor())
    {
        this->skip_spaces();
        this->decide(this->get_token());
        if (this->is_valid())
            throw std::runtime_error("invalid character\n");
    }
    this->print();
}
void    RPN::decide(std::string str)
{
    if (chars(str[0]))
        op.push(str[0]);
    if (isdigit(str[0]))
        num.push(atoi(str.c_str()));

}

int chars(char  c)
{
    if (c == '+' || c == '*'|| c == '-' || c == '/')
        return (1);
    return (0);
}

