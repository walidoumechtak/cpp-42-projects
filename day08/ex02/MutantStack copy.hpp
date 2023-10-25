#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <deque>
#include <iostream>
#include <string>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T>
{

private:
    Container container;

public:
    MutantStack() {}
    ~MutantStack() {}
    MutantStack(const MutantStack& obj)
    {
        *this = obj;
    }

    MutantStack &operator= (const MutantStack& obj)
    {
        if (this != &obj)
        {
            container = obj.container;
        }
        return (*this);
    }

    typedef typename Container::iterator iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    /*
        begin(): Returns an iterator pointing to the top element of the stack.
        end(): Returns an iterator pointing one position past the last element (typically, it will point to the bottom of the stack).
        rbegin(): Returns a reverse iterator pointing to the top element of the stack (the last element).
        rend(): Returns a reverse iterator pointing one position before the first element (typically, it will point above the top element).
        cbegin(): Returns a constant iterator pointing to the top element of the stack. Allows read-only access to the stack elements.
        cend(): Returns a constant iterator pointing one position past the last element.
        crbegin(): Returns a constant reverse iterator pointing to the top element of the stack. Allows read-only access to the stack elements in reverse.
        crend(): Returns a constant reverse iterator pointing one position before the first element.
    */

    iterator begin() { return container.begin(); }
    iterator end() { return container.end(); }
    reverse_iterator rbegin() {return container.rbegin(); }
    reverse_iterator rend() { return container.rend(); }
    const_iterator cbegin() { return container.cbegin(); }
    const_iterator cend() { return container.cend(); }
};


#endif