#include "RPN.hpp"
#include <fstream>
#include <cstdlib>
#include <string>

RPN::RPN(){

}

bool RPN::is_all_num(std::string &val){
    std::string t;
    if (val[0] == '-')
        t = val.substr(1, val.length() - 1);
    return t.find_first_not_of("0123456789") == std::string::npos;
}

void RPN::do_op(char op){
    if (st.size() < 2)
    {
        std::cerr << "Error \n";
        exit(0);
    }
    int val1 = st.top();
    st.pop();
    int val2 = st.top();
    st.pop();
    int res;
    if (op == '+')
        res = val2 + val1;
    else if (op == '-')
        res = val2 - val1;
    else if (op == '*')
        res = val2 * val1;
    else if (op == '/')
        res = val2 / val1;
    st.push(res);
}

RPN::RPN(const std::string &rp){
    std::stringstream a(rp);

    std::string tmp;

    while (a >> tmp)
    {
        if (!tmp.compare("+") || !tmp.compare("-") || !tmp.compare("*") || !tmp.compare("/"))
        {
            do_op(tmp[0]);
            continue;
        }
        if (!is_all_num(tmp))
        {
            std::cerr << "Error \n";
            exit(0);
        }
        st.push(atoi(tmp.c_str()));
    }

    if (st.size() != 1)
    {
        std::cerr << "Error \n";
        exit(0);
    }
    std::cout << st.top() << std::endl;
}

RPN::~RPN(){

}

RPN::RPN(const RPN &cp){
    (void )cp;
}

RPN & RPN::operator=(const RPN cp){
    (void )cp;
    return *this;
}