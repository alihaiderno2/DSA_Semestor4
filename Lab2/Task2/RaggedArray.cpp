#include <iostream>
using namespace std;
int **createPascalTriangle(int n);
void displayPascalTriangle(int **pt, int n);
void deallocatePascalTriangle(int **&pt, int n);
int main()
{
    int n;
    cout << "Enter the size of pascal triangle:" << endl;
    cin >> n;
    int **pt = createPascalTriangle(n);
    displayPascalTriangle(pt, n);
    deallocatePascalTriangle(pt, n);
}
int **createPascalTriangle(int n)
{
    if (n <= 0)
    {
        return nullptr;
    }
    int **raggedArray = new int *[n];
    for (int i = 0; i < n; i++)
    {
        raggedArray[i] = new int[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                raggedArray[i][j] = 1;
            }
            else if (j == i)
            {
                raggedArray[i][j] = 1;
            }
            else
            {
                raggedArray[i][j] = raggedArray[i - 1][j] + raggedArray[i - 1][j - 1];
            }
        }
    }
    return raggedArray;
}
void displayPascalTriangle(int **pt, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << pt[i][j] << " ";
        }
        cout << endl;
    }
}
void deallocatePascalTriangle(int **&pt, int n)
{
    if (pt == nullptr)
    {
        return;
    }
    for (int i = 0; i < n; i++)
    {
        delete[] pt[i];
    }
    delete[] pt;
    pt = nullptr;
}