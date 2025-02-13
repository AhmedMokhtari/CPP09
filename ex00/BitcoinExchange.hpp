#include <iostream>
#include <map>
class BitcoinExchange{
    private :
        std::map<std::string, float> db;
    public :
        BitcoinExchange();
        BitcoinExchange(const std::string &file, const std::string &db);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &cp);
        BitcoinExchange &operator=(const BitcoinExchange cp);
};