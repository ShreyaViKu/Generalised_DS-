# Generalised Data Structures Library (GDSL)

**Generalised Data Structures Library (GDSL)** is a reusable C++ library that provides generic implementations of commonly used data structures.

The library uses **C++ templates**, allowing the same implementation to work with different data types.

## Features

### Data Structures

* **Singly Linear Linked List**

  * Insert, Delete, Display, Count
* **Singly Circular Linked List**

  * Insert, Delete, Display, Count
* **Doubly Linear Linked List**

  * Insert, Delete, Display, Count
* **Doubly Circular Linked List**

  * Insert, Delete, Display, Count
* **Stack**

  * Push, Pop, Display, Count
* **Queue**

  * Enqueue, Dequeue, Display, Count

### Algorithms & Advanced Structures

Planned extensions include:

* Searching Algorithms
* Sorting Algorithms
* Binary Search Tree
* Additional data structures and algorithms

## Generic Programming

GDSL is implemented using C++ templates, making the data structures reusable with different data types.

```cpp
SinglyLL<int> intList;
SinglyLL<double> doubleList;

Stack<int> stack;
Queue<char> queue;
```

## Project Structure

```text
Generalised_DS-/
│
├── include/
│   ├── SinglyLL.h
│   ├── SinglyCLL.h
│   ├── DoublyLL.h
│   ├── DoublyCLL.h
│   ├── Stack.h
│   └── Queue.h
│
├── examples/
│   ├── SinglyLLExample.cpp
│   ├── SinglyCLLExample.cpp
│   ├── DoublyLLExample.cpp
│   ├── DoublyCLLExample.cpp
│   ├── StackExample.cpp
│   └── QueueExample.cpp
│
├── README.md
├── .gitignore
└── LICENSE
```

## Usage

Include the required header file and create an object of the desired data structure.

```cpp
#include "include/SinglyLL.h"

int main()
{
    SinglyLL<int> list;

    list.InsertFirst(10);
    list.InsertLast(20);
    list.Display();

    return 0;
}
```

## Technologies Used

* C++
* Object-Oriented Programming
* Generic Programming
* C++ Templates
* Dynamic Memory Allocation
* Data Structures & Algorithms
* Git & GitHub

## Future Enhancements

* Searching algorithms
* Sorting algorithms
* Binary Search Tree
* More advanced data structures
* Improved documentation and testing

## Author

**Shreya Kulkarni**

GitHub: https://github.com/ShreyaViKu
