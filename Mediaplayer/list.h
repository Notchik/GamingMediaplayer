#ifndef list_H
#define list_H

#pragma once
#include <iostream>

using namespace std;

template <typename T>
class node
{
public:
    T data;
    node<T> *n;
    node<T> *p;
};

template <typename T>
class list
{
    node<T> *h;
    node<T> *f;
    node<T> *l;
    int size;
public:

    list();
    ~list();
    void push_back(T obj);
    void pop_front();
    T see(int i);

    class iterator
    {
        node<T> *h;
    public:
        iterator(){}
        iterator(node<T> *node);
        ~iterator(){}

        iterator begin();
        iterator end();
        iterator operator =(node<T> *node);
    };

    iterator begin()
    {
       return iterator(list<T>::f);
    }

    iterator end()
    {
        if(l = NULL) return l;
        return iterator(list<T>::l->n);
    }
};

template <typename T>
list<T>::list()
{
    h=NULL;
    f=NULL;
    l=NULL;
    size = 0;
}

template <typename T>
list<T>::~list()
{
    while(this->h)
        pop_front();
}

template <typename T>
void list<T>::push_back(T obj)
{
    node<T> *temp = new node<T>();
    if(!h)
    {
        temp->data = obj;
        h = f = l = temp;
        h->n = NULL;
        h->p = NULL;
    }
    else
    {
        temp->data = obj;
        l->p = temp;
        temp->n = l;
        temp->p = NULL;
        l = temp;
    }
    size++;
}

template <typename T>
void list<T>::pop_front()
{
    if (h)
    {
        h = f = f->n;
        node<T> *temp = f->p;
        delete temp;
        if (h == NULL)
        {
            l = NULL;
            f = NULL;
        }
    }
    else
        return;

    size--;
}

template <typename T>
T list<T>::see(int i)
{
    if (i > list::size || i < 0)
    {
        return NULL;
    }
    for (int j = 0; j < i; j++)
    {
        h = h->n;
    }
    return h->data;
}

template<typename T>
typename list<T>::iterator list<T>::iterator::operator =(node<T>* node)
{
    *this->h = node;
    return *this;
}

#endif // list_H
