#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(std::string in_file) : file(in_file) {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & source)
{
    *this = source;
}

BitcoinExchange &BitcoinExchange::operator= (const BitcoinExchange& source)
{
    if (this != &source)
    {
        this->file = source.file;
        this->data = source.data;
        this->input = source.input;
    }
    return *this;
}

void    BitcoinExchange::openFiles()
{
    this->f_data.open("data.csv");
    if (!f_data.is_open())
    {
        std::cerr << "Error: file was not opened!" << std::endl;
        exit(1);
    }
    this->f_input.open(this->file);
    if (!this->f_input.is_open())
    {
        std::cerr << "Error: file was not opened!" << std::endl;
        exit(1);
    }
}

void    BitcoinExchange::closeFiles()
{
    this->f_input.close();
    this->f_data.close();
}

void    BitcoinExchange::fill_data_map()
{
    std::string line;
    std::string date;
    std::string value;
    // 2023-12-12,5
    while (getline(this->f_data, line))
    {
        if (line == "date,exchange_rate")
            continue;
        else
        {
            size_t  pos = line.find(",");
            date = line.substr(0, pos);
            value = line.substr(pos + 1, line.length());
            this->data.insert(std::pair<std::string ,std::string> (date, value));
        }
    }
    // std::map<std::string, std::string>::iterator it = this->data.begin();
    // for (;it != this->data.end(); ++it)
    // {
    //     std::cout << it->first << " : " << it->second << std::endl;
    // }
}

int count_element(std::string str, std::string target)
{
    int cpt = 0;
    char *ptr;
    const char *line;

    line = str.data();
    ptr = strtok((char *)line, target.data());
    cpt++;
    while (strtok(NULL, target.data()))
    {
        cpt++;
    }
    return (cpt);
}

int check_value(std::string value)
{
    //A valid value must be either a float or a positive integer, between 0 and 1000.
    char *endptr;
    double val = strtod(value.data(), &endptr);

    if (endptr[0] != '\0' || endptr == value.data() || val < 0 || val > INT_MAX)
    {
        //std::cerr << "Error: incorrect value: " << value << std::endl;
        return (-1);
    }
    return (0);
}

int check_date(std::string date)
{
    std::string year;
    std::string month;
    std::string day;

    size_t pos = date.find("-", 1);
    if (count_element(date, "-") != 3)
    {
        std::cout << "Error: invalid date format " << date << std::endl;
        return (-1);
    }
    year = date.substr(0, pos);
    std::string temp = date.substr(pos + 1, date.length());
    pos = temp.find("-");
    month = temp.substr(0, pos);
    day = temp.substr(pos + 1, temp.length());
    if (check_value(year) == -1 || check_value(month) == -1 || check_value(day) == -1)
    {
        std::cerr << "Erro: invalid date format " << date << std::endl;
        return (-1);
    }
    return (0);
}



void BitcoinExchange::parseInput()
{
    std::string date;
    std::string value;
    std::string line;

    fill_data_map();
    while (getline(this->f_input, line))
    {
        int cpt = count_element(line, " ");
        size_t  pos = line.find("|");

        if (line == "date | value")
            continue;
        /**
         * check if | not found 
         * or there is more than one space before and after |
         * or the compenent of the line is different from 3
        */
        if (pos == std::string::npos || (line[pos - 2] == ' ' || line[pos + 2] == ' ') || cpt != 3)
            std::cerr << "Error: bad input => " << line << std::endl;
        else
        {
            int data_result = check_date(line.substr(0, pos - 1));
            int value_result = check_value(line.substr(pos + 2, line.length()));
            if (value_result == -1)
            {
                std::cerr << "Error: incorrect value: " << line.substr(pos + 2, line.length()) << std::endl;
                continue;
            }
            if (data_result == -1)
                continue; // exit (1);
            
        }
    }
}

void BitcoinExchange::run()
{
    openFiles();
    parseInput();
    closeFiles();
}