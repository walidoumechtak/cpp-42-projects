#ifndef REPLACEFILE_HPP
#define REPLACEFILE_HPP

#include <iostream>
#include <string>
#include <fstream>

class ReplaceFile{

private:
    std::string fileName;
    std::string newFileName;
    std::string s1;
    std::string s2;
    std::fstream oFile;
    std::fstream nFile;


public:
    ReplaceFile();
    ReplaceFile(std::string fn, std::string ss1, std::string ss2);
    ~ReplaceFile();
    std::string get_filename();
    std::string get_s1();
    std::string get_s2();
    void    setFileName(std::string fn);
    void    setS1(std::string ss1);
    void    setS2(std::string ss2);
    void    open_file(std::string fileN, std::string flag);
    void    close_files();
    void    ft_replace();

};

#endif