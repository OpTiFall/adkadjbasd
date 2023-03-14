#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int main()
{
    double p;
    int w;
    int wynik = 1;

    cout << "Podaj podstawę potęgi: ";
    cin >> p;
    cout << "Podaj wykładnik potęgi: ";
    do
    {
        cin >> w;
    }
    while(w < 0);

    for(int i = 0; i < w; i++)
    {
        wynik *= p;
    }
    cout << "Potęga ta wynosi: " << wynik << endl;
}
