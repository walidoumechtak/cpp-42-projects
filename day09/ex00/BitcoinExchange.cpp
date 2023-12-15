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
    this->f_input.open(this->file.c_str());
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

int check_value(std::string value, std::string controller)
{
    //A valid value must be either a float or a positive integer, between 0 and 1000.
    char *endptr;
    double val = strtod(value.data(), &endptr);

    if (endptr[0] != '\0' || endptr == value.data() || val < 0 || val > INT_MAX || (controller == "val" && val > 1000))
    {
        return (-1);
    }
    return (0);
}

/*
January - 31 days
February - 28 days in a common year and 29 days in leap years
March - 31 days
April - 30 days
May - 31 days
June - 30 days
July - 31 days
August - 31 days
September - 30 days
October - 31 days
November - 30 days
December - 31 days
*/

int check_date(std::string date)
{
    std::string year;
    std::string month;
    std::string day;
    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    size_t pos = date.find("-", 1);
    if (count_element(date, "-") != 3 || date.length() != 10)
    {
        std::cout << "Error: invalid date format " << date << std::endl;
        return (-1);
    }
    year = date.substr(0, pos);
    std::string temp = date.substr(pos + 1, date.length());
    pos = temp.find("-");
    month = temp.substr(0, pos);
    day = temp.substr(pos + 1, temp.length());
    int day_int = strtod(day.data(), NULL);
    int month_int = strtod(month.data(), NULL);
    int year_int = strtod(year.data(), NULL);
    if (month_int == 2 && year_int % 4 == 0)
        arr[1] = 29;
    if ((month_int) > 12 || check_value(year, "non") == -1 || check_value(month, "non") == -1 
        || check_value(day, "non") == -1 || arr[month_int - 1] < day_int)
    {
        std::cerr << "Error: invalid date format " << date << std::endl;
        return (-1);
    }
    return (0);
}

bool isOnlyWhiteSpaces(const std::string &str)
{
    for (int i = 0; i < (int)str.length(); i++)
    {
        if (!isspace(str[i]))
            return false;
    }
    return true;
}

void BitcoinExchange::parseInput()
{
    std::string date;
    std::string value;
    std::string line;
    std::string first_line;
    std::string small_date;
    std::string big_date;
    std::map<std::string, std::string>::iterator it;

    fill_data_map();
    it = data.end();
    small_date = data.begin()->first;
    --it;
    big_date = it->first;
    getline(this->f_input, first_line);
    if (first_line.length() <= 0 || first_line != "date | value")
    {
        std::cerr << "Error: check the form of your input file!" << std::endl;
        return;
    }
   
    while (getline(this->f_input, line))
    {
        int cpt = count_element(line, " ");
        size_t  pos = line.find("|");

        if (line == "date | value" || line.length() == 0 || isOnlyWhiteSpaces(line))
            continue;
        date = line.substr(0, pos - 1);
        /**
         * check if | not found 
         * or there is more than one space before and after |
         * or the compenent of the line is different from 3
        */
        if (pos == std::string::npos || (line[pos - 2] == ' ' || line[pos + 2] == ' ') || cpt != 3)
            std::cerr << "Error: bad input => " << line << std::endl;
        else if (date >= big_date || date <= small_date)
        {
            std::cerr << "Error: please enter a date between: [ " << small_date << ", " << big_date << " ]" << std::endl;
            continue;
        }
        else
        {
            int date_result = check_date(date);
            int value_result = check_value(line.substr(pos + 2, line.length()), "val");
            if (value_result == -1)
            {
                std::cerr << "Error: incorrect value: " << line.substr(pos + 2, line.length()) << std::endl;
                continue;
            }
            if (date_result == -1)
                continue;
            std::string dateInput = line.substr(0, pos - 1);
            std::map<std::string, std::string>::iterator it = data.find(dateInput);
            if (it == data.end())
            {
                data.insert(std::make_pair(dateInput, "0"));
                it = data.find(dateInput);
                --it;
            }
            if (it != data.end())
            {
                double valFromData = strtod(it->second.c_str(), NULL);
                double valFromInput = strtod(line.substr(pos + 2, line.length()).c_str(), NULL);

                std::cout << line.substr(0, pos - 1);
                std::cout << " => ";
                std::cout << valFromInput;
                std::cout << " = ";
                std::cout << valFromData * valFromInput << std::endl;
                data.erase(++it);
            }
        }
    }
}
// small and big date.
void BitcoinExchange::run()
{
    openFiles();
    parseInput();
    closeFiles();
}