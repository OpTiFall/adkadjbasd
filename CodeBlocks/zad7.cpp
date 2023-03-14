#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

double calculateOutput(int k, int n)
{
    double output;
    const double t = pow(20,(double)1/3);
    for(int i = k; i <= n;i++)
    {
        double a = t/(2 * i);
        output += a;
    }

    return output;
}

int main()
{
    int k, n;

    do{
    cout << "Podaj liczby k i n" << endl;
    cin >> k >> n;
    }while(k == 0 || n == 0);

    cout << "Suma ta wynosi: " << calculateOutput(k, n) << endl;

    return 0;
}



