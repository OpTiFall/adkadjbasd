#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

string letters[1000];

int chars[6];

bool sorting_v2(char a, char b)
{
    return (int)a < (int)b;
}

bool CheckForRepeatedLetters(string s)
{
    char c[s.length()];
    for(int i = 0; i < s.length(); i++) {c[i] = s[i];}
    sort(c,c+s.length(),sorting_v2);
    string com;
    for(int i = 0; i < s.length();i++){com += c[i];}
    if(com != "ABCDEF") {return true;}
    return false;
}

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

unsigned long int toDec(string number, int system)
{
    unsigned long int s = 0;
    unsigned long int n = 1;
    for(int i = number.length()-1; i >= 0; i--)
    {
        s = s + (number[i] -'7') * n;
        n *= system;
    }
    return s;

}

bool sorting(string letters1, string letters2)
{
    return toDec(letters1,16) > toDec(letters2,16);
}
int main()
{
    ifstream input;
    input.open("ciagi.txt");

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

    sort(letters,letters+1000,sorting);

    cout << "Majwiększa liczba: "<< toDec(letters[999],16) << " - " << letters[999] << endl;
    cout << "Najmnijesza liczba: " << toDec(letters[0],16) << " - " << letters[0] << endl;

    cout << endl;

    cout << "Pięc pierwszych napisów pososrtowanych leksykograficznie: "  << endl;
    for( int i = 0; i< 5; i++) {cout << letters[i] << endl;}
    cout << "Pięć ostatnich: " << endl;
    for( int i = 995; i < 1000; i++) {cout << letters[i] << endl;}

    int dOutput;
    for(int i = 0; i < 1000; i++)
    {
        if(!CheckForRepeatedLetters(letters[i])){dOutput++;}
    }

    cout << "D: " << dOutput << endl;
}

