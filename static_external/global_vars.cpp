#include "global_vars.h"
#include <iostream>
using namespace std;
const int global_c = 0;
void increment_s1()
{
    s1++;
    cout << "global_vars.cpp's s1: " << s1 << endl;
}

void test()
{
    cout << "this is global vars's test func" << endl;
}

void pretest()
{
    test();
}

int my_class::global_class_var = 0;//static MUST be defined outside functions (but maybe it's allowed to be defined in methods...) - dunno why
void my_class::change_static_var()
{
    global_class_var++;
}
int my_class::get_var()
{
    return global_class_var;
}

/*void my_class::define_var() //works with line 21 too
{
    my_class::global_class_var = 0;
}*/
