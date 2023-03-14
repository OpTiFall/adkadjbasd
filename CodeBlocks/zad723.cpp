#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int L = 40;

long long int number;

string CalculateChar()
{
    string output;
    while (number > 36)
    {
        int s = number % 36;
        if (s >= 10) { s += 7; }
        char c = s + '0';
        output = c + output;
        number /= 36;
    }
    int s = number;
    if (s >= 10) { s += 7; }
    char c = s + '0';
    output = c + output;
    return output;
}

int main()
{
    fstream input;
    input.open("ukryty_napis.txt");
    for (int i = 0; i < L; i++)
    {
        input >> number;
        string t = CalculateChar();
        cout << t << " ";
    }
}
