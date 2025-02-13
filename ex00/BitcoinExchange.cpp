#include "BitcoinExchange.hpp"
#include <fstream>
#include <cstdlib>
#include <string>

BitcoinExchange::BitcoinExchange(){

}
BitcoinExchange::BitcoinExchange(const std::string &file, const std::string &db){
    std::fstream input_file(file.c_str());
    std::fstream data(db.c_str());
    if (!data.is_open() || !input_file.is_open())
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