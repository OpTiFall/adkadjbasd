#include <iostream>
using namespace std;

bool isAnalim(string word1, string word2)
{
    if(word1.length() != word2.length())
    {
        return false;
    }
    int index = word1.length() - 1;
    for(int i = 0; i < index; i++)
    {
        if(word1[i] != word2[index - i])
        {
            return false;
        }
    }
    return true;
}

bool isPalindrom(string word)
{
    int mirrored = 0;
    if(word.length() % 2 != 0)
    {
        mirrored = (word.length()/2)-1;
    }
    else
    {
        mirrored = word.length()/2;
    }
    for(int i = 0; i < mirrored; i++)
    {
        if(word[i] != word[(word.length()-1)- i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string f;
    string s;
    cin >> f >> s;
    cout << isAnalim(f,s) << endl;
    cout << isPalindrom(f);
}

