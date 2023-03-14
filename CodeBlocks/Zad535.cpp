#include <iostream>
#include <fstream>
using namespace std;

long int sumOfDigits(long int a)
{
    if(a < 10) {return a;}
    else return sumOfDigits(a / 10) + (a % 10);
}

int main()
{
    cout << "Podaj liczbę: " << endl;
    int n;
    cin >> n;
    cout << sumOfDigits(n);
}
