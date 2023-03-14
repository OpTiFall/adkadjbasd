#include <iostream>
#include <fstream>
using namespace std;

string letters[1000];

bool IsPalindrom(string s)
{
    int l = s.length();
    for(int i = 0; i < l/2;i++)
    {
        if(s[i] != s[(l-1)-i]) {return false;}

    }
    return true;
}
int numberOfPalindroms;

unsigned long long int toDec(string number, int system)
{
    unsigned long long int s = 0;
    int n = 1;
    for(int i = number.length()-1; i >= 0; i--)
    {
       // cout << number[i] << endl;
        cout << number[i] << (number[i] -'7') << endl;
        s = s + (number[i] -'7') * n;
        n *= system;
    }
    return s;

}
int main()
{
    ifstream input;
    input.open("ciagi.txt");

    cout << IsPalindrom("DDDD") << endl;
    for(int i = 0; i < 1000; i++)
    {

        string c;
        input >> c;
        letters[i] = c;
        if(IsPalindrom(c))
        {
            numberOfPalindroms++;
            if(c.length() == 8)
            {
                cout << c << endl;
            }
        }
    }
    cout << "Ilość wszystkich palindromów: " << numberOfPalindroms << endl;
    cout << toDec() << endl;
    for(int i = 0; i < 1000; i++)
    {
        cout << toDec(letters[i],16) << endl;
    }
}

