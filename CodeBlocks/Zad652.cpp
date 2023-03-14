#include <bits/stdc++.h>
using namespace std;

vector<string> strings;
map<string, int> quanity;

string shortest;
string longest;

vector<pair<string, int>> sorted;

string deleteVowels(string s)
{
    string result;
    for(char c: s)
    {
        if((int)c != 65 || (int)c != 69 || (int)c != 73 || (int)c != 79 || (int) c != 85 || (int)c != 89)
        {
            result.push_back(c);
        }
    }
    return result;
}

void CalculateQuantity(string s)
{
        if(quanity.count(s) == 0) {quanity.insert({s,0});}
        quanity[s]++;
}

bool compare(pair<string,int>& t1, pair<string,int>& t2)
{
    return t1.second > t2.second;
}

int main()
{
     ifstream plik("tekst2.txt");
     string t;
     while(plik >> t)
     {
        string check = deleteVowels(t);
        if(shortest.length() > check.length()) { shortest = check;}
        if(longest.length() < check.length()) { longest = check;}
        CalculateQuantity(t);
     }

     cout << shortest << endl;
     cout << longest << endl;

    for(auto& it : quanity)
    {
        sorted.push_back(it);
    }
    sort(sorted.begin(),sorted.end(),compare);
    int i = 0;
     for(auto iter = sorted.begin(); iter != sorted.end();iter++)
     {
        if(i < 10)
        {
        cout << (*iter).first << " " << (*iter).second << endl;
        i++;
        }
     }

}
