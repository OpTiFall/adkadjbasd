#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int const L = 60;

int dane[L] = {24023, 30435, 5687, 12034, 7607, 3590, 4289, 13001, 7797, 13525, 14713, 6258, 10309, 22595, 14549, 22702, 15079, 31650, 15663, 32637, 11560, 27158, 13930, 2371, 26027, 7242, 29912, 5662, 4329, 9825, 12123, 26487, 30839, 16944, 13515, 23511, 24456, 18858, 19608, 23804, 2226, 13723, 2737, 29741, 18677, 29850, 6820, 30922, 19449, 11832, 17926, 3367, 28055, 18046, 14869, 23962, 19611, 13719, 20636, 21971};

int NWD(int a, int b)
{
    int c;
    while(true)
    {
        c = a % b;
        if(c == 0) {return b;}
        a = b;
        b = c;
    }
    return 0;
}

int main()
{
    int a, b;
    int output = 0;
    for(int i = 1; i < L; i++)
    {
        a = dane[i-1];
        b = dane[i];
        output += NWD(a,b);
    }
    cout << output;
    return 0;

}


