#include "dynArr.h"

dynArr::dynArr(int t)
{
    sz = t;
    data = new int[t];
}

dynArr::~dynArr()
{
    delete [] data;
}

void dynArr::put(int i, int val)
{
    if ((i >= 0) && (i < sz))
        data[i] = val;
    return;
}

int dynArr::get(int i)
{
    if ((i >= 0) && (i < sz))
        return data[i];
    return -1;
}

int dynArr::get_sz()
{
    return sz;
}

/*dynArr::dynArr(dynArr& a)//default realization, merely copy all fields

{
    sz = a.sz;//yes, not a.get_sz() - dunno why...
    data = a.data;
}*/ //complicated problem with destructors: call delete[]a, call delete[]b - error (same part of memory)
//correct realization includes creating new memory

void dynArr::operator=(dynArr& a)//when void have troubles with a = (b = c), should be dynArr& and return *this
{
    if (this == &a)//works incorrect when a = a :)
        return;
    sz = a.sz;
    delete [] data;
    data = new int[sz];
    for (int i = 0; i < a.sz; i++)
        data[i] = a.data[i];
}




