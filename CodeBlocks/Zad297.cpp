#include <iostream>
#include <fstream>
using namespace std;

const int L = 2000;

int numbers[L];

int primalNumbers;
int primals[L];
int primalsCopy[L];

int twinNumbersA[L];
int twinNumbersB[L];

int twinNumbersActualIndex;

bool isPrimal(int a)
{
    if (a == 0 || a == 1) { return false; }
    for (int i = 2; i <= a / 2; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}

void bubbleSort()
{
    bool unsorted = true;
    int temp;
    while (unsorted) {
        unsorted = false;
        for (int i = 1; i < L; i++) {
            if (primalsCopy[i - 1] > primalsCopy[i]) {
                temp = primalsCopy[i];
                primalsCopy[i] = primalsCopy[i - 1];
                primalsCopy[i - 1] = temp;
                unsorted = true;
            }
        }
    }
}

int main()
{
    ifstream input;
    input.open("dane_6.txt");

    for (int i = 0; i < L; i++)
    {
        input >> numbers[i];
    }


    for (int i = 0; i < L; i++)
    {
        if (isPrimal(numbers[i])) { primalNumbers++; primals[i] = numbers[i]; }
    }

    cout << "Ilość liczb pierwszych: " << primalNumbers << endl;

    for (int i = 0; i < L; i++) { primalsCopy[i] = primals[i]; }

    bubbleSort();
    bool isChosen = false;

    for (int i = 0; i < L && !isChosen; i++)
    {
        if (primalsCopy[i] >= 2)
        {
            cout << "Najmniejsza liczba pierwsza: " << primalsCopy[i] << endl;
            isChosen = true;
        }
    }

    cout << "Największa liczba pierwsza: " << primalsCopy[L - 1] << endl;

    for (int i = 0; i < L - 1; i++)
    {
        if (primals[i] != 0 || primals[i + 1] != 0)
        {
            int t = primals[i] - primals[i + 1];
            if (t == 2 || t == -2)
            {
                twinNumbersA[twinNumbersActualIndex] = primals[i];
                twinNumbersB[twinNumbersActualIndex] = primals[i + 1];
                twinNumbersActualIndex++;
            }
        }
    }

    for (int i = 0; i < twinNumbersActualIndex; i++)
    {
        cout << twinNumbersA[i] << " i " << twinNumbersB[i] << endl;
    }
}
