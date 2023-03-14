#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int L = 1000;

long int numbers[L];

string toHex(long int number)
{
    string output;
    while (number > 16)
    {
        int s = number % 16;
        if (s >= 10) { s += 7; }
        char c = s + '0';
        output = c + output;
        number /= 16;
    }
    int s = number;
    if (s >= 10) { s += 7; }
    char c = s + '0';
    output = c + output;
    return output;
}

long int toDec(string number)
{
    long int a = 0;
    long int n = 1;
    int l = number.length();
    for(int i = 1; i < l+1; i++)
    {

        int t = number[l-i] -'0';
        if(t >= 17) { t-= 7;}
        a += t * n;
        n *= 16;
    }
    return a;
}

bool isPalindrom(string s)
{
    int l = s.length();
    for(int i = 0; i < l/2;i++)
    {
        if(s[i] != s[(l-1)-i]){return false;}
    }
    return true;
}

long int CalculateMaxNumber()
{
    long int t = numbers[0];
    for(int i = 1; i < L; i++)
    {
        if(numbers[i] > t)
        {
            t = numbers[i];
        }
    }
    return t;
}

long int CalculateMinNumber()
{
    long int t = numbers[0];
    for(int i = 1; i < L; i++)
    {
        if(numbers[i] < t)
        {
            t = numbers[i];
        }
    }
    return t;
}

int main()
{
    fstream input;
    input.open("pociagi.txt");
    long int p;
    cout << "Palindromy, które są palindormami i mają długość 8:  " << endl;
    for(int i = 0; i < L;i++)
    {
            string word;
            input >> word;

            bool t = isPalindrom(word);
           if(t) {p++;}

           if(word.length() == 8 && t)
            {
                cout << word << endl;
            }
            numbers[i] = toDec(word);

    }
    cout << "Ilość palindromów: " << p << endl;
    int min = CalculateMinNumber();
    long int max = CalculateMaxNumber();

    cout << "Min: " << min << " Hex: " << toHex(min) << endl;
    cout << "Max: " << max << " Hex: " << toHex(max) << endl;
}
