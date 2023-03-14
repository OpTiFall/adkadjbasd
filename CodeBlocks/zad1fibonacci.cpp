#include <iostream>
using namespace std;

int tribonacci(int n)
{
    int prev_1 = 0;
    int prev_2 = 0;
    int prev_3 = 1;
    int act = 0;
    for(int i = 1; i < n; i++)
    {
        act = prev_1 + prev_2 + prev_3;
        prev_1 = prev_2;
        prev_2 = prev_3;
        prev_3 = act;
    }
    return act;
}

int main()
{
    int n;
    cin >> n;
    cout << tribonacci(n) << endl;
    return 0;
}
