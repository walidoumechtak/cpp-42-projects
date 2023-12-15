#ifndef PMERGEME_HPP
#define PMERGEME_HPP

/*
    lower and upper bound that are disponible in c++ 98.
    template< class ForwardIt, class T >
    constexpr ForwardIt upper_bound( ForwardIt first, ForwardIt last, const T& value );

    template< class ForwardIt, class T, class Compare >
    constexpr ForwardIt upper_bound( ForwardIt first, ForwardIt last, const T& value, Compare comp );
*/

#include <iostream>
#include <exception>
#include <vector>

void    parseTheInput(char **av, int ac);

template <typename Container>
void    splitArray(Container &data, Container &small, Container &big)
{
    // take pair number from data, and compare them
    // the small one goes to small container
    // the big one goes to big container
    // 1 9 2 8 3 7 4 6 5
    for (int i = 0; i < (int)data.size(); i = i + 2)
    {
        if (i + 1 < (int)data.size() && data.at(i) > data.at(i + 1))
        {
            big.push_back(data.at(i));
            small.push_back(data.at(i + 1));
        }
        else if (i + 1 < (int)data.size() && data.at(i) < data.at(i + 1))
        {
            small.push_back(data.at(i));
            big.push_back(data.at(i + 1));
        }
    }
    if (data.size() % 2 != 0)
        big.push_back(data.at(data.size() - 1));
}

template <typename Container>
void print(Container big, Container small)
{
    for (int i = 0; i < (int)big.size(); i++)
        std::cout << big.at(i) << " ";
    std::cout << std::endl << std::endl;
    (void) small;
    // for (int i = 0; i < (int)small.size(); i++)
    //     std::cout << small.at(i);
    // std::cout << std::endl;
}

template <typename Container>
void    merge(Container &big, int s, int mid, int end)
{
    Container left;
    Container right;
    int left_size;
    int right_size;
    int k = s;

    // the size of subarrays or sub-container lets say.
    left_size = mid - s + 1;
    right_size = end - mid;

    // fill the sub-arrays that will get merged.
    for (int i = 0; i < left_size; i++)
        left.push_back(big.at(s + i));
    for (int i = 0; i < right_size; i++)
        right.push_back(big.at(mid + 1 + i));
    
    // the first element (from left of each array<container>) compare them and the smallest one pushed to the original container (big).
    int i = 0;
    int j = 0;

    // big.clear();
    // big.erase(big.begin() + s, big.end() - end);
    for (; i < (int)left.size() && j < (int)right.size();)
    {
        if (left.at(i) < right.at(j))
        {
            big[k] = left.at(i);
            // big.push_back(left.at(i));
            // left.erase(left.begin() + i);
            k++;
            i++;
        }
        else
        {
            big[k] = right.at(j);
            // big.push_back(right.at(j));
            // right.erase(right.begin() + j);
            k++;
            j++;
        }
    }
    for (; i < (int)left.size(); i++)
        big[k++] = left.at(i);
        // big.push_back(left.at(i));
    for (; j < (int)right.size(); j++)
        big[k++] = right.at(j);
        // big.push_back(right.at(i));
}



template <typename Container>
void    sortBig(Container &big, int s, int end)
{
    // devide to conquer.
    if (s >= end)
        return;
    int mid = s + (end - s) / 2;
    sortBig(big, s, mid); // take the left part.
    sortBig(big, mid + 1, end); // take the right part.
    merge(big, s, mid, end); // merge the sorted left and right container.
}

template <typename Container>
void insertion(Container &big, Container small)
{
    typename Container::iterator it;

    for (int i = 0; i < (int)small.size(); i++)
    {
        it = std::lower_bound(big.begin(), big.end(), small.at(i));
        if (it != big.end())
        {
            big.insert(it, small.at(i));
        }
    }
}

template <typename Container>
void    run(Container &data)
{
    Container small;
    Container big;

    splitArray(data, small, big);
    sortBig(big, 0, (int)big.size() - 1);
    insertion(big, small);
    print(big, small);
}

template <typename Container>
void    fillTheData(Container &data, char **av, int ac)
{
    int num;

    for (int i = 1; i < ac; i++)
    {
        num = strtod(av[i], NULL);
        data.push_back(num);
    }
}

#endif