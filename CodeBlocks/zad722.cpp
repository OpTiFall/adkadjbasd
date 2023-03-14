#include <iostream>
#include <fstream>
using namespace std;

const int L = 101;

int lastNumber;

char lastOperation = '+';

int CalculateNumber(string number, int system)
{
    long int a = 0;
    int n = 1;
    int l = number.length();
    for(int i = 1; i < l+1; i++)
    {

        int t = number[l-i] -'0';
        if(t >= 17) { t-= 7;}
        a += t * n;
        n *= system;
    }
    return a;
}

int main()
{
    fstream input;
    input.open("dzialania.txt");
    for(int i = 1; i < L+1;i++)
    {
        if(i % 2 == 1)
        {
            string number;
            int s;
            input >> number;
            input >> s;
            switch (lastOperation)
            {
            case '+':
                lastNumber += CalculateNumber(number,s);
                break;
            case '-':
                lastNumber -= CalculateNumber(number,s);
                break;
            case '*':
                lastNumber *= CalculateNumber(number,s);
                break;
            case '%':
                lastNumber = lastNumber % CalculateNumber(number,s);
                break;
            }

        }
        if(i % 2 == 0)
        {
            input >> lastOperation;
        }
    }

    cout << lastNumber;
}
