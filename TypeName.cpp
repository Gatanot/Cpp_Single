#include <iostream>
#include <queue>
#include <iterator>
using namespace std;
template <typename T>
class Stack
{
private:
    deque<T> elems;

public:
    void push(T value);
    T pop();

    size_t size();
    bool empty();

    typename deque<T>::iterator begin();
    typename deque<T>::iterator end();
};
template <typename T>
void Stack<T>::push(T value)
{
    elems.push_front(value);
}
template <typename T>
T Stack<T>::pop()
{
    T result = elems.front();
    elems.pop_front();
    return result;
}

template <typename T>
size_t Stack<T>::size()
{
    return elems.size();
}

template <typename T>
bool Stack<T>::empty()
{
    return elems.empty();
}
template <typename T>
typename deque<T>::iterator Stack<T>::begin()
{
    return elems.begin();
}
template <typename T>
typename deque<T>::iterator Stack<T>::end()
{
    return elems.end();
}
