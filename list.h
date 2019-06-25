#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T> class List
{
    public:
    class Node
    {
    public:
        Node *next;
        T value;

        Node(): next(NULL){}
        ~Node(){}
    };

    Node *head;
    int count;

    int getCount() const
    {
        return count;
    }

    class iterator
    {
    public:

        iterator(Node *a)
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

        bool operator==(iterator &a)
        {
            if (this==a.cur)
                return true;
            else
                return false;
        }

        bool operator!=(iterator &a)
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

        Node* getCur()
        {
            return cur;
        }

    private:
        Node *cur;

    };

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

    Node* begin() const
    {        
        return head;
    }

    Node* end() const
    {
        iterator a(head);
        while (a.getCur()->next)
        {
            ++a;
        }

        return a.getCur();
    }


    void getData() const
    {
        Node *current;
        current=head;
        iterator a(current);
        while (a.isValid())
        {
            cout << *a << " ";

            ++a;
        }
    }


    void append(T data)
    {
        Node *to_add = new Node;
        to_add->next = NULL;
        to_add->value = data;

        if(head == NULL)
            head = to_add;
        else
        {
            Node *current=new Node;

            current=this->end();
            current->next = to_add;
        }
        count++;
    }

    void addbegin(T data)
    {
        Node *to_add = new Node;
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

        Node *current;
        current=head;

        iterator a(current);
        for (int i=0; i<(pos-1); i++)
        {
            ++a;
        }

        Node* to_add=new Node;
        to_add->next=a.getCur()->next;
        to_add->value=data;

        a.getCur()->next=to_add;
        count++;
    }

    void del(int pos)
    {
        if (pos>count)
            throw std::runtime_error("invalid position");

        Node *to_del = head;
        if (pos==0)
        {
            head = head->next;
            delete to_del;
        }
        else
        {
            Node *current;
            current = head;
            iterator  a(current);

            for(int i=0; i<(pos-1); i++)
                ++a;
            current=a.getCur();

            to_del = current->next;
            current->next = current->next->next;
            delete to_del;
        }
        --count;
    }
};






#endif // LIST_H
