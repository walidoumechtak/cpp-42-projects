#include "ReplaceFile.hpp"

// ======== start setter function ==========
void    setFileName(std::string fn)
{
    fileName = fn;
}

void    setS1(std::string ss1)
{
    s1 = ss1;
}

void    setS2(std::string ss2)
{
    s2 = ss2;
}
// ======== end setter function ============

// ----- start getter function ----------
std::string ReplaceFile::get_filename()
{
    return (fileName);
}

std::string ReplaceFile::get_s1()
{
    return (s1);
}

std::string ReplaceFile::get_s2()
{
    return (s2);
}
// ----- end getter function ------------

ReplaceFile::ReplaceFile()
{
}

ReplaceFile::ReplaceFile(std::string fn, std::string ss1, std::string ss2): fileName(fn), s1(ss1), s2(ss2)
{
}

ReplaceFile::~ReplaceFile()
{
}