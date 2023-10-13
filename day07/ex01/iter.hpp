#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>

template <typename T1, typename Func, typename T3>
void iter(T1 *arr, int len, Func (*f)(T3 &ele))
{
    for (int i = 0; i < len; i++)
    {
        f(arr[i]);
    }
}

template <typename RET, typename T1>
RET TODO(T1 &t)
{
    t++;
}

#endif