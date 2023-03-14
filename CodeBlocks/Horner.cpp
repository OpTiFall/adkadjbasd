#include <iostream>
#include <fstream>
using namespace std;

struct Data
{
    int degreeOfPolynominal;
    long int* pCoefficients;

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
    int numberOfDatas;
    cin >> numberOfDatas;
    Data datas[numberOfDatas];
    for(int i = 0; i < numberOfDatas; i++)
    {
        int dp;
        cin >> dp;
        datas[i].degreeOfPolynominal = dp+1;
        datas[i].pCoefficients = new long int[dp+1];
        for(int j = 0; j < dp+1;j++)
        {
            cin >> datas[i].pCoefficients[j];
        }
        int na;
        cin >> na;
        for(int m = 0; m < na; m++)
        {
            int x;
            cin >> x;
            cout << datas[i].horner(x) << endl;
        }
    }
}



