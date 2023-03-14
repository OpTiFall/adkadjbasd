#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{

    ifstream input;
    input.open("input.txt");
    ofstream output;
    output.open("output.txt");
    int n = 0;
    input >> n;
    string bs;
    getline(input,bs);
    for(int i = 0; i < n; i++)
    {
        string h;
        getline(input,h);
        int hours = (h[0] - '0') * 10 + (h[1] - '0');
        int minutes = (h[3] - '0') * 10 + (h[4] - '0');

        int minutesRev = (h[1] - '0') * 10 + (h[0] - '0');
        if(hours != 0 && minutes != 0)
        {
            if(minutesRev < minutes && (hours < 16 || hours >= 20))
            {
                if(hours < 23)
                {
                    hours++;
                    minutesRev += 10;
                }
                else
                {
                    hours = 0;
                    minutes = 0;
                }
            }
            if(hours >= 16)
            {
                hours = 20;
                minutes = 02;
            }
        }
        else
        {
            hours == 0;
            minutes == 1;
        }

        output << hours << ":" << minutesRev << endl;
        cout << hours << ":" << minutesRev << endl;
    }
}

