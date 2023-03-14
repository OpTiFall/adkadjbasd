#include <iostream>
using namespace std;

union RGBData
{
    unsigned int R;
    unsigned int G;
    unsigned int B;
};

int ToDec(string s)
{
    int l = s.length();
    int sum = 0;
    int n = 1;
    for (int i = 1; i <= l; i++)
    {
        int t = (s[l - i] - '0');
        if (t >= 49) { t -= 39; }
        sum += t * n;
        n *= 8;
    }
    return sum;
}

int main()
{
    cout << "Wpisz liczbe RGB: " << endl;
    string t;
    cin >> t;
    cout << "rgb(";
    RGBData rgb;
    string t2;
    t2 += t[1];
    t2 += t[2];
    rgb.R = ToDec(t2);
    cout << rgb.R << ", ";
    string t3;
    t3 += t[3];
    t3 += t[4];
    rgb.G = ToDec(t3);
    cout << rgb.G << ", ";
    string t4;
    t4 += t[5];
    t4 += t[6];
    rgb.B = ToDec(t4);
    cout << rgb.R << ")";
}
