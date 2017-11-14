#ifndef MAT_H
#define MAT_H
#include "rat.h"

class mat
{
public:
    rat** m;
    int n;
    mat* e;

    mat (int _n)
    {
        rat zero(0, 1), one(1, 1);
        n = _n;
        m = new rat*[_n];
        e = nullptr;
        for (int i = 0; i < _n; i++)
        {
            m[i] = new rat[_n];
            for (int j = 0; j < _n; j++)
                m[i][j] = zero;
        }
        for (int i = 0; i < _n; i++)
            m[i][i] = one;
    }

    mat(int _n, rat** _m)
    {
        n = _n;
        m = _m;
        e = new mat(n);
    }

    ~mat()
    {
        for (int i = 0; i < n; i++)
            delete[] m[i];
        delete[] m;
    }

    void add(int i, int j, rat x)
    {
        for (int k = 0; k < n; k++)
            m[i][k] = m[i][k] + (m[j][k] * x);
    }
    void pr(int i, rat x)
    {
        for (int k = 0; k < n; k++)
            m[i][k] = (m[i][k] * x);
    }
    void swap_col(int i, int j)
    {
        for (int k = 0; k < n; k++)
            rat::swap(m[k][i], m[k][j]);
    }

    void swap_row(int i, int j)
    {
        std::swap(m[i], m[j]);
    }

    void show(bool show_e, char A)
    {
        int mx = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mx = std::max(mx, m[i][j].len());
        std::cout << A << ":" << std::endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                m[i][j].show();
                for (int k = 1; k <= (mx - m[i][j].len() + 3); k++)
                    std::cout << " ";
            }
            std::cout << std::endl;
        }

        if (show_e)
            e->show(false, 'E');
    }

    void make_zero(int i, int j)
    {
        if (m[i][j].p == 0)
            return;
        rat x(m[i][j].q, m[i][j].p);
        pr(i, x);
        e->pr(i, x);
        for (int k = 0; k < n; k++)
        {
            if (k == i)
                continue;
            rat x(-m[k][j].p, m[k][j].q);
            add(k, i, x);
            e->add(k, i, x);
        }
    }
};

#endif MAT_H


