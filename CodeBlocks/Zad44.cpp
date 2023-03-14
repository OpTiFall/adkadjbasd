#include <fstream>
#include <iostream>
using namespace std;

const int L = 200;

float CalculateAverage(int payouts[12])
{
    return (payouts[0] + payouts[1] + payouts[2] + payouts[3] + payouts[4] + payouts[5] + payouts[6] + payouts[7] + payouts[8] + payouts[9] + payouts[10] + payouts[11]) / 12;
}

struct Worker
{
    string name;
    string surname;
    long int pesel;
    int payouts[12];
    void print()
    {
        cout << "Imię: " << name << endl;
        cout << "Nazwisko: " << surname << endl;
        cout << "PESEL: " << pesel << endl;
        cout << "Średnia wysokość wynagrodzenia: " << CalculateAverage(payouts) << endl;
    }
    int sumOfPayouts()
    {
        return payouts[0] + payouts[1] + payouts[2] + payouts[3] + payouts[4] + payouts[5] + payouts[6] + payouts[7] + payouts[8]  + payouts[9] + payouts[10] + payouts[11];
    }
};

Worker workers[L];



void print()
{
    for(int i = 0;i < L;i++)
    {
        cout << "Pracownik nr: " << i+1 << endl;
        workers[i].print();
    }
}

void findMax()
{
    int t = workers[0].sumOfPayouts();
    int w = 0;
    for(int i = 1;i < L; i++)
    {
        if(t < workers[i].sumOfPayouts())
        {
            t = workers[i].sumOfPayouts();
            w = i;
        }
    }
    cout << endl;
    cout << "Nr najlepiej zarabiającego pracownika w firmie:  " << w+1 << endl;
    workers[w].print();
}

int main()
{
    ifstream input;
    input.open("pracownicy.txt");
    for(int i = 0;i < 200; i++)
    {
        input >> workers[i].surname >> workers[i].name >> workers[i].pesel;
        int j = 0;
        while(j < 12)
        {
            input >> workers[i].payouts[j];
            j++;
        }
    }


    print();

    findMax();
}
