#pragma once

#include <iostream>

template <class T>
struct Node
{
    T data;
    Node<T>* next;
};

template <class T>
class Stack
{
private:
    Node<T>* first;
    int iCount;

public:
    Stack();

    ~Stack();

    void push(T iNo);      // InsertFirst
    T pop();               // DeleteFirst
    T peep();              // Return first element
    void Display();
    int Count();
};

template <class T>
Stack<T>::Stack()
{
    first = nullptr;
    iCount = 0;
}

template <class T>
Stack<T>::~Stack()
{
    while(first != nullptr)
    {
        Node<T>* temp = first;
        first = first->next;
        delete temp;
    }

    iCount = 0;
}

template <class T>
void Stack<T>::push(T iNo)
{
    Node<T>* newn = new Node<T>;

    newn->data = iNo;
    newn->next = first;

    first = newn;

    iCount++;
}

template <class T>
T Stack<T>::pop()
{
    if(first == nullptr)
    {
        std::cout << "Stack is empty\n";
        return T();
    }

    Node<T>* temp = first;
    T iValue = first->data;

    first = first->next;

    delete temp;

    iCount--;

    return iValue;
}

template <class T>
T Stack<T>::peep()
{
    if(first == nullptr)
    {
        std::cout << "Stack is empty\n";
        return T();
    }

    return first->data;
}

template <class T>
void Stack<T>::Display()
{
    Node<T>* temp = first;

    while(temp != nullptr)
    {
        std::cout << "| " << temp->data << " |\n";
        temp = temp->next;
    }
}

template <class T>
int Stack<T>::Count()
{
    return iCount;
}