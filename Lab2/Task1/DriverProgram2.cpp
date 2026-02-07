#include <iostream>
#include <fstream>
#include "Student.h"
#include "Student.cpp"
using namespace std;
int main()
{
    int n;
    ifstream in("Students.txt");
    in >> n;
    if (n > 0)
    {
        Student *students = new Student[n];
        for (int i = 0; i < n; i++)
        {
            students[i].readFromFile(in);
            students[i].display();
        }
        delete[] students;
    }
}