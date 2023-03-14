
#include <iostream>
#include <fstream>
using namespace std;

const int L = 200;

long int sum;

struct Data
{
    int degreeOfPolynominal;
    long double* pCoefficients;

    double horner(double x)
    {
        long double y = pCoefficients[0];
        for(int i = 1; i < degreeOfPolynominal; i++)
        {
            y = y*x + pCoefficients[i];
        }
        return y;
    }
};


int main()
{
    ifstream input;
    input.open("wielomiany.txt");
    Data datas[L];
    for(int i = 0; i < L; i++)
    {
        int dp;
        input >> dp;
        datas[i].degreeOfPolynominal = dp+1;
        datas[i].pCoefficients = new long double[dp+1];
        for(int j = 0; j < dp+1;j++)
        {
            input >> datas[i].pCoefficients[j];
        }
        double x;
        input >> x;
        sum += datas[i].horner(x);
    }
    cout << sum;
}
