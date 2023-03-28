#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int a, b, c, d;


double thisStupidThing(double x1, double x2)
{
    if(x2 < x1)
    {
        double t = x2;
        x2 = x1;
        x1 = t;
    }

    double dx = abs(x1 - x2);
    double f1, f2, fs;
    double xs = (x1+x2)/2;
    while(dx > 0.001)
    {
        f1 = a*x1*x1*x1 + b*x1*x1 + c*x1 + d;
        f2 = a*x2*x2*x2 + b*x2*x2 + c*x2 + d;
        fs = a*xs*xs*xs + b*xs*xs + c*xs + d;
        if(f1*fs < 0)
        {
            x2 = xs;
        }
        else
        {
            x1 = xs;
        }
        xs = (x1+x2)/2;
        dx = abs(x1 - x2);
    }
    return (x2+x1)/2;
}

int main()
{
    srand((unsigned) time(NULL));

    do
    {
        a = rand() % 20 - 10;
    }   while(a == 0);

    b = rand() % 20 - 10;
    c = rand() % 20 - 10;
    d = rand() % 20 - 10;
    cout << a << " " << b << " " << c << " " << d << endl;
    int e, f, g;
    e = 3*a;
    f = 2*b;
    g = c;
    double delta = f*f - 4*e*g;
    if(delta <= 0)
    {
        cout << "nie" << endl;
        return 0;
    }
    double x1 = (-f + sqrt(delta))/(2*e);
    double x2 = (-f - sqrt(delta))/(2*e);
    double f1 = a*x1*x1*x1 + b*x1*x1 + c*x1 + d;
    double f2 = a*x2*x2*x2 + b*x2*x2 + c*x2 + d;
    if(f1*f2 > 0)
    {
        cout << "nie2" << endl;
        return 0;
    }
    double zero = thisStupidThing(x1, x2);
    cout << zero << endl;
    return 0;
}
