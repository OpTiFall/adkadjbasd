#include <iostream>
#include <fstream>
using namespace std;

int fastpow(int x, int n)
{
    if(n == 0){return 1;}
    if(n % 2 == 1) { return x * fastpow(x,n-1);}
    else
    {
        int a = fastpow(x,n/2);
        return a * a;
    }
}

int main()
{
    cout << "Podaj podstawę i wykładnik potęgi: " << endl;
    int x, n;
    cin >> x >> n;
    cout << "Wynik potęgowania wynosi: " << fastpow(x,n);
}


