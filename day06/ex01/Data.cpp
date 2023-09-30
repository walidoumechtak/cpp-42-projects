#include "Data.hpp"

Data::Data() : val(0)
{
}

Data::Data(int in_val) : val(in_val)
{
}

Data::Data(const Data& obj)
{
    *this = obj;
}

Data &Data::operator= (const Data& source)
{
    if (this != &source)
    {
        this->val = source.val;
    }
    return *this;
}

Data::~Data()
{
}

void Data::setData(int val)
{
    this->val = val;
}

int Data::getData(void) const
{
    return (this->val);
}