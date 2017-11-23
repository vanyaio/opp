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

    pol operator-(const pol& a) const
    {
        pol ans;
        for (int i = 0; i <= mx_deg; i++)
            ans.m[i] = (m[i] - a.m[i]);
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

    pol operator*(const rat& a) const
    {
        pol ans;
        for (int i = 0; i <= mx_deg; i++)
            ans.m[i] = m[i] * a;
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

    rat last_coeff() const
    {
        return m[deg];
    }

    static void get_qr(const pol& as, const pol& b, pol& q, pol& r)
    {
        pol a = as;
        while (a.deg >= b.deg)
        {
            q.m[a.deg - b.deg] = a.last_coeff() / b.last_coeff();
            pol temp_q;
            temp_q.m[a.deg - b.deg] = q.m[a.deg - b.deg];
            a = (a - (b * temp_q));
            a.set_deg();
        }
        r = a;
    }


    static void euclid(const pol& as, const pol& bs)
    {
        pol a = as;
        pol b = bs;
        pol one;
        one.m[0] = rat(1, 1);
        pol zero;
        zero.m[0] = rat(0, 1);
        pol x[10];
        pol y[10];
        x[0] = one;
        y[0] = zero;
        x[1] = zero;
        y[1] = one;

        pol r[10];
        pol q[10];
        r[0] = a;
        r[1] = b;

        for (int i = 1; r[i].deg != -inf;)
        {
            cout << "step " << i << endl;
            get_qr(r[i - 1], r[i], q[i], r[i + 1]);
            r[i - 1].show(); cout << " = "; r[i].show(); cout << " * ("; q[i].show(); cout << ") + "; r[i + 1].show(); cout << endl;
            x[i + 1] = (x[i - 1] - (x[i] * q[i]));
            y[i + 1] = (y[i - 1] - (y[i] * q[i]));
            cout << "=> "; r[i + 1].show(); cout << " = "; x[i + 1].show(); cout << "  |||||  "; y[i + 1].show(); cout << endl;
            cout << endl << endl;
            r[i + 1].set_deg();
            ++i;
        }
    }
    //pol(rat* a, ...)
};
#endif // POL_H
