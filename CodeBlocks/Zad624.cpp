#include <iostream>
using namespace std;

class Matrix
{
    public:
    Matrix():Matrix(2,1,3,7)
    {

    }
    Matrix(int x,int y, int z, int w)
    {
        matrix[0] = new int[2];
        matrix[1] = new int[2];
        matrix[0][0] = x;
        matrix[0][1] = y;
        matrix[1][0] = z;
        matrix[1][1] = w;
    }

    int** matrix;

    /*void Change(int x, int y, int z, int w)
    {
        matrix[0] = x;
        matrix[1] = y;
        matrix[2] = z;
        matrix[3] = w;
    }
    */
    int determinant() { return (matrix[0][0] * matrix[0][1]) - (matrix[1][0] * matrix[1][1]);}

    void print()
    {
        cout << matrix[0][0] << " " << matrix[0][1] << endl;
        cout << matrix[1][0] << " " << matrix[1][1] << endl;
    }
};

int main()
{
    Matrix matrix;
    matrix.print();
    cout << matrix.determinant() << endl;
}

