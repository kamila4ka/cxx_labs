#ifndef LIST_H
#define LIST_H

#include <stdexcept>

template <typename T> class List // шаблон класса односвязного списка
{
    public:
    class Node // класс Node содержит данные списка
    {
    public:
        Node *next; // указатель на следующий элемент в списке
        T value; // данные списка

        Node(): next(NULL){}
        ~Node(){}
    };

    Node *head; // указатель на начало списка
    int count; // число элементов в списке

    int getCount() const // возвращает количество элементов в списке
    {
        return count;
    }

    class iterator
    {
    public:

        Node *cur;

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

        bool operator==(iterator *a)
        {
            if (this->cur==a->cur)
                return true;
            else
                return false;
        }

        bool operator!=(iterator &a)
        {
            if (this->cur!=a.cur)
                return true;
            else
                return false;
        }

        Node* getCur()
        {
            return cur;
        }
    };

    List(): head(NULL), count(0){}
    ~List()
    {
        clear(); // функция освобождает память, используемую для хранения списка
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
        Node* current = new Node;
        for(current=head; current!=NULL; current=current->next);
        return current;
    }


    T getData(int x) const // возвращает данные из списка.
    {
        if (x>count)
            throw std::runtime_error("invalid position");

        Node *current;
        current=head;
        iterator a(current);

        for (int i=0; i<x; i++)
            ++a;

        return *a;
    }


    void append(T data)// добавление элемента в конец списка
    {
        Node *to_add = new Node;
        to_add->next = NULL;
        to_add->value = data;

        if(head == NULL) // если в списке нет элементов
            head = to_add;
        else
        {
            Node *current=new Node;
            for (current=head; current->next!=nullptr; current=current->next);
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
            ++a;

        current=a.getCur();

        Node* to_add=new Node;
        to_add->next=current->next;
        to_add->value=data;

        current->next=to_add;
        count++;
    }

    void del(int x) // удаление элемента из списка
    {
        if (x>count)
            throw std::runtime_error("invalid position");

        Node *to_del = head;
        if (x==0)
        {
            head = head->next;
            delete to_del;
        }
        else
        {
            Node *current;
            current = head;
            iterator  a(current);
            for(int i=0; i<(x-1); i++)
                ++a;
            current=a.getCur();
            to_del = current->next;
            current->next = current->next->next;
            delete to_del;
        }
        --count;
    }

    void clear() // очистка списка
    {
        Node *current = head;
        Node *to_del = head;


        while (to_del!=NULL)
        {
            current=current->next;
            delete to_del;
            to_del=current;
        }
        head=NULL;
        count=0;
    }

};




#endif // LIST_H
