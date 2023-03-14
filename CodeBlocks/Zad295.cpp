#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

const int L = 1000;

string numbers[L];
int numbersDigitsSum[L];
int numbersDigitsSumCopy[L];

int evenNumbers;

bool IsEven(int number) { return number % 2 == 0; }

int minSumOfDigits;
int maxSumOfDigits;

string increasingDigitsNumbers[L];

int CalculateSumOfDigits(string number)
{
    int sum = 0;
    for (int i = 0; i < number.length(); i++)
    {
        sum += number[i] - '0';
    }
    return sum;
}

bool AreDigitsIncreasing(string number)
{
    int t = 0;
    for (int i = 0; i < number.length(); i++)
    {
        if (number[i] - '0' > t)
        {
            t = number[i] - '0';
        }
        else 
        {
            return false;
        }
    }
    return true;
}

void BubbleSort()
{
    bool unsorted = true;
    int temp;
    while (unsorted) {
        unsorted = false;
        for (int i = 1; i < L; i++) {
            if (numbersDigitsSumCopy[i - 1] > numbersDigitsSumCopy[i]) {
                temp = numbersDigitsSumCopy[i];
                numbersDigitsSumCopy[i] = numbersDigitsSumCopy[i - 1];
                numbersDigitsSumCopy[i - 1] = temp;
                unsorted = true;
            }
        }
    }
}

int main()
{
    ifstream input;
    input.open("cyfry.txt");

    for (int i = 0; i < L; i++)
    {
        input >> numbers[i];
        numbersDigitsSum[i] = CalculateSumOfDigits(numbers[i]);
        numbersDigitsSumCopy[i] = CalculateSumOfDigits(numbers[i]);
    }
    for (int i = 0; i < L; i++)
    {
        if (IsEven(stoi(numbers[i]))) { evenNumbers++; }
        if (AreDigitsIncreasing(numbers[i])) {increasingDigitsNumbers[i] = numbers[i];}
    }
    BubbleSort();

    minSumOfDigits = numbersDigitsSumCopy[0];
    maxSumOfDigits = numbersDigitsSumCopy[L - 1];

    int minSumOfDigitsNumber = 0;
    int maxSumOfDigitsNumber = 0;

    for (int i = 0; i < L; i++)
    {
        if (numbersDigitsSum[i] == minSumOfDigits)
        {
            minSumOfDigitsNumber = stoi(numbers[i]);
        }
        if (numbersDigitsSum[i] == maxSumOfDigits)
        {
            maxSumOfDigitsNumber = stoi(numbers[i]);
        }
    }
  
    cout << "W pliku jest " << evenNumbers << " parzystych liczb" << endl;
    cout << "Liczba, ktorej suma cyfr jest najmniejsza to: " << minSumOfDigitsNumber << " z suma cyfr: " << minSumOfDigits << endl;
    cout << "Liczba, ktorej suma cyfr jest najwieksza to: " << maxSumOfDigitsNumber << " z suma cyfr: " << maxSumOfDigits << endl;
    cout << "Liczby, ktorych cyfry sa ustawione rosnaco: " << endl;
    for (int i = 0; i < L; i++)
    {
        if (increasingDigitsNumbers[i] != "")
        {
            cout << increasingDigitsNumbers[i] << endl;
        }
    }


}