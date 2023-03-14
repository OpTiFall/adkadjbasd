#include <iostream>
#include <fstream>
using namespace std;

long int DecToBinary(long int a)
{
    if(a <= 1) {return a;}
    else return a % 2 + DecToBinary(a/2)*10;
}

int main()
{
    cout << "Podaj liczbę: " << endl;
    int n;
    cin >> n;
    cout << DecToBinary(n);
}
