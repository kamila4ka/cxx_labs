#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T> class Iterator;

template <typename T> class List
{

    List *head;
    int count;

public:

    List *next;
    T value;

    int getCount() const
    {
        return count;
    }

    List(): head(NULL), count(0){}
    ~List()
    {
        for (int i=count; i>0; --i)
            del(i);
    }

    List(List const &a): head(a.head), count(a.count) {}

    List(T data)
    {
        append(data);
    }

    List* begin() const
    {        
        return head;
    }

    List* end() const
    {
        Iterator<T> a(head);
        while (a.getCur()->next)
        {
            ++a;
        }

        return a.getCur();
    }

    void append(T data)
    {
        List *to_add = new List;
        to_add->next = NULL;
        to_add->value = data;

        if(head == NULL)
            head = to_add;
        else
        {
            List *current=new List;

            current=this->end();
            current->next = to_add;
        }
        count++;
    }

    void addbegin(T data)
    {
        List *to_add = new List;
        to_add->value = data;
        if(head == NULL)
            {
                to_add->next = NULL;
                head = to_add;
            }
        else
        {
            to_add->next=head;
            head=to_add;
        }
        count++;
    }

    void add(T data, int pos)
    {
        if (pos>count)
            throw std::runtime_error("invalid position");

        List *current;
        current=head;

        Iterator<T> a(current);
        for (int i=0; i<(pos-1); i++)
        {
            ++a;
        }

        List* to_add=new List;
        to_add->next=a.getCur()->next;
        to_add->value=data;

        a.getCur()->next=to_add;
        count++;
    }

    void del(int pos)
    {
        if (pos>count)
            throw std::runtime_error("invalid position");

        List *to_del = head;
        if (pos==0)
        {
            head = head->next;
            delete to_del;
        }
        else
        {
            List *current;
            current = head;
            Iterator<T>  a(current);

            for(int i=0; i<(pos-1); i++)
                ++a;

            to_del = a.getCur()->next;
            a.getCur()->next = a.getCur()->next->next;
            delete to_del;
        }
        --count;
    }
};


template <typename T> class Iterator
{
public:

    Iterator(List<T> *a)
    {
        cur=a;
    }

    T operator*()
    {
        return cur->value;
    }

    void operator++()
    {
        cur=cur->next;
    }

    bool operator==(Iterator &a)
    {
        if (this==a.cur)
            return true;
        else
            return false;
    }

    bool operator!=(Iterator &a)
    {
        if (this!=a.cur)
            return true;
        else
            return false;
    }

    bool isValid()
    {
        return cur!=nullptr;
    }

    List<T>* getCur()
    {
        return cur;
    }

private:
    List<T> *cur;

};



#endif // LIST_H
