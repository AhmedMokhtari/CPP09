#include <iostream>
#include <map>
#include <sstream>
class BitcoinExchange{
    private :
        std::map<std::string, float> db;
        bool isLeap(int year);
        void fill_map(const std::string &db);
        bool is_valid_float(const std::string &val, float &value);
        bool is_valid_date(const std::string &val, int &year, int &month, int &day);
    public :
        BitcoinExchange();
        BitcoinExchange(const std::string &db);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &cp);
        BitcoinExchange &operator=(const BitcoinExchange cp);
        void print_data(const std::string &file);
};