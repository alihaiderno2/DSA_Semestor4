#include <iostream>
#include <fstream>
#include "Student.h"
#include "Student.cpp"
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of students:" << endl;
    cin >> n;
    if (n > 0)
    {
        Student *students = new Student[n];
        ofstream out("Students.txt", ios::app);
        out << n << endl;
        for (int i = 0; i < n; i++)
        {
            students[i].getInputFromUser();
            students[i].storeInFile(out);
        }
        delete[] students;
    }
}