#include <iostream>
#include <fstream>
using namespace std;

int moreThan5Digits;

int maxMultiplication;
int maxMultiplicationNumber;

int multiplicationOfDigits(int number)
{
    if(number < 10){return number;}
    return number % 10 * multiplicationOfDigits(number/10);
}

int main()
{
    ifstream input;
    input.open("liczby_v3.txt");

    for(int i = 0;i < 1000; i++)
    {
        int t;
        input >> t;
        if(t >= 100000){moreThan5Digits++;}
        int multiplication = multiplicationOfDigits(t);
        if(multiplication >= maxMultiplication)
        {
            maxMultiplication = multiplication;
            maxMultiplicationNumber = t;
        }
    }

    cout << "Ilość liczb, które mają więcej niż 5 cyfr: " << moreThan5Digits << endl;

    cout << "Liczba o największym iloczynie cyfr: " << maxMultiplicationNumber << endl;
    cout << "Iloczyn jej cyfr wynosi: " << maxMultiplication << endl;
}
