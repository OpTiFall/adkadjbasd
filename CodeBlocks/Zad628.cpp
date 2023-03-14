#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
using namespace std;

struct Rzymskie
{
    int value;
    Rzymskie(int number)
    {
        value = number;
    }
    Rzymskie(string s)
    {
        value = toNumber(s);
    }
    string toRzymskie(int number)
    {
        string rz;
        string chars[13] = {"M","CM", "D", "CD", "C" , "XC", "L", "XL", "X","IX", "V", "IV", "I"};
        int values[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        for(int i = 0; i < 13;i++)
        {
            while(number >= values[i])
            {
                rz += chars[i];
                number -= values[i];
            }
        }
        return rz;
    }
    int toNumber(string s)
    {
        int number = 0;
        int next = 0;
        for(int i = 0;i < s.size(); i++)
        {
            value = charValue(s[i]);
            if(i < s.size()-1 && charValue(s[i+1]) > value) { number -= value;}
            else{ number += value;}
        }
        return number;
    }

    int charValue(char c)
    {
        switch(c)
        {
            case 'M': return 1000;
            case 'D': return 500;
            case 'C': return 100;
            case 'L': return 50;
            case 'X': return 10;
            case 'V': return 5;
            case 'I': return 1;
            default: return 0;
        }
    }

};

int main()
{
    string s1, s2;
    while(cin >> s1 >> s2)
    {
        Rzymskie first(s1);
        Rzymskie second(s2);
        int output = first.value + second.value;
        cout << first.toRzymskie(output) << endl;
    }
    return 0;
}
