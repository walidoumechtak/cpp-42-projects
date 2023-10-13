#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

void subjectTest()
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // INNER SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return;
        }
    }

    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    
    delete [] mirror;
}

class Complex{

    private:
        int n;
    public:
        Complex() : n(13) {}
        Complex(int _n) : n(_n) {}
        int getInt() const {return n;}
};

std::ostream & operator<< (std::ostream &o, const Complex& obj)
{
    o << obj.getInt();
    return o;
}

int main()
{
    // subjectTest();

    Array<Complex> items(5);
    Array<int> items2(5);
    for (int i = 0; i < 5; i++)
        std::cout << items[i] << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << items2[i] << std::endl;
    return 0;
}