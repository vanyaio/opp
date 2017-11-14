#ifndef MAT_MN_H
#define MAT_MN_H
#include<bits/stdc++.h>
#include "rat.h"
using namespace std;
class mat_xy
{
public:
    rat** m;
    int x;
    int y;

    mat_xy()
    {
        cout << "Input x, y: " << endl;
        int _x, _y; cin >> _x >> _y; x = _x; y = _y;
        cout << "Input matrix: " << endl;

        m = new rat*[x];
        for (int i = 0; i < x; i++)
        {
            m[i] = new rat[y];
            for (int j = 0; j < y; j++)
            {
                int p, q;
                cin >> p >> q;
                rat a(p, q);
                m[i][j] = a;
            }
        }
    }

    mat_xy(const mat_xy& a)
    {
        x = a.x; y = a.y;
        rat** m = new rat*[x];
        for (int i = 0; i < x; i++)
        {
            m[i] = new rat[y];
            for (int j = 0; j < y; j++)
                m[i][j] = a.m[i][j];
        }
    }

    mat_xy(int _x, int _y)
    {
        x = _x;
        y = _y;
        m = new rat*[x];
        for (int i = 0; i < x; i++)
            m[i] = new rat[y];
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                m[i][j] = rat(0, 1);
    }

    mat_xy(int _x, int _y, rat** _m)
    {
        x = _x;
        y = _y;
        m = _m;
    }

    ~mat_xy()
    {
        for (int i = 0; i < x; i++)
            delete[] m[i];
        delete[] m;
    }

    void fill_ij(int i, int j, const mat_xy& a, mat_xy& ans) const
    {
        ans.m[i][j] = rat(0, 1);
        for (int k = 0; k < y; k++)
            ans.m[i][j] = ans.m[i][j] + (m[i][k] * a.m[k][j]);
        for (int k = 0; k < (y - 1); k++)
        {
            (m[i][k].show()); cout << " * "; (a.m[k][j].show()); cout << " + ";
        }
            //cout << (m[i][k].show()) << " * " << (a.m[k][j].show()) << " + ";
        //cout << (m[i][y - 1].show()) << " * " << (a.m[y - 1][j].show()) << "; ";
        (m[i][y - 1].show()); cout << " * "; (a.m[y - 1][j].show()); cout << "; ";
    }

    mat_xy operator*(const mat_xy& a) const
    {
        mat_xy ans(x, a.y);
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < a.y; j++)
                fill_ij(i, j, a, ans);
            cout << endl;
        }
        return ans;
    }

    void show()
    {
        int mx = -1;
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++)
                mx = std::max(mx, m[i][j].len());

        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                m[i][j].show();
                for (int k = 1; k <= (mx - m[i][j].len() + 3); k++)
                    std::cout << " ";
            }
            std::cout << std::endl;
        }

    }

};

#endif // MAT_MN_H
