#ifndef WHATEVER_HPP
#define WHATEVER_HPP


template <typename T>

void swap(T &v1, T &v2)
{
    T temp;

    temp = v1;
    v1 = v2;
    v2 = temp;
}


template <typename T>
T min(T v1, T v2)
{
    if (v1 < v2)
        return v1;
    else
        return v2;
    //return (v1 < v2) ? v1 : v2;
}


template <typename T>
T max(T v1, T v2)
{
    if (v1 > v2)
        return v1;
    else
        return v2;
    //return (v1 > v2) ? v1 : v2;
}

#endif