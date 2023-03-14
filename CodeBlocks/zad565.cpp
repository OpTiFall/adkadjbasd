#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int const L = 1001;

int numbers[L];

bool isPrimal(int a)
{
    if(a == 0 || a == 1) {return false;}
    for(int i = 2; i <= a/2; i++)
    {
        if(a % i == 0)
        {
            return false;
        }
    }
    return true;
}

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

void bubbleSort()
{
    bool unsorted = true;
    int temp;
    while (unsorted)
    {
        unsorted = false;
        for (int i = 1; i < L; i++)
        {
            if (numbers[i-1] > numbers[i])
            {
            temp = numbers[i];
            numbers[i] = numbers[i-1];
            numbers[i-1] = temp;
            unsorted = true;
            }
        }
    }
}

int main()
{
    ifstream input;
    ofstream output;
    input.open("zestaw.txt");
    output.open("zad565output.txt");

    int sum = 0;
    int primals = 0;
    int maxNWD = 0;
    int sameNWDNumbers[L];
    for(int i = 0; i < L; i++)
    {
        input >> numbers[i];
        sum += numbers[i];
        if(isPrimal(numbers[i])){primals++;}
        int nwd = NWD(numbers[i], 2358);
        if(nwd > maxNWD)
        {
            for(int i = 0; i < L; i++)
            {
                sameNWDNumbers[i] = 0;
            }
            maxNWD = nwd;
            sameNWDNumbers[i] = numbers[i];
        }
        if(nwd == maxNWD)
        {
            sameNWDNumbers[i] = numbers[i];
        }
    }
    bubbleSort();
    output << "Min: " << numbers[0] << " Max: " << numbers[L-1] << endl;

    int medianaIndex = (L-1)/2;
    output << "Mediana: " << numbers[medianaIndex] << endl;

    output.precision(7);
    float average = (float)sum/L;
    output << "Średnia: " << average << endl;

    int closest = 0;
    int j = 0;
    while(numbers[j] < average)
    {
        j++;
    }
    float a = -(average - numbers[j]);
    float b = average - numbers[j - 1];

    if(a < b)
    {
        closest = numbers[j];
    }
    else
    {
        closest = numbers[j - 1];
    }

    output << "Najbliższa średniej: " << closest << endl;

    output << "Ilość liczb pierwszych: " << primals << endl;

    for(int i = 0; i < L; i++)
    {
        if(sameNWDNumbers[i] != 0)
        {
            output << "NWD: " << sameNWDNumbers[i] << endl;
        }
    }
    output << "Ich NWD jest równe " << maxNWD << endl;

}

