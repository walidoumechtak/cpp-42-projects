#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE
#include <fstream>
#include <map>
#include <iostream>
#include <string>
#include <cstring>

class BitcoinExchange
{
    private:
        std::string file;
        std::ifstream   f_data;
        std::ifstream   f_input;
        std::map<std::string, std::string>    data;
        std::map<std::string, std::string>    input;

    public:
        BitcoinExchange();
        BitcoinExchange(std::string in_file);
        BitcoinExchange(const BitcoinExchange& source);
        BitcoinExchange &operator= (const BitcoinExchange& source);
        ~BitcoinExchange();
        void    openFiles();
        void    parseInput();
        void    closeFiles();
        void    fill_data_map();
        void    run();
};

#endif