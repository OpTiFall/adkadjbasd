#include <iostream>
#include <fstream>
using namespace std;

const int L = 1000;

int numbersA[L];
int numbersB[L];

int isMultiplicationOfEachOther;

int nwdEqualOne;

int equalDigitsSum;

bool isMultiplicationOfAnNumber(int checked, int multiplied)
{
    if (checked == multiplied || multiplied == 1)
    {
        return true;
    }
    if (checked < multiplied)
    {
        int temp = checked;
        checked = multiplied;
        multiplied = temp;
    }
    int multipliedTemp = 0;
    int t = multiplied;
    while (checked > multipliedTemp)
    {
        multipliedTemp += t;
        if (multipliedTemp == checked)
        {
            return true;
        }
    }
    return false;
}


int NWD(int a, int b)
{
    int c = 0;
    while (true)
    {
        if (b != 0) { c = a % b; }
        else { cout << "Cannot divide by zero - NWD Function" << endl; }
        if (c == 0) { return b; }
        a = b;
        b = c;
    }
    return 0;
}

void CalculateIfNWDEqualsOne(int i)
{
    if (NWD(numbersA[i], numbersB[i]) == 1)
    {
        nwdEqualOne++;
    }
}

void CalcualteIfSumOfDigitsIsEqual(int i)
{
    int firstSumOfDigits = 0;
    int secondSumOfDigits = 0;

    int t = 10;
    int digit1 = 0;
    int digit2 = 0;

    while (numbersA[i] > t / 10)
    {
        digit1 = ((numbersA[i] % t) - digit2) / (t / 10);
        t *= 10;
        digit2 = ((numbersA[i] % t) - digit1) / (t / 10);
        t *= 10;
        firstSumOfDigits += digit1 + digit2;
    }

    digit1 = 0;
    digit2 = 0;
    t = 10;
    while (numbersB[i] > t / 10)
    {
        digit1 = ((numbersB[i] % t) - digit2) / (t / 10);
        t *= 10;
        digit2 = ((numbersB[i] % t) - digit1) / (t / 10);
        t *= 10;
        secondSumOfDigits += digit1 + digit2;
    }

    if (firstSumOfDigits == secondSumOfDigits)
    {
        equalDigitsSum++;
    }

}


int main()
{
    ifstream input;
    input.open("pary_liczb.TXT");

    for (int i = 0; i < L; i++)
    {
        input >> numbersA[i];
        input >> numbersB[i];
    }

    for (int i = 0; i < L; i++)
    {
        if (isMultiplicationOfAnNumber(numbersA[i], numbersB[i])) { isMultiplicationOfEachOther++; }
        CalculateIfNWDEqualsOne(i);
        CalcualteIfSumOfDigitsIsEqual(i);
      
    }

    cout << "Jest " << isMultiplicationOfEachOther << " par liczb, ktorych jedna liczba jest wielokrotnoscia drugiej " << endl;
    cout << "Jest " << nwdEqualOne << " par liczb wzglednie pierwszych" << endl;
    cout << "Jest " << equalDigitsSum << " par liczb, ktorych suma liczb jest rowna" << endl;

}
