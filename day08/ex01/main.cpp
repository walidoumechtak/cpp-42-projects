#include "Span.hpp"
#include <stack>

void subjectTest()
{
    Span  sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
}

void BigNumber()
{
    Span bigSpan = Span(20000);

    for (int i = 0; i < 20000; i++)
        bigSpan.addNumber(i + 1);
    std::cout <<  "Shortest Span: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << bigSpan.longestSpan() << std::endl;
}

void    oneCall()
{
    std::vector<int> base;
    for (int i = 1; i < 11; i++)
        base.push_back(i);

    Span oneCall;
    std::vector<int>::iterator beg = base.begin();
    std::vector<int>::iterator end = base.end();
    oneCall.oneFill(beg, end);
    std::cout <<  "Shortest Span: " << oneCall.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << oneCall.longestSpan() << std::endl;
}

int main()
{
    subjectTest();
    std::cout << "----------------------" << std::endl;
    BigNumber();
    std::cout << "----------------------" << std::endl;
    oneCall();
   
}