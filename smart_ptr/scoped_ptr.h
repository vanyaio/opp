#ifndef SCOPED_PTR_H
#define SCOPED_PTR_H
class scoped_ptr// { scoped_ptr p1(new type()) ...}<- here all is deleted, without writing delete;
{
private:
    type* type_ptr;
    //Problems: {scoped_ptr p1, scoped_ptr p2 = p1 ...} - double delete
    //let's forbid = and copy constructor
    scoped_ptr(const scoped_ptr& p);//copy constructor is not safety too
    scoped_ptr& operator=(const scoped_ptr& p);
public:
    scoped_ptr(type* _type_ptr)
    {
        type_ptr = _type_ptr;
    }

    ~scoped_ptr()
    {
        if (type_ptr != nullptr)
            delete type_ptr;
    }

    type* get_type_ptr()
    {
        return type_ptr;
    }

    //scoped_ptr p(new type..),wanna do p->doSmth(), (*p).doSmth() - let's reload
    type* operator->()
    {
        return type_ptr;//VERY NOT UNDERSTANDABLE p->dosmth == p.type_ptr->dosmth ??? ANWSER SUPPOSED TO BE YES
    }
    type& operator*
    {
        return *type_ptr;
    }
};

class avto_ptr
{
    //same like scoped, but c.const & op= works differently
    // avto_ptr p1 = new type; avto_ptr p2 = p1; = overloading thus p1 points to null, p2 to p1.type_ptr
    // all following methods check whether p points to null

    avto_ptr(avto_ptr& p)
    {
        type_ptr = p.type_ptr;
        p.type_ptr = nullptr;
    }


};

class sharet_prt//see somewhere else
{


};
#endif // SCOPED_PTR_H
