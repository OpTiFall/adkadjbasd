#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int main()
{
    double dollar = 3.97;
    double euro = 4.58;

    double zloty;
    cout << "Ile masz złotych?" << endl;
    cin >> zloty;

    cout << "W dollarach byś miał " << zloty / dollar << " $ , a w Euro " << zloty / euro << " Euro";

    return 0;
}
