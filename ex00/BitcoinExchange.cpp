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

bool BitcoinExchange::isLeap(int year){
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    return false;
}

bool BitcoinExchange::is_valid_date(const std::string &val, int &year, int &month, int &day){
    if (val.size() != 10)
        return false;
    if (val[4] != '-' || val[7] != '-')
        return false;
    for (int i = 0; i < 10; i++)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(val[i]))
            return false;
    }
    std::stringstream d(val);
    char a;

    d >> year;
    d >> a;
    d >> month;
    d >> a;
    d >> day;
    int arr[] = {31 , 28 , 31 , 30 , 31 , 30 , 31 , 31, 30 , 31 , 30 , 31};
    if (day > 31 || month > 12 || day == 0 || month == 0)
        return false;
    if (isLeap(year))
        arr[1] = 29;
    if (day > arr[month - 1])
        return false;
    return true;
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
        int year, month, day;

        s >> date;
        s >> sep;
        s >> val;
        

        if (date.empty())
        {
            std::cerr << "Error :  empty filed \n";
            continue ;
        }
        if (!is_valid_date(date, year, month, day))
        {
            std::cout << "Error : bad input => "<< date <<  "\n";
            continue;
        }
        if (sep.empty() || val.empty())
        {
            std::cerr << "Error :  empty filed \n";
            continue ;
        }
        if (!is_valid_float(val, value))
        {
            std::cout << "Error : bad input => "<< val <<  "\n";
            continue;
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
        std::map<std::string, float>::iterator it = db.lower_bound(date);
        float res;
        if (it->first == date)
            res = it->second;
        else if (it != db.begin())
        {
            it--;
            res = it->second;
        }
        else{
            std::cout << "Date before First date in data \n";
            continue ;
        }
        std::cout <<  date << " => " << value << " = "  << res * value <<  std::endl;
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