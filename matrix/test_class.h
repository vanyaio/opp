#ifndef TESH_CLASS_H
#define TEST_CLASS_H
class cl
{
private:
    int x;
    c1* e;
public:

    /*void operator=(const cl& a)
    {
        x = a.x; e = a.e;
    }*/

    cl(int _x, bool is_e)
    {
        x = _x;
        if (!is_e)
        {

        }
    }

    cl* val_e()
    {
        return e;
    }
};
#endif // TESH_CLASS_H
