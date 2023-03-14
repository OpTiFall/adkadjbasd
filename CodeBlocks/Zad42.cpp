#include <iostream>
#include <fstream>
using namespace std;

const int L = 42;

int numbers[L] = {2, 3, 5, 6, 7, 9, 12, 13, 14, 15, 17, 18, 19, 23, 24, 26, 27, 28, 34, 35, 38, 42, 43, 45, 48, 52, 53, 54, 56, 59, 61, 65, 66, 67, 70, 73, 74, 75, 77, 78, 92, 99};

int binarySearch(int t[],const int n,const int searched)
{
    int a = 0; int b = n-1;
    int c;
    while(a < b)
    {
        c = (a + b)/2;
        if(t[c] == searched) {return c;}
        if(t[c] > searched)
        {
            b = c-1;
        }
        else {a = c+1;}
    }
    if(t[a] == searched) {return a;}
    if(t[a] - searched > -(t[a-1] - searched))
    {
        return a-1;
    }
    else return a;
}

int main()
{
    cout << "Podaj szukaną liczbę: " << endl;
    int number;
    cin >> number;
    cout << numbers[binarySearch(numbers,L, number)];
}
