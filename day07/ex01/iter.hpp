#ifndef ITER_HPP
#define ITER_HPP

template <typename T1, typename T2, typename T3>
void iter(T1 *arr, int len, T2 (*f)(T3 &ele))
{
    for (int i = 0; i < len; i++)
    {
        f(arr[i]);
    }
}


#endif