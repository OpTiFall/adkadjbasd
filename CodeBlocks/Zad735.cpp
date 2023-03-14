#include <bits/stdc++.h>
using namespace std;

vector<pair<double, int>> points;

int calculateArea(int NO, double lambda)
{
    int belongs;
    for(pair<double, int> p: points)
    {
        long double N = NO*exp(-lambda*p.first);
        if(N >= p.second) {belongs++;}
    }
    return belongs*200;
}


int main()
{
    ifstream plik("punkty_losowe.txt");
    double t; int N;
    for(int i = 0; i < 10000;i++)
    {
        plik >> t >> N;
        points.push_back(make_pair(t, N));
    }
    plik.close();
    ifstream plik2("exponent_monte_carlo.txt");
    double P = 200000.0;
    double lambda; int NO;
    long int sum = 0;
    long int tmp = 0;
    for(int i = 0; i < 100; i++)
    {
        plik2 >> NO >> lambda;
        tmp = calculateArea(NO, lambda);
        cout << tmp << endl;
        sum += tmp;
    }

    cout << sum << endl;

    return 0;
}
