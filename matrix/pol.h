#ifndef POL_H
#define POL_H
#include "rat.h"
#define mx_deg 15
#define inf 1000
using namespace std;

class pol
{
public:
    int deg;
    rat m[mx_deg + 1];
    rat* a;
    rat* b;
    rat* x;
    rat* y;

    void set_deg()
    {
        deg = -inf;
        for (int i = mx_deg; i >= 0; i--)
            if (m[i].p != 0)
            {
                deg = i;
                return;
            }
    }

    pol()
    {
        deg = -inf;
        for (int i = 0; i <= mx_deg; i++)
            m[i] = rat(0, 1);
    }

    pol(bool x)
    {
        cout << "deg: ";
        cin >> deg;

        for (int i = 0; i <= mx_deg; i++)
            m[i] = rat(0, 1);
        for (int i = 0; i <= deg; i++)
        {
            int p, q;
            cin >> p >> q;
            m[i] = rat(p, q);
        }
        set_deg();
    }

    pol operator+(const pol& a) const
    {
        pol ans;
        for (int i = 0; i <= mx_deg; i++)
            ans.m[i] = (m[i] + a.m[i]);
        ans.set_deg();
        return ans;
    }

    void show()
    {
        set_deg();
        if (deg == -inf)
        {
            cout << "0";
            return;
        }
        if (deg == 0)
        {
            m[0].show();
            return;
        }

        m[0].show();
        cout << " + ";
        for (int i = 1; i < deg; i++)
            if (m[i].p != 0)
            {
                m[i].show();
                cout << "x ^ " << i << " + ";
            }
        m[deg].show();
        cout << "x ^ ";
        cout << deg;
    }

    pol operator*(const pol& a) const
    {
        pol ans;
        for (int i = 0; i <= mx_deg; i++)
            for (int j = 0; j <= i; j++)
                ans.m[i] = ans.m[i] + (m[j] * a.m[i - j]);
        ans.set_deg();
        return ans;
    }

    void operator=(const pol& a)
    {
        deg = a.deg;
        for (int i = 0; i <= mx_deg; i++)
            m[i] = a.m[i];
        set_deg();
    }

    static void swap(pol& a, pol& b)
    {
        pol temp;
        temp = a;
        a = b;
        b = temp;
    }
    //pol(rat* a, ...)
};
#endif // POL_H
