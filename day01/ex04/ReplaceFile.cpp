#include "ReplaceFile.hpp"

// ======== start ft_reaplce ================

void    replace_s1_by_s2(std::string str, std::string s1, std::string s2, std::fstream &nFile)
{
    int pos;

    while ((pos = str.find(s1)) != -1)
    {
        str.erase(pos, s1.length());
        str.insert(pos, s2);
        pos += s2.length();
    }
    nFile << str << std::endl;
}

void    ReplaceFile::ft_replace()
{
    std::string line;
    int sizeLine;

    sizeLine = line.length();
    open_file(fileName, "in");
    open_file(newFileName, "app");

    while (oFile.good())
    {
        getline(oFile, line);
        replace_s1_by_s2(line, s1, s2, nFile);
    }
}

// ======== end of ft_replace ================

void    ReplaceFile::open_file(std::string fileN, std::string flag)
{
    if (flag == "app")
    {
        nFile.open(fileN, std::ios::out | std::ios::app);
        if (!nFile.is_open())
        {
            std::cerr << "Error: the file no exist or there is a probleme while openinig the file" << std::endl;
            exit(0);
        }

    }
    else if (flag == "in")
    {
        oFile.open(fileN, std::ios::in);
        if (!oFile.is_open())
        {
            std::cerr << "Error: the file no exist or there is a probleme while openinig the file" << std::endl;
            exit(0);
        }
    }
}

void    ReplaceFile::close_files()
{
    oFile.close();
    nFile.close();
}

// ******* construcors and destructor *******
ReplaceFile::ReplaceFile()
{
    
}

ReplaceFile::ReplaceFile(std::string fn, std::string ss1, std::string ss2): fileName(fn), s1(ss1), s2(ss2)
{
    newFileName = fileName + ".replace";
}

ReplaceFile::~ReplaceFile()
{
}
// ******* construcors and destructor *******