#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>
using namespace std;

int const L = 1000;

int evenNumbers;
int firstLargerThenSecond;
int multiplicationOfTheOther;
int nwdEqualOne;
int equalDigitsSum;
int powerOf3Numbers[L];
int lastPOWIndex;

int parA[L];
int parB[L];

bool isMultiplicationOfAnNumber(int checked, int multiplied)
{
    if(checked == multiplied || multiplied == 1)
    {
        return true;
    }
    if(checked < multiplied)
    {
        int temp = checked;
        checked = multiplied;
        multiplied = checked;
    }
    int multipliedTemp = 0;
    int t = multiplied;
    while(checked > multipliedTemp)
    {
        multipliedTemp += t;
        if(multipliedTemp == checked)
        {
            return true;
        }
    }
    return false;
}

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

void CalculateAmountOfEvenNumbers(int i)
{
    if(parA[i] % 2 == 0 && parB[i] % 2 == 0)
    {
        evenNumbers++;
    }
}

void CalculateIfAreMultiplications(int i)
{
    if(isMultiplicationOfAnNumber(parA[i], parB[i]))
    {
        multiplicationOfTheOther++;
    }
}

void CalculateIfNWDEqualsOne(int i)
{
    if(NWD(parA[i], parB[i]) == 1)
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

    while(parA[i] > t/10)
    {
        digit1 = ((parA[i] % t) - digit2)/(t/10);
        t *= 10;
        digit2 = ((parA[i] % t) - digit1) / (t/10);
        t *= 10;
        firstSumOfDigits += digit1 + digit2;
    }

    digit1 = 0;
    digit2 = 0;
    t = 10;
    while(parB[i] > t/10)
    {
        digit1 = ((parB[i] % t) - digit2) / (t/10);
        t *= 10;
        digit2 = ((parB[i] % t) - digit1) / (t/10);
        t *= 10;
        secondSumOfDigits += digit1 + digit2;
    }

    if(firstSumOfDigits == secondSumOfDigits)
    {
        equalDigitsSum++;
    }

}

bool isPowerOf3(int number)
{
    if(number == 1)
    {
        return true;
    }
    int t = 3;
    while(number >= t)
    {
        if(t == number)
        {
            return true;
        }
        t *= 3;
    }
    return false;
}


void CalculateNumbersOfPowerOf3(int i)
{
    if(isPowerOf3(parA[i]))
    {
        powerOf3Numbers[lastPOWIndex] = parA[i];
        lastPOWIndex++;
    }
    if(isPowerOf3(parB[i]))
    {
        powerOf3Numbers[lastPOWIndex] = parB[i];
        lastPOWIndex++;
    }
}

int main()
{
    ifstream input;
    ofstream output;
    ofstream powerOf3;
    input.open("PARY_LICZB.TXT");
    output.open("zad501output.txt");
    powerOf3.open("POTEGI.TXT");

    for(int i = 0; i < L; i++)
    {
        input >> parA[i] >> parB[i];
    }

    for(int i = 0; i < L; i++)
    {
        CalculateAmountOfEvenNumbers(i);
        if(parA[i] > parB[i]){firstLargerThenSecond++;}
        CalculateIfAreMultiplications(i);
        CalculateIfNWDEqualsOne(i);
        CalcualteIfSumOfDigitsIsEqual(i);
        CalculateNumbersOfPowerOf3(i);
    }
    output << "Ilość parzystych par liczb: " << evenNumbers << endl;
    output << "Ilość par, w których pierwsza liczba jest pierwsza od drugiej: " << firstLargerThenSecond << endl;
    output << "Ilość par, w których jedna liczba jest wielokrotnością drugiej: " << multiplicationOfTheOther << endl;
    output << "Ilość par liczb względnie pierwszych: " << nwdEqualOne << endl;
    output << "Ilość par liczb, których suma cyfr jest równa: " << equalDigitsSum << endl;
    for(int i = 0; i < lastPOWIndex; i++)
    {
        powerOf3 << powerOf3Numbers[i] << endl;
    }
}

