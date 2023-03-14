#include <iostream>
#include <string>
using namespace std;

int amountOfWords(string s)
{
    if(s.length() == 0){return 0;}

    int words = 1;
    bool space = false;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] != ' ' && s[i] != '\t' && s[i] != '\n'){space = false;}
        if(s[i] == ' ' && !space)
        {
            words++;
            space = true;
        }
    }

    return words;
}

int main()
{
    string s;
    getline(cin, s);
    cout << amountOfWords(s);
}
