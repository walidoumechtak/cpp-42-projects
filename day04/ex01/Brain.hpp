#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>
#include <string>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    Brain(const Brain& source);
    Brain &operator= (const Brain& source);
    void    setIdeas(std::string str, int lim);
    std::string *getIdeas();
    ~Brain();
};

#endif