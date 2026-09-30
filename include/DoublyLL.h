#pragma once

#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T>* next;
    Node<T>* prev;
};

template <class T>
class DoublyLL
{
private:
    Node<T>* first;
    int iCount;

public:
    DoublyLL();
    ~DoublyLL();

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
DoublyLL<T>::DoublyLL()
{
    this->first = nullptr;
    this->iCount = 0;
}

template <class T>
DoublyLL<T>::~DoublyLL()
{
    while(this->first != nullptr)
    {
        DeleteFirst();
    }
}

template <class T>
void DoublyLL<T>::Display()
{
    Node<T>* temp = this->first;

    while(temp != nullptr)
    {
        cout << "| " << temp->data << " | <=> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return this->iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T iNo)
{
    Node<T>* newn = new Node<T>;

    newn->data = iNo;
    newn->next = nullptr;
    newn->prev = nullptr;

    if(this->first == nullptr)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }

    this->iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T iNo)
{
    Node<T>* newn = new Node<T>;

    newn->data = iNo;
    newn->next = nullptr;
    newn->prev = nullptr;

    if(this->first == nullptr)
    {
        this->first = newn;
    }
    else
    {
        Node<T>* temp = this->first;

        while(temp->next != nullptr)
        {
            temp = temp->next;
        }

        newn->prev = temp;
        temp->next = newn;
    }

    this->iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T iNo, int iPos)
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
        newn->prev = temp;

        temp->next->prev = newn;
        temp->next = newn;

        this->iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(this->first == nullptr)
    {
        return;
    }

    Node<T>* temp = this->first;

    this->first = this->first->next;

    delete temp;

    if(this->first != nullptr)
    {
        this->first->prev = nullptr;
    }

    this->iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    if(this->first == nullptr)
    {
        return;
    }

    if(this->first->next == nullptr)
    {
        delete this->first;
        this->first = nullptr;
    }
    else
    {
        Node<T>* temp = this->first;

        while(temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->prev->next = nullptr;

        delete temp;
    }

    this->iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
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

        for(int i = 1; i < iPos; i++)
        {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;

        this->iCount--;
    }
}