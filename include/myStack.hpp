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
class MyStack
{
private:
    Element<T>* top_ = nullptr;
    unsigned counter {0};
public:
    MyStack() = default;
    bool isEmpty();
    unsigned count();
    void push(T element);
    T pop();
    T top();
};

template <typename T>
bool MyStack<T>::isEmpty()
{
    return top_ == nullptr;
}

template <typename T>
unsigned MyStack<T>::count()
{
    return counter;
}

template <typename T>
void MyStack<T>::push(T element)
{
    auto el = new Element<T>(element, top_);
    top_ = el;
    counter++; 
}

template <typename T>
T MyStack<T>::pop()
{
    if(isEmpty())
    {
        throw std::out_of_range("Stack is epmpty! Cant pop element!");
    }
    else
    {
        T returnedValue = top_->value;
        Element<T>* nextEl = top_->next;
        delete top_;
        top_ = nextEl;
        counter--;
        return returnedValue;  
    } 
}

template <typename T>
T MyStack<T>::top()
{
    if(isEmpty())
    {
        throw std::out_of_range("Stack is epmpty! Cant take element!");
    }
    return top_->value;  
}