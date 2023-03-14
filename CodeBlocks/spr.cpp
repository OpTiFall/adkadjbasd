#include <bits/stdc++.h>
using namespace std;

ifstream file;

vector<string> binary;

map<string, int> decimal;

vector<pair<string, int>> sorted;

map<string, int> quantity;

int toDecimal(string s)
{
    int l = s.length();
    int sum = 0;
    int n = 1;
    for (int i = 1; i <= l; i++)
    {
        int t = (s[l - i] - '0');
        if (t >= 49) { t -= 39; }
        sum += t * n;
        n *= 2;
    }
    return sum;
}


bool higest(pair<string,int> t1, pair<string,int> t2)
{
    return t1.second > t2.second;
}

bool lowest(pair<string,int> t1, pair<string,int> t2)
{
    return t1.second < t2.second;
}

void CalculateQuantity(string s)
{
    if(quantity.count(s) == 0) {quantity.insert({s,0});}
    quantity[s]++;
}

void A()
{
    cout << "A)" << endl;
    cout << "5 największych liczb:" << endl;
    int i = 0;
    for(auto it : decimal)
    {
        sorted.push_back(it);
    }
    sort(sorted.begin(),sorted.end(),higest);
    for(auto iter = sorted.begin(); iter != sorted.end();iter++)
     {
        if(i < 5)
        {
            cout << (*iter).second << " | Binary: " << (*iter).first << endl;
            i++;
        }
     }
     cout << endl;
     cout << "5 najmniejszych liczb:" << endl;
     i = 0;
     sort(sorted.begin(),sorted.end(),lowest);
     for(auto iter = sorted.begin(); iter != sorted.end();iter++)
     {
        if(i < 5)
        {
            cout << (*iter).second << " | Binary: " << (*iter).first << endl;
            i++;
        }
     }
}

void B()
{
    cout << "B)" << endl;
    sorted.erase(sorted.begin(),sorted.end());
    cout << "10 najwięcej występujących wyrazów:" << endl;
    for(auto it : quantity)
    {
        sorted.push_back(it);
    }
    sort(sorted.begin(),sorted.end(),higest);
    int i = 0;
    for(auto iter = sorted.begin(); iter != sorted.end();iter++)
     {
        if(i < 10)
        {
            cout << (*iter).first << " | Ilość wystąpień: " << (*iter).second << endl;
            i++;
        }
     }
}

int main()
{
    file.open("zero_jedynki.txt");

    for(int i = 0; i < 2000; i++)
    {
        string t;
        file >> t;
        binary.push_back(t);
        CalculateQuantity(t);
    }

    for(string s: binary)
    {
        if(decimal.count(s) == 0){decimal.insert({s,0});}
        decimal[s] = toDecimal(s);
    }

    A();
    cout << endl;
    B();

    return 0;
}
