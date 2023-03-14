#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int b = 9;
    int *x = &a; //wskaźnik x pokazuje na a
    cout << "a = " << a <<  " b = " << b << " x = " << x <<
         " &a = " << &a << " *x = " << *x  << " &x = " << &x;
    cout << endl;
    a = b;
    cout << "a = " << a <<  " b = " << b << " x = " << x <<
         " &a = " << &a << " *x = " << *x ;
    cout << endl;
    int c = 2;
    const int *y = &c; //wskaźnik na stałą - nie można zmienić  c przez wskaźnik
    int* const z = &c; //stały wskaźnik, nie może pokazywać na nic innego;
    //*y = 6;  niemożliwe
    y = &a;
    //z = &a; niemożliwe
    *z = 7;
    int **w = &x;
    cout << "**w = "<< **w << endl;
    return 0;
}
