#include <iostream>
#include <fstream>
using namespace std;

const int L = 1000;

string strings[L];

int sumOfAs;
int everySumOfASCIIs;

int ASCIIPrimalNumbers;

bool isPrimal(int a)
{
    if(a == 0 || a == 1) {return false;}
    for(int i = 2; i < a/2;i++)
    {
        if(a % i == 0)
        {
            return false;
        }
    }
    return true;
}

int CalculateNumberOfAs(string s)
{
    int amountOFAs = 0;
    for(char c : s)
    {
        if(c == 'a') {amountOFAs++;}
    }
    return amountOFAs;
}

int CalculateSumOfASCII(string s)
{
    int sumOfASCIIs = 0;
    for(char c : s)
    {
        int n = c;
        sumOfASCIIs += n;
    }
    return sumOfASCIIs;
}


bool isPalindrom(string s)
{
    int l = s.length()-1;
    if(l+1 <= 2){return false;}
    for(int i = 0; i < l+1/2; i++)
    {
        if(s[i] != s[l-i]) { return false;}
    }
    return true;
}
int main()
{
    ifstream input;
    input.open("stringi.txt");

    for(int i = 0; i < L; i++)
    {
        input >> strings[i];
        sumOfAs += CalculateNumberOfAs(strings[i]);
        int ASCII = CalculateSumOfASCII(strings[i]);
        everySumOfASCIIs += ASCII;
        if(isPrimal(ASCII)) {ASCIIPrimalNumbers++;}
    }

    cout << "A) Ilość liter a w całym pliku: " << sumOfAs << endl;
    cout << "B) Suma wszytskich kodów ASCII wynosi: " << everySumOfASCIIs  << endl;
    cout << "A liczba wszytskich sum kodów ASCII stringa, które były liczbą pierwszą wynosi: " << ASCIIPrimalNumbers << endl;

    cout << "Wszytskie palindormy w pliku: " << endl;
    for(int i = 0; i < L; i++)
    {
        if(isPalindrom(strings[i])) { cout << strings[i] << endl;}
    }
}
