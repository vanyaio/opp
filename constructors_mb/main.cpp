#include <iostream>
using namespace std;

class cl
{
private:
    const int f1;
public:
    cl(int init_f1) : f1(init_f1){}
    cl(cl& obj): f1(obj.f1) {}
    int f() const {} //does not change fields of object

};

int main()
{
    void** x;
    void* y;
    y = (void*)x;
    x = (void**)y;
    return 0;
}
