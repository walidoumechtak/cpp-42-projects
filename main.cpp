#include <iostream>
#include <string>

using namespace std;

class Base
{
    int num;
};

class Der : public Base{
    int d_num;
};

int main()
{
    Der d;
    cout << "> " << sizeof(d) << endl;
    cout << "char> " << sizeof(char) << endl;
    cout << "double> " << sizeof(double) << endl;
    cout << "float> " << sizeof(float) << endl;
    cout << "int> " << sizeof(int) << endl;
    cout << "short> " << sizeof(short) << endl;
    cout << "long> " << sizeof(long) << endl;
    cout << "long long> " << sizeof(long long) << endl;
}