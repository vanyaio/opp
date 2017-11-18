#ifndef MAT_POL_H
#define MAT_POL_H

#include "pol.h"
using namespace std;

class mat_pol
{
public:
    int n;
    pol** m;
    pol r;
    mat_pol(int _n, pol** _m)
    {
        n = _n;
        m = _m;
        r.m[0] = rat(1, 1);
        r.set_deg();
    }

    ~mat_pol()
    {
        for (int i = 0; i < n; i++)
            delete[] m[i];
        delete[] m;
    }

    void add(int i, int j, const pol& x)
    {
        for (int k = 0; k < n; k++)
            m[i][k] = m[i][k] + (m[j][k] * x);
    }
    void pr(int i, const pol& x)
    {
        for (int k = 0; k < n; k++)
            m[i][k] = (m[i][k] * x);
        r = (r * x);
    }

    void swap_col(int i, int j)
    {
        for (int k = 0; k < n; k++)
            pol::swap(m[k][i], m[k][j]);
        r = r * rat(-1, 1);
    }

    void swap_row(int i, int j)
    {
        std::swap(m[i], m[j]);
        r = r * rat(-1, 1);
    }

    void show()
    {
        cout << "A: " <<endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "c" << i + 1 << "," << j + 1 << ": ";
                m[i][j].show();
                cout << "  ";
            }
            cout << endl;
        }
        cout << "R: ";
        r.show();
    }

    void make_zero(int i, int j)
    {
        for (int k = 0; k < n; k++)
        {
            if (k == i)
                continue;
            pol temp;
            temp = m[k][j];
            pr(k, m[i][j]);
            add(k, i, temp * rat(-1 , 1));
        }
    }
};
#endif // MAT_POL_H
