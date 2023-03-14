#include <iostream>
using namespace std;

int convertToArabic(char z)
{
    switch(z)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
        }
}

int calculateNumber(string z)
{
    bool s = false;
    int lastNumber = convertToArabic(z[z.size()-1]);
    int output = convertToArabic(z[z.size()-1]);
    for(int i = z.size()-2;i > -1;i--)
    {
        if(lastNumber < convertToArabic(z[i]))
        {
            output += convertToArabic(z[i]);
            lastNumber = convertToArabic(z[i]);
            s = false;
        }
        else if (lastNumber == convertToArabic(z[i]))
        {
            if(s)
            {
                output -= convertToArabic(z[i]);
                lastNumber = convertToArabic(z[i]);
            }
            if(!s)
            {
                output += convertToArabic(z[i]);
                lastNumber = convertToArabic(z[i]);
            }
        }
        else if(lastNumber > convertToArabic(z[i]))
        {
            output = lastNumber - convertToArabic(z[i]);
            lastNumber = convertToArabic(z[i]);
            s = true;
        }

    }
    return output;
}

int main()
{
    string f;
    string s;
    cin >> f >> s;
    int a1 = calculateNumber(f);
    int a2 = calculateNumber(s);
    cout << a1 + a2 << endl;
    return 0;
}
