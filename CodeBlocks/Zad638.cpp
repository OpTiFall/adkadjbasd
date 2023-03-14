#include <bits/stdc++.h>
using namespace std;

struct fraction
{
    long int a;
    long int b;
    void print()
    {
        cout << a << "/" << b << endl;
    }

    fraction operator+(fraction f)
    {
        fraction result;
        int nwd = __gcd(b,f.b);
        int nww = b/nwd*f.b;
        result.b = nww;
        result.a = (a*nww/b) + (f.a*nww/f.b);
        int nwd3 = __gcd(result.b,result.a);
        result.a /= nwd3;
        result.b /= nwd3;
        return result;
    }

    fraction operator-(fraction f)
    {
        fraction result;
        int nwd = __gcd(b,f.b);
        int nww = b/nwd*f.b;
        result.b = nww;
        result.a = (a*nww/b) - (f.a*nww/f.b);
        int nwd3 = __gcd(result.b,result.a);
        result.a /= nwd3;
        result.b /= nwd3;
        return result;
    }

    fraction operator*(fraction f)
    {
        fraction result;
        int nwd1 = __gcd(b,a);
        int nwd2 = __gcd(f.b,f.a);
        result.b = (b/nwd1) * (f.b / nwd2);
        result.a = (a/nwd1) * (f.a / nwd2);
        int nwd3 = __gcd(result.b,result.a);
        result.a /= nwd3;
        result.b /= nwd3;
        return result;
    }
    fraction operator/(fraction f)
    {
        fraction result;
        int nwd1 = __gcd(b,a);
        int nwd2 = __gcd(f.b,f.a);
        result.b = (b/nwd1) * (f.a / nwd2);
        result.a = (a/nwd1) * (f.b / nwd2);
        int nwd3 = __gcd(result.b,result.a);
        result.a /= nwd3;
        result.b /= nwd3;
        return result;
    }

    bool operator<(fraction &f)
    {
        fraction f1;
        f1.a = f.a;
        f1.b = f.b;
        fraction f2;
        f2.a = a;
        f2.b = b;
        simplify(f1);
        simplify(f2);
        int nwd = __gcd(f1.b,f2.b);
        int nww = f1.b/nwd*f2.b;
        f1.a = f1.a*nww/f1.b;
        f2.a = f2.a*nww/f2.b;
        if(f2.a == f1.a) return b < f.b;
        return f2.a < f1.a;

    }

    bool operator>(fraction &f)
    {
        fraction t1 = f;
        fraction t2;
        t2.a = a;
        t2.b = b;
        return t1 < t2;
    }

    void simplify(fraction &f)
    {
        int nwd = __gcd(f.a,f.b);
        f.a /=nwd;
        f.b /=nwd;
    }

    bool isSimplified()
    {
        return __gcd(a,b) == 1;
    }
};

vector<fraction> dane;

void A()
{
    fraction minimum = dane[0];
    for(fraction f: dane)
    {
        if(f < minimum) {minimum = f;}
    }
    minimum.print();
}

int b;

void B()
{
    for(fraction f: dane)
    {
        if(f.isSimplified()) { b++;}
    }
    cout << b << endl;
}

int c;

void C()
{
    for(fraction f: dane)
    {
        fraction fs = f;
        fs.simplify(fs);
        c+= fs.a;
    }
    cout << c << endl;
}

fraction d;

fraction output;

void D()
{
    d.a = 0;
    d.b = 1;

    for(fraction f: dane)
    {
        d = d + f;
    }

    int m = (4 * 9 * 25 * 49 * 13) / d.b;
    d.a *= m;
    cout << d.a << endl;
}



int main()
{
    ifstream plik("dane_ulamki.txt");
    for(int i = 0; i < 1000; i++)
    {
        fraction f;
        plik >> f.a >> f.b;
        dane.push_back(f);
    }
    A();
    B();
    C();
    D();
    return 0;

}
