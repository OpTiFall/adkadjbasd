#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

double calculateS(double t)
{
    const double a = 9.81;
    return (a * (pow(t,2))/2;
}

int main()
{
    double t;
    cout << "Podaj ile sekund ciało przebywało w spadku swobodnym" << endl;
    cin >> t;
    cout << "Ciało te przebyło " << calculateS(t) << " metrów w spadku swobodnym" << endl;

    return 0;
}


