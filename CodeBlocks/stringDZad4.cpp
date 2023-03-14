#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int znaki[26];

int letters[26];

bool isAnalim(string f, string s)
{
    if(f.size() != s.size())
    {
        cout << "Nie są to anagramy (długość jest inna)" << endl;
        return false;
    }

    for(int i = 0; i < f.size(); i++)
    {
        int n = f[i] - 'a';
        letters[n]++;

        n = s[i] - 'a';
        letters[n]--;
    }

    for(int i = 0; i < 26; i++)
    {
        if(letters[i] != 0)
        {
            cout << "Nie są anagrami (litery są różne)" << endl;
            return false;
        }
    }
    return true;
}

bool isAnalim2(string f, string s)
{
    if(f.size() != s.size())
    {
        cout << "Nie są to anagramy (długość jest inna)" << endl;
        return false;
    }
    sort(f.begin(),f.end());
    sort(s.begin(),s.end());

    for(int i = 0; i < f.size(); i++)
    {
        if(f[i] != s[i])
        {
            cout << "Nie są anagrami (litery są różne)" << endl;
            return false;
        }
    }
    return true;
}

int main()
{
    string f;
    string s;
    cin >> f >> s;
    if(isAnalim2(f, s)){cout << "Słowa są anagrami";}
}
