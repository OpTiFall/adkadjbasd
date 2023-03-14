#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int rising;
int nwd;
int sumOfDigitsEqualTo35;

int sumOfRowDigits;

struct Numbers
{
    int number[3];
    bool isRising()
    {
        if(number[0] < number[1] && number[1] < number[2]){return true;}
        return false;
    }
    int NWD()
    {
        return NWDR(NWDR(number[0],number[1]),number[2]);
    }
    int NWDR(int a, int b)
    {
        int c;
        while(true)
        {
            c = a % b;
            if(c == 0) {return b;}
            a = b;
            b = c;
        }
        return 0;
    }
    int sumOfDigits()
    {
        return sumOfDigitsR(number[0],10) + sumOfDigitsR(number[1],10) + sumOfDigitsR(number[2],10);
    }
    int sumOfDigitsR(int n, int w)
    {
        if(w/10 > n)
        {
            return 0;
        }
        return n % w + sumOfDigitsR(n - (n % w),w*10)/10;
    }

    bool isSumOfDigitsEqualTo35()
    {
        return sumOfDigits() == 35;
    }

};

Numbers numbers[1000];

int main()
{
    ifstream input;
    input.open("liczby_v2.txt");
    for(int i = 0; i < 1000; i++)
    {
        input >> numbers[i].number[0];
        input >> numbers[i].number[1];
        input >> numbers[i].number[2];
    }
    int lSumOfRowDigits = 0;
    for(int i = 0; i < 1000; i++)
    {
        if(numbers[i].isRising()){rising++;}
        nwd += numbers[i].NWD();
        if(numbers[i].isSumOfDigitsEqualTo35()) {sumOfDigitsEqualTo35++;}
        if(numbers[i].sumOfDigits() == lSumOfRowDigits)
        {
            sumOfRowDigits++;
        }
        else if(numbers[i].sumOfDigits() > lSumOfRowDigits)
        {
            lSumOfRowDigits = numbers[i].sumOfDigits();
            sumOfRowDigits = 1;
        }

    }
    cout << "Liczba wierszy uporządkowanych rosnąco: " << rising << endl;
    cout << "Suma NWD wszystkich wierszy wynosi: " << nwd << endl;
    cout << "Liczba wierszy, których suma cyfr wynosi 35: " << sumOfDigitsEqualTo35 << endl;
    cout << "Największa suma cyfr w wierszu: " << lSumOfRowDigits << endl;
    cout << "Liczba wierszy o tej sumie cyfr: " << sumOfRowDigits << endl;

}


