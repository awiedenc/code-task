#pragma once
#include <iostream>

using namespace std;

template <class T>
class Nod
{
public:
    T data;
    Nod* next;
    Nod* previous;
    Nod();
    Nod(T data);
    ~Nod();
};

template <class T>
Nod<T>::Nod()
{
    this->next = nullptr;
    this->previous = nullptr;
}

template <class T>
Nod<T>::Nod(T data)
{
    this->next = nullptr;
    this->previous = nullptr;
    this->data = data;
}

template <class T>
Nod<T>::~Nod()
{
    if (this->previous != nullptr && this->next != nullptr)
    {
        this->previous->next = this->next;
        this->next->previous = this->previous;
    }
}
