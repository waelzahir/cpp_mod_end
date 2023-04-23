#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>
#include <cstdlib>


class RPN
{
    private:
        std::string expr;
        int i;
        int acumulator;
        std::stack<int> rpn;
    public:
    
    RPN();
    RPN(const RPN& rhs);
    ~RPN();
    void    parse_expretion(std::string line);
    char    cursor();
    void    skip_spaces();
    void    decide(std::string str);
    int     is_valid();
    std::string get_token();
    int    apply_operation(int op, int num1, int num2);
    int get_res();
};

int chars(char  c);
#endif