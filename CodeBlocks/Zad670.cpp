#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;

string f;
struct Letters
{
    char c;
    int n;
    string b;
};

Letters letters[12];

bool sorting(Letters l1, Letters l2)
{
    return l1.n < l2.n;
}

bool sorting_v2(Letters l1, Letters l2)
{
    return l1.c < l2.c;
}

void print()
{
    for(int i = 0; i < 12; i++)
    {
        cout << letters[i].c << ": " << letters[i].n  << " Binary: " << letters[i].b << endl;
    }
}
string toBin(int n, int d)
{
    string t;
    while(n > 0)
    {
        t = to_string(n % 2) + t;
        n /= 2;
    }
    while(t.size() < d) t ='0'+t;
    return t;
}
int main()
{
    string f;
    ifstream input;
    input.open("formula.txt");

    input >> f;

    for(int i = 0; i < 12; i++)
    {
        letters[i].c = (char)('A' + i);
    }
    for(char c : f)
    {
        letters[c - 'A'].n++;
    }

    sort(letters,letters+12,sorting);


    for(int i = 0; i < 12; i++)
    {
        letters[i].b = toBin(i,3);
    }
    for(int i = 4; i < 12; i++)
    {
        letters[i].b = '1'+toBin(i-4,3);
    }

     print();
     sort(letters,letters+12,sorting_v2);
     string code;
     for(char l : f)
     {
        code += letters[l-'A'].b;
     }

     ofstream output("Zad670_Output.txt");
     output << code << endl;

     cout << "f size: " << f.size() << " encoded: " << ceil(code.size()/8.0) << endl;
     cout << "Compression rate: " << f.size() /(code.size()/8.0) << endl;

}
