#include <iostream>
#include <fstream>
using namespace std;

const int L = 500;

int numbers[L];

int output[L];

bool isPrimal(int a)
{
    if (a == 0 || a == 1) { return false; }
    for (int i = 2; i <= a / 2; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ifstream input;

    input.open("liczby.txt");

    for (int i = 0; i < L; i++)
    {
        input >> numbers[i];
    }
    
    for (int i = 0; i < L; i++)
    {
        int t = sqrt(numbers[i]);
        if (isPrimal(t))
        {
            output[i] = numbers[i];
        }
    }
    for (int i = 0; i < L; i++)
    {
        if (output[i] != 0)
        {
            cout << output[i] << endl;
        }
    }
}
