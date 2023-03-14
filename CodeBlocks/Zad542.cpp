#include <iostream>
using namespace std;
int main()
{
    int liczba = 22;
    int* wskaznik = &liczba;

    cout << "adres zmiennej=" << &liczba << endl;
    cout << "adres wskaźnika=" << &wskaznik << endl;
    cout << "wartość wskaźnika=" << *wskaznik << endl;
    cout << "liczba=" << liczba << endl;
    *wskaznik = 20;
    cout << "liczba=" << liczba << endl;
    return 0;
}
