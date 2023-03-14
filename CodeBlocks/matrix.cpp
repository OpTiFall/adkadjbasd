#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int main()
{
    cout << "How many numbers?";
    int anw;
    cin>>anw;

    srand (time(NULL));

    while(anw)
    {
        cout << rand() % 10 + 1;
        anw--;
    }
    return 0;
}
