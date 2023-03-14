/*
Treść zadania
1. Wczytaj całe zdanie
2. Wypisz co drugą literę (nieparzystą, czyli od pierwszej litery) zdania
*/

#include <iostream>
#include <string>
using namespace std;

void printLetters(string s)
{
    for(int i = 0; i < s.length(); i = i + 2)
    {
        cout << s[i];
    }
}

int main()
{
    string s;
    getline(cin, s);
    printLetters(s);
}

