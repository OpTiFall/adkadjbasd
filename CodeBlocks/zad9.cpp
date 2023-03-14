#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int main()
{
    srand(time(NULL));

    int n;
    cout << "Do ilu losowych liczb chcesz obliczyć średnią arytmetyczną?" << endl;
    cin >> n;

    int numbers[n];
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        numbers[i] = rand() % 10000 + 1;
        sum += numbers[i];
    }

    cout << "Średnia arytmetyczna tych liczb wynosi: " << (double)sum/n;

    return 0;

}




