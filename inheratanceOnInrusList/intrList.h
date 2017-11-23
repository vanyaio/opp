#ifndef INTR_LIST_H
#define INTR_LIST_H
class intr_list
{
public:
    int value;
    intr_list* next;

    intr_list(int _value)
    {
        next = nullptr;
        value = _value;
    }

    void add(int x)
    {
        intr_list* curr = this;
        while (curr -> next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = new intr_list(x);
    }

};
#endif // INTR_LIST_H
