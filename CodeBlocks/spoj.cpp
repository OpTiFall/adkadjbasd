#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n == 0 || n == 1 || n == 2)
    {
        cout << "NIE";
        return 0;
    }
    n++;
    int output[n];
    for(int i = 0; i <= n; i++)
    {
        output[i] = i;
    }

    for(int i = 1; i < n/2; i = i + 2)
    {
        int tV = output[i];
        output[i] = output[n-i];
        output[n-i] = tV;
    }
    if(n == 4)
    {
        int tV = output[2];
        output[2] = output[3];
        output[3] = tV;
    }
    for(int i = 0; i < n; i++)
    {
        cout << output[i] << " ";
    }

    return 0;
}




