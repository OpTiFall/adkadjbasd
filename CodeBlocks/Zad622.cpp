#include <iostream>
using namespace std;

struct Matrix
{

    Matrix():Matrix(2,1,3,7)
    { }

    Matrix(int x,int y, int z, int w)
    {
        matrix[0] = new int[2];
        matrix[1] = new int[2];
        matrix[0][0] = x;
        matrix[0][1] = y;
        matrix[1][0] = z;
        matrix[1][1] = w;
        xMax = 2;
        yMax = 2;
    }

    Matrix(int x, int y)
    {
        xMax = x;
        yMax = y;
        matrix = new int*[y];
        for(int i = 0; i < y; i++)
        {
            matrix[i] = new int[x];
        }
    }

    int xMax;
    int yMax;
    int** matrix;

    void Change(int x, int y, int value)
    {
        matrix[y][x] = value;
    }

    int GetValue(int x,int y) { return matrix[y][x];}

    int determinant() { return (matrix[0][0] * matrix[0][1]) - (matrix[1][0] * matrix[1][1]);}

    void print()
    {
        for(int i = 0; i < xMax; i++)
        {
            for(int j = 0; j < yMax; j++)
            {
                cout << matrix[j][i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x;
        cin >> y;
        Matrix matrix(x, y);
        for(int j = 0; j < y; j++)
        {
            for(int k = 0; k < x; k++)
            {
                int value;
                cin >> value;
                matrix.Change(k,j, value);
            }
        }
        Matrix output(x,y);
        output.Change(0,0,matrix.GetValue(1,0));
       // output.Change(2,0,matrix.GetValue(2,1));
        for(int i = 1; i < x-1; i++)
        {
            output.Change(0,i,matrix.GetValue(i+1,0));
        }
        for(int i = 0; i < y-1; i++)
        {
            output.Change(i,x-1,matrix.GetValue(x-1,i+1));
        }
        for(int i = x-1; i > 0;i--)
        {
            output.Change(y-1,i,matrix.GetValue(i-1,y-1));
        }
        for(int i = 1; i < y; i++)
        {
            output.Change(i,0,matrix.GetValue(0,i-1));
        }
        /*for(int i = 1; i < x-2; i++)
        {
            for(int j = 1; j < y-2; j++)
            {
                output.Change(i,j,matrix.GetValue(i,j));
            }
        }
        */



        output.print();
    }
}
