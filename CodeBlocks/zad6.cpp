#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

double calculateOutput(double x)
{
    return (sqrt(3) - pow(x,5))/(-2+x);
}

int main()
{
    double x = 0;

    do{
        cout << "Podaj liczbę x" << endl;
        cin >> x;
    }
    while (x == 2);

    cout << "Wynik tego wyrażenia wynosi: " << calculateOutput(x) << endl;

    return 0;
}
