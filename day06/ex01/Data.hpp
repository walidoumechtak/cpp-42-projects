#ifndef DATA_HPP
#define DATA_HPP

class Data
{
private:
    int val;
public:
    Data( );
    Data(int in_val);
    ~Data();
    Data(const Data &obj);
    Data &operator= (const Data& source);

    void setData(int val);
    int getData(void) const;
};

#endif