#include <iostream>
#include <fstream>
using namespace std;

string compress(string s)
{
        char lc = s[0];
        int numberOfLetters = 1;
        string output;
        s += '/';
        for(int i = 1; i < s.length(); i++)
        {
            char c = s[i];

            if(c == lc)
            {
                numberOfLetters++;
            }
            else
            {
                string t;
                if(numberOfLetters > 3)
                {
                    output += lc;
                    output += '*';
                    output += to_string(numberOfLetters);
                    numberOfLetters = 1;
                }
                else if(numberOfLetters == 3)
                {
                    output += lc;
                    output += lc;
                    output += lc;
                    numberOfLetters = 1;
                }
                else if(numberOfLetters == 2)
                {
                    output += lc;
                    output += lc;
                    numberOfLetters = 1;
                }
                else if(numberOfLetters == 1 && lc != ' ')
                {
                    output += lc;
                    numberOfLetters = 1;
                }
                lc = c;
            }

        }
        return output;
}

string decompress()
{

}

int main()
{
    string n;
    cin >> n;

    if(n == "KOMPRESJA")
    {
        string outputs[1000];
        int i = 0;
        while(i < 1000)
        {
            string s;
            cin >> s;
            outputs[i] = compress(s);
            i++;
        }
        for(int i = 0; i < 1000; i++)
        {
             cout << outputs[i] << endl;
        }
        string ls = outputs[0];
        int numberOfWords = 1;
        for(int i = 1; i < 1000; i++)
        {
            string s = outputs[i];

            if(s == ls)
            {
                numberOfWords++;
                cout << " adding" << endl;
            }
            else
            {
                if(numberOfWords > 1)
                {
                    cout << ls << '/' << to_string(numberOfWords);
                }
                else if(numberOfWords == 1)
                {
                    cout << ls;
                    numberOfWords = 1;
                }
                ls = s;
            }
        }
    }
    else
    {

    }

}
