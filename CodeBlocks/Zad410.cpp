#include <iostream>
#include <fstream>
using namespace std;

int numbers[1000];

int main()
{
    ifstream input;
    input.open("liczby_v4.txt");
    for(int i = 0; i < 1000; i++)
    {
        int t;
        cin >> t;
        numbers[i] = t;
    }

    int maxi = 0;
    for(int i = 0; i < 1000; i++)
    {
        if(numbers[i] % 2 == 0 && numbers[i] > maxi) {maxi = numbers[i];}

    }

    cout << maxi << endl;

}

