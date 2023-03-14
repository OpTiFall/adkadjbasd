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

int main()
{
    ifstream input("pierwiastki_calkowite.txt");

    long int sum = 0;
    long int t;

    while(input >> t) { sum += squareRoot(t); }
    cout << sum << endl;

    return 0;
}
