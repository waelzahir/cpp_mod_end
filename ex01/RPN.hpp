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
        std::stack<int> num;
        std::stack<char> op;
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
    void    print()
    {
        while (num.size())
            {
                std::cout << num.top() << std::endl;
                num.pop();
            }
        while (op.size())
        { 
            std::cout << op.top()<<std::endl;
            op.pop();
        }
    }
};

int chars(char  c);
#endif