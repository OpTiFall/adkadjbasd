#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int main()
{
    srand(time(NULL));

    int n;
    int stats[6];
    cout << "Ile razy rzucono kostką?" << endl;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int number = rand() % 6 + 1;
        cout << number << endl;
        stats[number-1]++;
    }

    for(int i = 0; i < 6; i++)
    {
        int hashNumber = (int)stats[i]/10;
        cout << i+1 << ": ";
        cout << hashNumber;
        /*while(hashNumber != 0)
        {
            cout << "#" << hashNumber;
            hashNumber--;
        }
        */
        cout << endl;
    }

    return 0;

}





