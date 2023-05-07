#include <iostream>
#include <string>

class ReplaceFile{

private:
    std::string fileName;
    std::string s1;
    std::string s2;

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
    void    open_file(std::string fileN);
}