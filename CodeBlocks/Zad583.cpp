#include <iostream>
#include <fstream>
using namespace std;

int fastpow(int x, int n)
{
    int w = 1;
    while(n > 0)
    {
        if(n % 2 == 1) {w *= x;}
        x = (x%10)*(x%10);
        n /= 2;
        w = w % 10;
    }

    return w;
}

int main()
{
    int h;
    cin >> h;
    for(int i = 0;i < h; i++)
    {
        int a,b;
        cin >> a;
        cin >> b;
        cout << fastpow(a,b) << endl;
    }
}



