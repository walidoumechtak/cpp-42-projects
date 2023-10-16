#include "Span.hpp"

Span::Span() : cpt(0)
{
}

Span::Span(unsigned int _N) : N(_N), cpt(0)
{
}

Span::~Span()
{
}

void    Span::addNumber(int num)
{
    if (cpt < N)
    {
        span.push_back(num);
        temp_span.push_back(num);
    }
    else
        throw std::out_of_range("the span is full");
}

int Span::shortestSpan()
{
    std::vector <int> dist;

    int len = temp_span.size();
    if (len == 1 || len == 0)
        throw std::exception();
    sort(temp_span.begin(), temp_span.end());
    for (int i = 0; i < (int)temp_span.size() - 1; i++)
        dist.push_back(temp_span[i + 1] - temp_span[i]);
    sort(dist.begin(), dist.end());
    return (dist[0]);
}

int Span::longestSpan()
{
    int len = temp_span.size();
    if (len == 1 || len == 0)
        throw std::exception();
    sort(temp_span.begin(), temp_span.end());
    return (temp_span[temp_span.size() - 1] - temp_span[0]);
}

// template <typename Iteri1, typename Iteri2>
// void    Span::oneFill(std::vector<int>& source, Iteri1 I1, Iteri2 I2)
// {
//     this->span.insert(source, I1, I2);
// }

void Span::oneFill(std::vector<int>& source, std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
    (void)source;
    this->span.insert(span.begin(), beg, end);
    this->temp_span.insert(temp_span.begin(), beg, end);
    // std::cout << span.size() << std::endl;

    // for (int i = 0; i < (int)span.size(); i++)
    //     std::cout << span[i] << std::endl;
}