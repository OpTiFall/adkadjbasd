#include <iostream>
#include <fstream>
using namespace std;

string compress(string s)
{
        char lc = s[0];
        int numberOfLetters = 1;
        string output;
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
                if(numberOfLetters > 2)
                {
                    output += lc;
                    output += to_string(numberOfLetters);
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

string *outputs;

int main()
{
    int n;
    cin >> n;
    outputs = new string[n];
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        outputs[i] = compress(s);
    }
    for(int i = 0; i < n; i++)
    {
        cout << outputs[i] << endl;
    }

}

