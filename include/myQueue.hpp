#pragma once

#include <exception>

template <typename T>
struct Element
{
    T value;
    Element<T>* next;
    Element( T value_, Element<T>* next_): value(value_), next(next_){}
};

template <typename T>
class MyQueue
{
private:
    Element<T>* end = nullptr;
    Element<T>* begin = end;
    unsigned counter {0};
public:
    MyQueue() = default;
    bool isEmpty();
    unsigned count();
    void push_back(T element);
    T pop_front();
};

template <typename T>
bool MyQueue<T>::isEmpty()
{
    return begin == end;
}

template <typename T>
unsigned MyQueue<T>::count()
{
    return counter;
}

template <typename T>
void MyQueue<T>::push_back(T element)
{
    if(isEmpty())
    {
        auto el = new Element<T>(element, end);
        begin = el;
        counter++; 
    }
    else
    {
        auto el = new Element<T>(element, end);
        begin->next = el;
        counter++; 
    }           
}

template <typename T>
T MyQueue<T>::pop_front()
{
    if(isEmpty())
    {
        throw std::out_of_range("Queue is epmpty! Cant pop element!");
    }
    else
    {
        T returnedValue = begin->value;
        Element<T>* nextEl = begin->next;
        delete begin;
        begin= nextEl;
        counter--;
        return returnedValue;  
    } 
}