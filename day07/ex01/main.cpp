#include "iter.hpp"
#include <iostream>
#include <string>

class Complex
{
    private:
        int n;
    public:
        Complex() : n(42) {}
        Complex(int _n) : n(_n) {}
        int getInt() const { return n; }
};

std::ostream &operator << (std::ostream &o, const Complex& obj)
{
    o << obj.getInt();
    return o;
}

template <typename T>
void print(T const& item)
{
    std::cout << item << std::endl;
}

int main(void)
{
    // int size = 5;
    // int arr[5] = {0};

    // iter(arr, size, TODO<void, int>);
    // for (int i = 0; i < size; i++)
    //     std::cout << arr[i] << std::endl;

    // ===================================================

    Complex obj[5];
    int arr[5] = {0,1,2,3,4};

    iter(obj, 5, print<Complex>);
    iter(arr, 5, print<int>);
}