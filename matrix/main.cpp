#include "mat.h"
#include "mat_mn.h"
#include "pol.h"
#include "mat_pol.h"

using namespace std;

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
                a.e->m[i][i] = rat(0, 1);
        a.e->m[0][0] = rat(2, 1); a.e->m[1][0] = rat(3, 1); a.e->m[2][0] = rat(1, 1); a.e->m[3][0] = rat(5, 1); a.e->m[4][0] = rat(0, 1);
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

    if (mode == 2)
    {
        mat_xy a;
        cout << "A: " << endl;
        a.show();

        cout << "A^2_1: " << endl;
        mat_xy a2(a * a);
        cout << "A^2: " <<endl;
        a2.show();

        cout << "A^3_1: " << endl;
        mat_xy a3(a2 * a);
        cout << "A^3: " << endl;
        a3.show();
    }

    if (mode == 3)
    {
        int n;
        cout << "Input n: " << endl;
        cin >> n;
        pol** m = new pol*[n];
        cout << "Deg, pol" << endl;
        for (int i = 0; i < n; i++)
        {
            m[i] = new pol[n];
            for (int j = 0; j < n; j++)
            {
                cout << "c" << i + 1 << "," << j + 1 << ": ";
                int deg;
                cin >> deg;
                for (int k = 0; k <= deg; k++)
                {
                    int p, q;
                    cin >> p >> q;
                    m[i][j].m[k] = rat(p, q);
                }
            }
        }

        mat_pol a(n, m);
        a.show();

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
                    a.swap_col(i - 1, j - 1);
                else
                    a.swap_row(i - 1, j - 1);
            }
            if (c == 'a')
            {
                int i, j;
                cin >> i >> j;
                pol x;
                int deg;
                cin >> deg;
                for (int k = 0; k <= deg; k++)
                {
                    int p, q;
                    cin >> p >> q;
                    x.m[k] = rat(p, q);
                }
                a.add( i - 1, j - 1, x);
            }
            if (c == 'p')
            {
                int i;
                cin >> i;
                pol x;
                int deg;
                cin >> deg;
                for (int k = 0; k <= deg; k++)
                {
                    int p, q;
                    cin >> p >> q;
                    x.m[k] = rat(p, q);
                }
                a.pr( i - 1, x);
            }

            if (c == 'z')
            {
                int i, j;
                cin >> i >> j;
                a.make_zero(i-1, j-1);
            }

            if (c == 'e')
                return 0;

            a.show();
            cout << endl << endl;
        }
    }

    if (mode == 4)
    {
        pol a(true);
        pol b(true);

        cout << "A: "; a.show(); cout << endl;
        cout << "B: "; b.show(); cout << endl;
        pol::euclid(a, b);
    }
    return 0;
}
