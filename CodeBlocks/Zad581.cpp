#include <iostream>
#include <fstream>
using namespace std;

struct Address
{
    int buildingNumber;
    int addressNumber[20];
    void print()
    {
        cout << "Bulilding Number: " << buildingNumber << endl;
       for(int i = 0; i < 20; i++)
        {
            cout << addressNumber[i] << " ";
        }
        cout << endl;
    }
};

int numbers[1000];

int notFoundNumbers;
int notFoundAddresses;

int binarySearch(int t[],const int n,const int searched)
{
    int a = 0; int b = n-1;
    int c;
    while(a < b)
    {
        c = (a + b)/2;
        if(t[c] == searched) {return c;}
        if(t[c] > searched)
        {
            b = c-1;
        }
        else {a = c+1;}
    }
    if(t[a] == searched) {return a;}
    return -1;
}


int main()
{
    Address addresses[1000];
    ifstream input;
    input.open("adresy.txt");

    for(int i = 0; i < 1000; i++)
    {
        input >> addresses[i].buildingNumber >> numbers[i];
        for(int j = 0; j < 20; j++)
        {
            input >> addresses[i].addressNumber[j];

        }
    }
    ifstream input2;
    input2.open("przesylki.txt");
    for(int i = 0; i < 1000; i++)
    {
        int searchedNumber;
        input2 >> searchedNumber;
        int found = binarySearch(numbers, 1000, searchedNumber);
        if(found == -1)
        {
            notFoundNumbers++;
        }
        else
        {

            for(int j = 0; j < 20; j++)
            {
                int searchedAddress;
                input >> searchedAddress;
                if(binarySearch(addresses[found].addressNumber,20,searchedAddress) == -1)
                {
                    notFoundAddresses++;
                }
            }
        }

    }
    cout << "Not Found Numbers: " << notFoundNumbers << endl;
    cout << "Not Found Addresses: " << notFoundAddresses << endl;
}
