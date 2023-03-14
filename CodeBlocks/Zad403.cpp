#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

string pesels[1000];

int wPesels;
int mPesels;

int bornInNovember = 0;

bool isWomen(string pesel)
{
     int t = pesel[9] - '0';
     return t % 2 == 0;
}

bool isBornInNovember(string pesel)
{
    string t = pesel.substr(2,2);
    return t == "09" || t == "29";
}

bool isValid(string pesel)
{
    if(pesel.length() != 11) {return false;}
    int t = 0;
    for(int i = 0; i < 10; i++)
    {
        int multiplier;
        if(i % 4 == 0){multiplier = 1;}
        else if(i % 4 == 1){multiplier = 3;}
        else if(i % 4 == 2){multiplier = 7;}
        else if(i % 4 == 3){multiplier = 9;}
        t += (pesel[i] -'0') * multiplier;
    }
    t += pesel[10]- '0';
    if(t % 10 == 0) {return true;}
    return false;
}

int main()
{
    ifstream input;
    input.open("dane.txt");
    for(int i = 0; i < 1000; i++)
    {
        long int t;
        input >> t;
        pesels[i] = to_string(t);
    }
    cout << "C: " << endl;
    for(int i = 0; i < 1000; i++)
    {
       if(isWomen(pesels[i])){wPesels++;}
       else{mPesels++;}
       if(isBornInNovember(pesels[i])){bornInNovember++;}
      if(!isValid(pesels[i]) && pesels[i].length() == 11) {cout << pesels[i] << endl;}

    }
    cout << "A: Kobiet - " << wPesels << ", Mężczyzn - " << mPesels << endl;
    cout << "B: " << bornInNovember << endl;
}


