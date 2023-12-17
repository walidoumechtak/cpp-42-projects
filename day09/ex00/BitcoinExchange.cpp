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

void    ltrim(std::string &source)
{
    int i;

    i = 0;
    while (std::isspace(source[i]))
        i++;
    source = source.substr(i);
}

void    rtrim(std::string &source)
{
    int i;

    i = source.length() - 1;
    while (i > 0)
    {
        if (isspace(source[i]))
            i--;
        else
            break;
    }
    source = source.substr(0, i + 1);
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

    if (value.find("-") != std::string::npos)
        return -1;
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

    // check the form of the date is correct or not.!
    size_t pos = date.find("-", 1);
    if (count_element(date, "-") != 3 || date.length() != 10)
    {
        std::cout << "Error: invalid date format " << date << std::endl;
        return (-1);
    }
    // extract each part of the date <year>, <month>, <day>.
    year = date.substr(0, pos);
    std::string temp = date.substr(pos + 1, date.length());
    pos = temp.find("-");
    month = temp.substr(0, pos);
    day = temp.substr(pos + 1, temp.length());

    // converte them to int.
    int day_int = strtod(day.data(), NULL);
    int month_int = strtod(month.data(), NULL);
    int year_int = strtod(year.data(), NULL);

    // check if the year is leap or not if yes add one day to the second month.
    if (month_int == 2 && year_int % 4 == 0)
        arr[1] = 29;

    // here just check for error.
    /**
    *   if month is biger than 12.
    *   if the entred day is bigger than the excepcted day.
    *   ..., and some more check in check_value() function.
    */
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

    // fill the map<string, string> with its value.
    fill_data_map();
    // export the first and the last day in the database.
    it = data.end();
    small_date = data.begin()->first;
    --it;
    big_date = it->first;
    
    // get the first line and check it. 
    getline(this->f_input, first_line);
    if (first_line.length() <= 0 || first_line != "date | value")
    {
        std::cerr << "Error: check the form of your input file!" << std::endl;
        return;
    }
    // start the proccessing of the input file.
    while (getline(this->f_input, line))
    {
        int cpt = count_element(line, " ");
        size_t  pos = line.find("|");

        if (line.length() == 0 || isOnlyWhiteSpaces(line))
            continue;
        // extract the date for the input line 
        date = line.substr(0, pos - 1);
        ltrim(date); // this function ignore the whitespaces from the left of the string.

        /**
         * check if | not found 
         * or there is more than one space before and after |
         * or the compenent of the line is different than 3
        */
        if (pos == std::string::npos || (line[pos - 2] == ' ' || line[pos + 2] == ' ') || cpt != 3)
            std::cerr << "Error: bad input => " << line << std::endl;
        else if (date >= big_date || date <= small_date) // check the boundry of the date. 
        {
            std::cerr << "Error: please enter a date between: [ " << small_date << ", " << big_date << " ]" << std::endl;
            continue;
        }
        else
        {
            std::string valFormInputString = (line.substr(pos + 2, line.length()));
            rtrim(valFormInputString);
            int date_result = check_date(date);
            int value_result = check_value(valFormInputString, "val");
            if (value_result == -1)
            {
                std::cerr << "Error: incorrect value: " << valFormInputString << std::endl;
                continue;
            }
            if (date_result == -1)
                continue;
            // searcch for the target date in the map.
            std::map<std::string, std::string>::iterator it = data.find(date);
            if (it == data.end())
            {
                // if not found insert it inside the map.
                data.insert(std::make_pair(date, "0"));
                it = data.find(date); // we just get our inserted date | value, good teeps.
                --it; // to get the nearest.
            }
            if (it != data.end())
            {
                double valFromData = strtod(it->second.c_str(), NULL); // get the targeted value from data map (database).
                double valFromInput = strtod((valFormInputString).c_str(), NULL); // get the value from the input file.
                //finaly print the result.
                std::cout << line.substr(0, pos - 1);
                std::cout << " => ";
                std::cout << valFromInput;
                std::cout << " = ";
                std::cout << valFromData * valFromInput << std::endl;
                data.erase(++it); // erase in case of the same date was found in the input file.
            }
        }
    }
}

void BitcoinExchange::run()
{
    openFiles();
    parseInput();
    closeFiles();
}