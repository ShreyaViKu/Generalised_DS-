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
class SinglyLL
{
private:
    Node<T>* first;
    int iCount;

public:
    SinglyLL();
    ~SinglyLL();

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
SinglyLL<T>::SinglyLL()
{
    this->first = nullptr;
    this->iCount = 0;
}

template <class T>
SinglyLL<T>::~SinglyLL()
{
    while(this->first != nullptr)
    {
        DeleteFirst();
    }
}

template <class T>
void SinglyLL<T>::Display()
{
    Node<T>* temp = this->first;

    while(temp != nullptr)
    {
        cout << "| " << temp->data << " | -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return this->iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T iNo)
{
    Node<T>* newn = new Node<T>;

    newn->data = iNo;
    newn->next = this->first;

    this->first = newn;
    this->iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T iNo)
{
    Node<T>* newn = new Node<T>;

    newn->data = iNo;
    newn->next = nullptr;

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

        temp->next = newn;
    }

    this->iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T iNo, int iPos)
{
    int i = 0;

    Node<T>* temp = nullptr;
    Node<T>* newn = nullptr;

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
        temp = this->first;

        newn = new Node<T>;

        newn->data = iNo;
        newn->next = nullptr;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    Node<T>* temp = nullptr;

    if(this->first == nullptr)
    {
        return;
    }

    temp = this->first;
    this->first = this->first->next;

    delete temp;

    this->iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    Node<T>* temp = nullptr;

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
        temp = this->first;

        while(temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }

    this->iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;

    Node<T>* temp = nullptr;
    Node<T>* target = nullptr;

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
        temp = this->first;

        for(i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;

        delete target;

        this->iCount--;
    }
}