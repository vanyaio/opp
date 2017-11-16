#ifndef RAT_H
#define RAT_H
#include<bits/stdc++.h>
#define maxn 100;

int gcd(int a, int b);

struct rat
{
    int p;
    int q;

    rat()
    {
        p = 0; q = 1;
    }

    rat(int _p, int _q)
    {
        p = abs(_p);
        q = abs(_q);
        int _gcd = gcd(abs(_p), abs(_q));
        p /= _gcd; q /= _gcd;
        if (_p * _q < 0)
            p = -p;
    }

    rat operator+(const rat& a) const
    {
        rat ans((p * a.q + a.p * q), q * a.q);
        return ans;
    }

    rat operator*(const rat& a) const
    {
        rat ans((p * a.p), (q * a.q));
        return ans;
    }

    void operator=(const rat& a)
    {
        p = a.p; q = a.q;
    }

    static void swap(rat& a, rat& b)
    {
        rat temp(0, 1); temp = a; a = b; b = temp;
    }

    void show()
    {
        if (p == 0)
        {
            std::cout << 0;
            return;
        }
        if (q == 1)
        {
            std::cout << p;
            return;
        }
        std::cout << p << "/" << q;
    }

    static int len(int a)
    {
        int ans = 0;
        if (a < 0) ans++;
        a = abs(a);
        while (a > 0)
        {
            a /= 10;
            ans++;
        }
        return ans;
    }

    int len()
    {
        if (p == 0)
            return 1;
        if (q == 1)
            return rat::len(p);
        return (rat::len(p) + 1 + rat::len(q));

    }
};

int gcd(int a, int b)
{
    if (a > b)
        std::swap(a, b);
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
#endif // RAT_H
