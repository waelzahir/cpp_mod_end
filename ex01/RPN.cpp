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

      this->i++;
      return( expr.substr(start, 1));
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
        if (!this->cursor())
            break ;
        this->decide(this->get_token());
        if (this->is_valid())
            throw "invalid character";
    }
}
void    RPN::decide(std::string str)
{
    int first = 0;
    int second = 0;
    if (isdigit(str[0]))
        {
            rpn.push(atoi(str.c_str()));
            return ;
        }
    if (rpn.size() < 2)
        throw "invalid rpn notation";
    if (chars(str[0]))
    {

        first = rpn.top();
        rpn.pop();
        second = rpn.top();
        rpn.pop();
        rpn.push(this->apply_operation(str[0], first, second));
        return ;
    }
    throw "invalid rpn notation";
}

int    RPN::apply_operation(int op, int num1, int num2)
{
    switch (op)
    { 
    case 45:
        return (num1 - num2);
    case 43:
        return (num1 + num2);
    case 42:
        return (num1 * num2);
    case 47:
        return ((num2) ? num1 / num2 : throw "Error");
    default:
        return (0);
    }
    return (0);
}
int RPN::get_res()
{
    if (rpn.size()  != 1)
        throw "invalid rpn notation";

    return (rpn.top());
}

int chars(char  c)
{
    if (c == '+' || c == '*'|| c == '-' || c == '/')
        return (1);
    return (0);
}

