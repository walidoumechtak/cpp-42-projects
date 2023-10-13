#ifndef _ARRAY_HPP_
#define _ARRAY_HPP_

template <typename T>

class Array
{
    private:
        T *arr;
        unsigned int sz;
    public:
        Array() : sz(0)
        {
            arr = new T[0];
        }

        Array(unsigned int n) : sz(n)
        {
            arr = new T[n];
            for (unsigned int i = 0; i < n; i++)
                arr[i] = T();
        }

        Array(const Array& obj)
        {
            *this = obj;
        }

        T &operator[] (int index)
        {
            if (index < 0 || (unsigned int)index >= sz)
                throw std::out_of_range("out of bounds");
            return arr[index];
        }

        Array& operator= (const Array& obj)
        {
            if (this != &obj)
            {
                this->sz = obj.sz;
                this->arr = new T[this->sz];
                for (unsigned int i = 0; i < sz; i++)
                {
                    this->arr[i] = obj.arr[i];
                }
            }
            return *this;
        }

        unsigned int size()
        {
            return sz;
        }

        ~Array()
        {
            delete[] arr;
        } 
};

#endif