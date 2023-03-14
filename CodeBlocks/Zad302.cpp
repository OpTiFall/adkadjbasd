#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> points;

//int l;

void calculatePI(int nk, int n)
{
    double pi = (double)nk/(double)n;
    pi = round(pi*10000)/10000;
    cout << pi << endl;
}

void A()
{
    int w = 0;
    int b = 0;
    int r2 = 0;
    for(pair<int, int> p: points)
    {
        r2 = (p.first - 200)*(p.first - 200) +(p.second - 200)*(p.second - 200);
        if(r2 == 40000) {b++;}
        else if(r2 < 40000) {w++;}
    }
    cout << w << " "<< b << endl;
}

void B()
{
    int n = 0;
    int r2 = 0;
    int l = 1;
    for(pair<int, int> p: points)
    {
        r2 = (p.first - 200)*(p.first - 200) +(p.second - 200)*(p.second - 200);
        if(r2 <= 40000) {n++;}
        if(l == 1000) calculatePI(n, 1000);
        else if(l == 5000) calculatePI(n, 5000);
        l++;
    }
    calculatePI(n,10000);
}


void C()
{
    ofstream output("302output.txt");
    int r2 = 0;
    int l = 1;
    int n = 0;
    for(pair<int, int> p: points)
    {
        r2 = (p.first - 200)*(p.first - 200) +(p.second - 200)*(p.second - 200);
        if(r2 <= 40000) {n++;}
        double pi = 4.0*(double)n/(double)l;
        double w = abs(M_PI-pi);
        output << l << " " << n << endl;
        l++;
    }
    calculatePI(n,10000);
}

int main()
{
    ifstream plik("punkty.txt");
    int x, y;
    for(int i = 0; i < 10000;i++)
    {
        plik >> x >> y;

        points.push_back(make_pair(x, y));
    }

    A();
    B();
    C();

    return 0;
}
