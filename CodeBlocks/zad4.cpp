#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int main()
{
    int x, y;
    cout << "Podaj dwie liczby: " << endl;
    cin >> x >> y;

    if(x % y == 0)
    {
        cout << "Te liczby są podzielne przez siebie" << endl;
    }
    else
    {
        cout << "Te liczby nie są podzielne przez siebie" << endl;
    }
}

