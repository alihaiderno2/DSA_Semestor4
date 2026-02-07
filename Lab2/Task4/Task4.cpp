#include <iostream>
using namespace std;
int **oneDToTwoD(int *, int, int, int);
int main()
{
    int n;
    cout << "Enter the number of elements for one D array";
    cin >> n;
    int *p = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    int r, c;
    cout << "Enter the number of rows";
    cin >> r;
    cout << "Enter the amount of colums for 2D array conversion";
    cin >> c;
    int **twoD = oneDToTwoD(p, r, c, n);
    if (twoD == nullptr)
    {
        cout << "The conversion could not happen" << endl;
    }
    else
    {
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << twoD[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < r; i++)
        {
            delete[] twoD[i];
        }
        delete[] twoD;
        twoD = nullptr;
    }
    delete[] p;
}
int **oneDToTwoD(int *p, int r, int c, int n)
{
    if (r < 0 || c < 0)
    {
        cout << "Conversion is not possible" << endl;
        return nullptr;
    }
    if (n != r * c)
    {
        return nullptr;
    }
    int **pointerToTwoD = new int *[r];
    for (int i = 0; i < r; i++)
    {
        pointerToTwoD[i] = new int[c];
    }
    int k = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            pointerToTwoD[i][j] = p[k];
            k++;
        }
    }
    return pointerToTwoD;
}