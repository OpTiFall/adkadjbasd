#include <iostream>
using namespace std;

int act;
const int nominals[] = {200,100,50,5,2,1};
int fibonacci(int n)
{
    int prev_1 = 0;
    int prev_2 = 1;
    act = 0;
    for(int i = 1; i < n; i++)
    {
        act = prev_1 + prev_2;
        prev_1 = prev_2;
        prev_2 = act;
    }
    return act;
}

int main()
{
    int n;
    cin >> n;
    int i = 0;
    while(n != 0)
    {
            for(int i = 0 ; i < nominals.size(); i++)
        {
            n -= nominals[i] * div(n,nominals[i]);
            cout << div(n,nominals[i]) + " x " + nominals[i];
        }
    }
    cout << "-1";
    return 0;
}

