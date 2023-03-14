#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int silnia(int n)
{
    int r = 1;
    for(int i = n;i > 1;i--)
    {
		r *= i;
    }

    return r;
}

double cos_m(double x)
{
    long double output = 1;
    long double pOutput = 0;

    double p = 1;
    int s = 1;
    for(int i = 1; abs(output - pOutput) > 0.0001; i++)
    {
        p *= x;
        s*= i;

        if(i % 2 == 0){
            pOutput = output;
            if(i % 4 == 0)
            {
                output += p/s;
            }
            else
            {
                output -= p/s;
            }
        }

    }
    return output;
}

int main()
{
    int x;

    cout << "Podaj liczbę x" << endl;
    cin >> x;

    cout << "Kosinus tej liczby wynosi: " << cos_m(x) << endl;

    return 0;
}



