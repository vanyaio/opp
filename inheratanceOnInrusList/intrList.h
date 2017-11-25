#ifndef INTR_LIST_H
#define INTR_LIST_H
#include<bits/stdc++.h>
using namespace std;

class intr_list
{
protected: //private - used by the class, protected - by heirs, public - by anything, see below why protected's chosen
    int value;
    intr_list* next;
public:

    intr_list(int _value)
    {
        next = nullptr;
        value = _value;
    }
    //~intr_list() {  };
    virtual void add(int x)//virtual to override, uses dynamic binding, see below
    {
        intr_list* curr = this;
        while (curr -> next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = new intr_list(x);
    }

    int length()
    {
        int cnt = 0;
        for (intr_list* curr = this; curr != nullptr; curr = curr ->next)
            cnt++;
        return cnt;
    }
};

class double_list : public intr_list
{
private:
    intr_list* prev;
public:
    double_list(int _value) : intr_list(_value) // if remove : intr_list(_value), default constructor calls if it exists
    {
        prev = nullptr;
    }

    void add(int x) override//overriding (like overloading, but not overloading because name and arguments are the same)
    {
        double_list* curr = this;
        while  (curr->next != nullptr )//next in protected section, thus may be appealed in double_list
            curr = (double_list*)curr->next;
        curr->next = new double_list(x);//curr->next is intr_list*, see below why it's allowed
        ((double_list*)(curr->next)) -> prev = (intr_list*)curr;
    }
};

//object of double_list is an object of intr_list
//here's some examples:
void foo(intr_list* l)//might pass double_list l as argument - all functions defined for intr_list are defined for double_list
{
    l->add(10);//if l is double_list, double_list's method add() calls;
}
void foo1()
{
    int tmp;
    cin >> tmp;
    intr_list* a = nullptr;
    if (tmp)
        a = new intr_list(10);
    else
        a = new double_list(10);
    a->add(20);//uses dynamic binding, while compilation compiler does not know which add() to call
}
#endif // INTR_LIST_H
