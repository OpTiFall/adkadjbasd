#include<bits/stdc++.h>
#include<math.h>
using namespace std;

double squareRoot(__int128 a)
{
    __int128 x1 = 2;
    __int128 x2 = (x1+a/x1)/2;
    while(abs(x2 - x1)*1000 > 1)
    {
        x1 = x2;
        x2 = (x1+a/x1)/2;
    }
    return x2;
}

long int intSquareRoot(const long int n)
{
    __int128 p = 1;
    while(true)
    {
        p = (p+n/p)/2;
        if(p*p <= n && (p+1)*(p+1) > n) { return p;}
    }
    return (long)p;
}

int main()
{
    ifstream input("pierwiastki_calkowite.txt");

    long int sum = 0;
    long int sum2 = 0;
    long int t;

    while(input >> t) { sum += squareRoot(t); sum2 += intSquareRoot(t);}
    cout << sum << endl;
    cout << sum2 << endl;

    return 0;
}
