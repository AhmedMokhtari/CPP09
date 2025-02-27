#pragma once
#include <iostream>
#include <stack>
#include <sstream>


class RPN{
    private :
        std::stack<int> st;
        bool is_all_num(std::string &val);
        void do_op(char op);
    public :
        RPN();
        RPN(const std::string &rp);
        ~RPN();
        RPN(const RPN &cp);
        RPN &operator=(const RPN cp);
};