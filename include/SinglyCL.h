#pragma once

#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T>* next;
};

template <class T>
class SinglyCL
{
private:
    Node<T>* first;
    Node<T>* last;
    int iCount;

public:
    SinglyCL();
    ~SinglyCL();

    void Display();
    int Count();

    void InsertFirst(T iNo);
    void InsertLast(T iNo);
    void InsertAtPos(T iNo, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
SinglyCL<T>::SinglyCL()
{
    this->first = nullptr;
    this->last = nullptr;
    this->iCount = 0;
}

template <class T>
SinglyCL<T>::~SinglyCL()
{
    while(this->iCount > 0)
    {
        DeleteFirst();
    }
}

template <class T>
void SinglyCL<T>::Display()
{
    if(this->first == nullptr)
    {
        return;
    }

    Node<T>* temp = this->first;

    do
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;

    } while(temp != this->first);

    cout << "(Back to First)\n";
}

template <class T>
int SinglyCL<T>::Count()
{
    return this->iCount;
}

template <class T>
void SinglyCL<T>::InsertFirst(T iNo)
{
    Node<T>* newn = new Node<T>;

    newn->data = iNo;
    newn->next = nullptr;

    if(this->first == nullptr)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;
    }

    this->last->next = this->first;
    this->iCount++;
}

template <class T>
void SinglyCL<T>::InsertLast(T iNo)
{
    Node<T>* newn = new Node<T>;

    newn->data = iNo;
    newn->next = nullptr;

    if(this->first == nullptr)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }

    this->last->next = this->first;
    this->iCount++;
}

template <class T>
void SinglyCL<T>::InsertAtPos(T iNo, int iPos)
{
    if((iPos < 1) || (iPos > this->iCount + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == this->iCount + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        Node<T>* temp = this->first;
        Node<T>* newn = new Node<T>;

        newn->data = iNo;

        for(int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

template <class T>
void SinglyCL<T>::DeleteFirst()
{
    if(this->first == nullptr)
    {
        return;
    }

    if(this->first == this->last)
    {
        delete this->first;

        this->first = nullptr;
        this->last = nullptr;
    }
    else
    {
        Node<T>* temp = this->first;

        this->first = this->first->next;

        delete temp;

        this->last->next = this->first;
    }

    this->iCount--;
}

template <class T>
void SinglyCL<T>::DeleteLast()
{
    if(this->first == nullptr)
    {
        return;
    }

    if(this->first == this->last)
    {
        delete this->first;

        this->first = nullptr;
        this->last = nullptr;
    }
    else
    {
        Node<T>* temp = this->first;

        while(temp->next != this->last)
        {
            temp = temp->next;
        }

        delete this->last;

        this->last = temp;
        this->last->next = this->first;
    }

    this->iCount--;
}

template <class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > this->iCount))
    {
        cout << "Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == this->iCount)
    {
        DeleteLast();
    }
    else
    {
        Node<T>* temp = this->first;

        for(int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        Node<T>* target = temp->next;

        temp->next = target->next;

        delete target;

        this->iCount--;
    }
}