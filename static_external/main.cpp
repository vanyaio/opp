#include <iostream>
#include "global_vars.h"
using namespace std;

void foo()
{
    static int calling_foo_cnt = 0;
    calling_foo_cnt++;
    cout << "calling_foo_cnt: " << calling_foo_cnt << endl;
}

void test()
{
    cout << "and this is main's test func" << endl;
}

int main()
{
    cout << global_c << endl;//global variables ex

    cout << "s1: " << s1 << endl;//static vars ex
    increment_s1();
    increment_s1();
    cout << "s1: " << s1 << endl;

    foo();//static in function ex
    foo();

    pretest();//static function ex
    test();

    //static fields and methods
    cout << "global_class_var: " << my_class::get_var() << endl;
    my_class::change_static_var();
    cout << "global_class_var: " << my_class::get_var() << endl;

    return 0;
}
