#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <list>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack() {}
        ~MutantStack() {}
        MutantStack(const MutantStack& obj) { *this = obj; }
        MutantStack &operator= (const MutantStack& obj)
        {
            if (this != &obj)
                std::stack<T, Container>::operator=(obj);
            return (*this);
        }

        //typedef typename std::deque<T>::iterator iterator;
        // typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename Container::iterator iterator;
        
        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
        
};


#endif