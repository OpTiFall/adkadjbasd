#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int p;

int * coefficients;

double x1;
double x2;

double thisStupidThing(int p)
{
    if(x2 < x1)
    {
        double t = x2;
        x2 = x1;
        x1 = t;
    }

    double dx = abs(x1 - x2);
    double f1, f2, fs;
    double xs = (x1+x2)/2;
    while(dx > 0.001)
    {
        int tp = p;
        while(tp > 0)
        {
           f1 += pow(coefficients[tp],x1);
           tp--;
        }
        f1 += coefficients[0];
        tp = p;
        while(tp > 0)
        {
           f2 += pow(coefficients[tp],x2);
           tp--;
        }
        f2 += coefficients[0];
        tp = p;
        while(tp > 0)
        {
           fs+= pow(coefficients[tp],xs);
           tp--;
        }
        fs += coefficients[0];
        if(f1*fs < 0)
        {
            x2 = xs;
        }
        else
        {
            x1 = xs;
        }
        xs = (x1+x2)/2;
        dx = abs(x1 - x2);
    }
    return (x2+x1)/2;
}

int main()
{
    ifstream input("metoda_polowienia.txt");
    double f1;
    int m;
    input >> m;
  //  m = 1;
    for(int i = 0; i < m;i++)
    {
        input >> p;
        int t;
        int tp = p+1;
        delete[] coefficients;
        coefficients = new int[tp];
        while(tp >= 0)
        {
            input >> t;
            tp--;
            coefficients[tp] = t;
        }

        input >> x1;
        input >> x2;
        x1 = -x1;

        cout << thisStupidThing(p) << endl;

    }
    return 0;
}
