#ifndef RPN_HPP
#define RPN_HPP


class RPN
{
    private:
        std::stack<int> num;
        std::stack<char> op;
    public:
    RPN();
    RPN(const RPN& rhs);
    ~RPN();
    void    parse_expretion(std::string line);
};
#endif