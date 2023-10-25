#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
    private:
        std::vector <int> span;
        std::vector <int> temp_span;
        unsigned int N;
        unsigned int cpt;
    public:
        Span();
        Span(unsigned int _N);
        Span(const Span& obj);
        Span& operator = (const Span& obj);
        ~Span();
        void addNumber(int num);
        int shortestSpan();
        int longestSpan();

        void oneFill(std::vector<int>::iterator beg, std::vector<int>::iterator end);
};

#endif