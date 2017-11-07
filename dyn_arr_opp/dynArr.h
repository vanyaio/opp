#ifndef ARR_H
#define ARR_H

class dynArr
{
    private://encapsulation
        int sz;
        int* data;
    public:
        dynArr(int t);
        ~dynArr();
        void put(int i, int val);
        int get(int i);
        int get_sz();
        //dynArr(dynArr& a) //copy constructor, generating by default, see default realization in dynArr.cpp
        //has a lot of troubles inside, better put it into private to prevent using, or write your own that is more safety
        //copy constructors uses when calling void f(dynArr x);, that is the reason why dynArr& - not just dynArr

        //void operator = (dynArr& a); - default realization with almost same troubles like copy construct, works almost the same way
        void operator = (dynArr& a);

};

#endif // ARR_H
