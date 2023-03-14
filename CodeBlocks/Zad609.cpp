#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <locale>
using namespace std;

struct prime
{
    string imie;
    string nazwisko;
    int klasa;
    char oddzial;

    void print()
    {
        cout << imie << " " << nazwisko << " " << klasa << " " << oddzial << endl;
    }
};

bool compare(prime u1, prime u2)
{
    if(u1.nazwisko == u2.nazwisko) { return u1.imie < u2.imie; }
    else return u1.nazwisko < u2.nazwisko;
}

vector<prime> uczniowie;

void sprawdzNazwisko()
    {
        cout << "Podaj naziwsko: ";
        string s;
        cin >> s;
        s = tolower(s);
        for(prime u: uczniowie)
        {
            if(tolower(u.nazwisko) == s) {u.print();}
        }
    }

int main()
{
     ifstream file("szablony_uczniowie.txt");
     for(int i = 0; i < 225; i++)
     {
         prime uczen;
         file >> uczen.nazwisko >> uczen.imie >> uczen.klasa >> uczen.oddzial;
         uczniowie.push_back(uczen);
     }
   //  sprawdzNazwisko();
     sort(uczniowie.begin(),uczniowie.end(),compare);

     return 0;
}

