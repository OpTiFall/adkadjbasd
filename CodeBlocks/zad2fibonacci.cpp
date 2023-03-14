#include <iostream>
using namespace std;

int act;
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
    while(act < n)
    {
        i++;
        fibonacci(i);
        if(act == n)
        {
            cout << i;
            return 0;
        }
    }
    cout << "-1";
    return 0;
}
