#include "mat.h"
#include "mat_mn.h"

using namespace std;
int foo(rat x)
{
    return x.p;
}
int main()
{
    int mode;
    cout << "Input mode: ";
    cin >> mode;

    if (mode == 1)
    {


        int n;
        cout << "Input n: " << endl;
        cin >> n;
        rat** m = new rat*[n];
        for (int i = 0; i < n; i++)
        {
            m[i] = new rat[n];
            for (int j = 0; j < n; j++)
            {
                int p, q;
                cin >> p >> q;
                rat a(p, q);
                m[i][j] = a;
            }
        }

        bool show_e = false;
        char c;
        cout << "Input y if show E: " << endl;
        cin >> c;
        if (c == 'y')
            show_e = true;

        mat a(n, m);

        /*
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a.m[i][i] = 0;
        a.m[0][0] = ; a.m[1][0] = ; a.m[2][0] = ;
        */

        a.show(show_e, 'A');
        while (true)
        {
            char c;
            cin >> c;
            if (c == 's')
            {
                cin >> c;
                int i, j;
                cin >> i >> j;
                if (c == 'c')
                {
                    a.swap_col(i - 1, j - 1);
                    a.e->swap_col(i - 1, j - 1);
                }
                else
                {
                    a.swap_row(i - 1, j - 1);
                    a.e->swap_row(i - 1, j - 1);
                }
            }
            if (c == 'a')
            {
                int i, j, p, q;
                cin >> i >> j >> p >> q;
                rat x(p, q);
                a.add( i - 1, j - 1, x);
                a.e->add( i - 1, j - 1, x);
            }
            if (c == 'p')
            {
                int i, p, q;
                cin >> i >> p >> q;
                rat x(p, q);
                a.pr( i - 1, x);
                a.e->pr( i - 1, x);
            }
            if (c == 'z')
            {
                int i, j;
                cin >> i >> j;
                a.make_zero(i-1, j-1);
            }
            if (c == 'e')
                return 0;

            a.show(show_e, 'A');
            cout << endl << endl;
        }

    }

    else
    {
        mat_xy a;
        cout << "A: " << endl;
        a.show();

        mat_xy b;
        cout << "B: " << endl;
        b.show();

        cout << "C1: " << endl;
        mat_xy c(a * b);
        cout << "C2: " << endl;
        c.show();
        //mat_xy c(a * b);
        //c.show();
    }

    return 0;
}
