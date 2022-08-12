#pragma once
#include "Nod.h"
#include <algorithm>
#include <string>

template <class T>
class Collection
{
protected:
    unsigned size; 
    Nod<T>* first = nullptr;

public:
    Collection()
    {
        this->size = 0;
    }

    ~Collection()
    {
        this->delete_all();
    }

    int get_size()
    {
        return int(this->size);
    }

    void add_last(T data)
    {
        Nod <T>* tmp = new Nod<T>();
        tmp->data = data;
        if (this->first == nullptr)
        {
            this->first = tmp;
        }
        else
        {
            Nod<T>* tmp2 = this->first;
            while (tmp2->next)
            {
                tmp2 = tmp2->next;
            }
            tmp2->next = tmp;
            tmp->previous = tmp2;
        }
        this->size++;
    }

    void delete_from(int number)
    {
        if (number <= 0 || number > int(this->size))
        {
            throw string("Range error.");
            return;
        }
        Nod<T>* tmp = this->first;
        int i = 1;

        if (number == 1)
        {
            tmp->next->previous = nullptr;
            this->first = tmp->previous;
        }
        else
        {
            while (i < number)
            {
                tmp = tmp->next;
                i++;
            }
            if (tmp->previous != nullptr && tmp->next != nullptr)
            {
                tmp->previous->next = tmp->next;
                tmp->next->previous = tmp->previous;
            }
            else
            {
                tmp->previous->next = nullptr;
            }
        }
        this->size--;
        delete tmp;
    }

    void delete_all()
    {
        Nod<T>* tmp;
        while (this->first)
        {
            tmp = this->first;
            this->first = this->first->next;
            delete tmp;
            this->size--;
        }
    }

    void write()
    {
        cout << "-------------------------------------------------------" << endl;
        Nod<T>* tmp;
        tmp = this->first;
        for (int i = 1; i <= int(this->size); i++)
        {
            cout << i << ") " << tmp->data << endl;
            tmp = tmp->next;
        }
    }

    friend ostream& operator << (ostream& stream, Collection& collection)
    {
        Nod<T>* tmp = collection.first;
        stream << collection.size << endl;
        while (tmp)
        {
            stream << tmp->data << endl; // wywolanie operatora klasy np Komputer
            tmp = tmp->next;
        }
        return stream;
    }

    friend istream& operator >> (istream& stream, Collection& collection)
    {
        collection.delete_all();
        int size;
        stream >> size;
        int i = 0;
        while (i < size)
        {
            T middle;
            stream >> middle;
            collection.add_last(middle);
            i++;
        }
        return stream;
    }

};

