#pragma once

#include <iostream>

template <class T>
struct Node
{
    T data;
    Node<T>* next;
};

template <class T>
class Queue
{
private:
    Node<T>* first;
    int iCount;

public:
    Queue();

    ~Queue();

    void Enqueue(T No);
    T Dequeue();
    void Display();
    int Count();
};

template <class T>
Queue<T>::Queue()
{
    first = nullptr;
    iCount = 0;
}

template <class T>
Queue<T>::~Queue()
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
void Queue<T>::Enqueue(T No)
{
    Node<T>* newn = new Node<T>;

    newn->data = No;
    newn->next = nullptr;

    if(first == nullptr)
    {
        first = newn;
    }
    else
    {
        Node<T>* temp = first;

        while(temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    iCount++;
}

template <class T>
T Queue<T>::Dequeue()
{
    if(first == nullptr)
    {
        std::cout << "Queue is empty\n";
        return T();
    }

    Node<T>* temp = first;
    T Value = first->data;

    first = first->next;

    delete temp;

    iCount--;

    return Value;
}

template <class T>
void Queue<T>::Display()
{
    Node<T>* temp = first;

    while(temp != nullptr)
    {
        std::cout << "| " << temp->data << " |\n";
        temp = temp->next;
    }
}

template <class T>
int Queue<T>::Count()
{
    return iCount;
}