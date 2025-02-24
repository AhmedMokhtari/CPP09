#include "BitcoinExchange.hpp"
#include <fstream>
#include <cstdlib>
#include <string>

BitcoinExchange::BitcoinExchange(){

}

void BitcoinExchange::fill_map(const std::string &db){
    std::fstream data(db.c_str());
    if (!data.is_open())
    {
        std::cerr << "Error: could not open file.\n";
        exit(0);
    }
    std::string line;
    // int i =0;
    while (std::getline(data, line))
    {
        std::string tmp = line.substr(11);
        std::string tmp1 = line.substr(0, 10);
        this->db.insert(std::pair<std::string, float>(tmp1, atof(tmp.c_str()) ) );
        // std::cout << tmp1  << " " << tmp << std::endl;
        // if (++i == 1000)
        //     break;

    }
    // for (std::map<std::string, float>::iterator it = this->db.begin(); it != this->db.end(); it++)
    // {
    //     std::cout << it->first << " " << it->second << "\n";
    // }
    // std::cout << std::endl;
}

BitcoinExchange::BitcoinExchange(const std::string &db){
    // std::fstream input_file(file.c_str());
    fill_map(db);
}

bool BitcoinExchange::is_valid_float(const std::string &val, float &value){
    char *end;

    value = strtof(val.c_str() , &end);
    return *end == 0;
}
void BitcoinExchange::print_data(const std::string &file){
    std::fstream f(file.c_str());
    if (!f.is_open())
    {
        std::cerr << "Error Opening file \n";
        return ;
    }
    std::string line;
    int i = 0;
    while (getline(f,line))
    {
        if (!i++)
            continue ;
        std::stringstream s(line);
        std::string date;
        std::string sep;
        std::string val;
        float value;

        s >> date;
        s >> sep;
        s >> val;
        
        if (date.empty() || sep.empty() || val.empty())
        {
            std::cerr << "Error :  empty filed \n";
            continue ;
        }
        if (value > 1000)
        {
            std::cerr << "Error :  Too Large Number \n";
            continue ;
        }
        if (value < 0)
        {
            std::cerr << "Error :  not a positive number.\n";
            continue ;
        }
        if (!is_valid_float(val, value))
        {
            std::cout << "Error : bad input => "<< val <<  "\n";
            continue;
        }
        
        std::stringstream d(date);


        int y,m, da;
        char a;

        d >> y;
        d >> a;
        d >> m;
        d >> a;
        d >> da;
        std::cout << "year is " << y << std::endl;
        std::cout << "char  is " << a << std::endl;
        std::cout << "month  is " << m << std::endl;
        std::cout << "day  is " << da << std::endl;
        std::cout << "date : "  << date << " value : " << value << std::endl;
    }

}
BitcoinExchange::~BitcoinExchange(){

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cp){
    (void )cp;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange cp){
    (void )cp;
    return *this;
}