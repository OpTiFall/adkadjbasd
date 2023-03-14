#include <iostream>
#include <string>
using namespace std;

int amountOfChars(string s, string letter)
{
    int amount = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == letter[0])
        {
            amount++;
        }
    }

    return amount;
}

int main()
{
    string s;
    string l;
    getline(cin, s);
    getline(cin, l);
    cout << amountOfChars(s, l);
}

