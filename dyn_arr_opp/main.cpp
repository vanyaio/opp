#include <iostream>
#include "dynArr.h"

using namespace std;

int main()
{
    dynArr a(10);
    dynArr b(10);
    b.put(0, 322);
    for (int i = 0; i < 10; i++)
        cout << b.get(i) << " " << a.get(i) << endl;

    cout << "|||||" << endl;
    b = a;

    for (int i = 0; i < 10; i++)
        cout << b.get(i) << " " << a.get(i) << endl;
}
