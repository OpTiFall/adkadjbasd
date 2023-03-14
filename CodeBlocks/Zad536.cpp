#include <iostream>
#include <fstream>
using namespace std;

int factorial(int a)
{
    if(a < 2) {return a;}
    else return a * factorial(a - 1);
}

int main()
{
    cout << "Podaj n i k: " << endl;
    int n,k;
    cin >> n >> k;
    float denominator = (factorial(k) * factorial(n-k));
    cout << factorial(n) / denominator << endl;
}
