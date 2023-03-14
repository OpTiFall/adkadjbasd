#include <iostream>
#include <fstream>
using namespace std;

int L = 1000;

long int l;

long int a;

int main()
{
    ifstream input;
    input.open("duze_liczby.txt");
    for (int i = 0; i < L; i++)
    {
        long long unsigned n;
        input >> n;
        a += n / 1000;
        l += n % 1000;
        if (l >= 1000)
        {
            a += 1;
            l -= 1000;
        }
    }

    cout << a << " " << l << "/1000" << endl;
}

