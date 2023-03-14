#include <bits/stdc++.h>
using namespace std;

ifstream file;

struct Galeria
{
    string country;
    string city;
    vector<int> premises;
    void print()
    {
        cout << country << " " << city << " " << premises.size() << endl;
    }
};

vector<Galeria> galerie;

void A()
{
    map<string, int> mapa;
    for(Galeria g : galerie) {mapa[g.country]++;}
    for(pair<string, int> p : mapa)
    {
        cout << p.first << " " << p.second << endl;
    }
}

int main()
{

    //file.open("galerie.txt");
    int a,b;
    char check = 'c';
  //  file >> check;
    cout << check;
    for(int i = 0; i < 50; i++)
    {
        Galeria g;
        file >> g.country >> g.city;
        for(int j = 0; j < 70; i++)
        {
        //    file >> a >> b;
            if(a > b) {g.premises.push_back(a*b);}
        }

    }
   // A();

    return 0;
}
