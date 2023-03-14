#include <iostream>
#include <fstream>
#include <cctype>
#include<string>
using namespace std;

const int L = 1877;

const int A = 26;

string words[L];

int alphabet[A];

int twoSameLettersNextToEachOther;

int amountOfLetters;

bool hasTwoSameLettersNextToEachOther(string word)
{
    char t = word[0];
    for (int i = 1; i < word.length(); i++)
    {
        if (t == word[i])
        {
            return true;
        }
        else
        {
            t = word[i];
        }
    }
    return false;
}


int main()
{
    
    ifstream input;
    input.open("tekst.txt");
    
    for (int i = 0; i < L; i++)
    {
        input >> words[i];
    }
    
    for (int i = 0; i < L; i++)
    {
        if (hasTwoSameLettersNextToEachOther(words[i]))
        {
            twoSameLettersNextToEachOther++;
        }

        for (char c : words[i])
        {
            amountOfLetters++;
            c = tolower(c);
            alphabet[c - 'a']++;
        }
        
    }

    cout << "Ilosc slow z dwoma takimi samymi literami obok siebie: " << twoSameLettersNextToEachOther << endl;
    for (int i = 0; i < A; i++)
    {
        int t = i + 'A';
        char s = t;
        float percent = ((float)alphabet[i] / amountOfLetters) * 100;
        cout.precision(3);
        cout << s << ": " << alphabet[i] << " (" << percent << "% " << ")" << endl;
    }
   
}

