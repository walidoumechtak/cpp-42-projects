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
        ~Span();
        void addNumber(int num);
        int shortestSpan();
        int longestSpan();

        // template <typename Iteri1, typename Iteri2>
        // void    oneFill(std::vector<int>& source, Iteri1 I1, Iteri2 I2);
        void oneFill(std::vector<int>& source, std::vector<int>::iterator beg, std::vector<int>::iterator end);
};

#endif