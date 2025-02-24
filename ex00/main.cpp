#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    BitcoinExchange a("data.csv");
    a.print_data("input.txt");
    return 0;
}