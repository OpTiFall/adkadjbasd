#include<bits/stdc++.h>
#include<math.h>
using namespace std;


double squareRoot(double a)
{
    const double delta = 0.001;
    double x1 = 2.0;
    double x2 = (x1+a/x1)/2;
    while(abs(x2 - x1) > delta)
    {
        x1 = x2;
        x2 = (x1+a/x1)/2;
    }
    return x2;
}

double power(double a, int n)
{
    double t = 1;
    while(n > 1)
    {
        if(n % 2 == 1) { t *= a;}
        a *= a;
        n /= 2;
    }
    return t*a;
}

double root(double a, int n)
{
    const double delta = 0.001;
    double x1 = 2.0;
    double x2 = ((n-1)*x1+a/pow(x1,n-1))/n;
    while(abs(x2 - x1) > delta)
    {
        x1 = x2;
        x2 = ((n-1)*x1+a/pow(x1,n-1))/n;
    }
    return x2;
}


int main()
{
    cout << squareRoot(25) << endl;
    cout << root(125, 3);
    return 0;
}
