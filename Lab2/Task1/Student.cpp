#include "Student.h"
#include <iostream>
using namespace std;
Student::Student()
{
    rollNo = 0;
    name[0] = '\0';
    noofQuizzes = 0;
    marks = nullptr;
    totalMarks = nullptr;
}
Student::Student(int r, const char *n, int q)
{
    rollNo = r;
    for (int i = 0; i < name_size - 1 && n[i] != '\0'; i++)
    {
        name[i] = n[i];
    }
    name[name_size - 1] = '\0';
    noofQuizzes = q;
    marks = new int[noofQuizzes];
    totalMarks = new int[noofQuizzes];
    for (int i = 0; i < noofQuizzes; i++)
    {
        marks[i] = 0;
        totalMarks[i] = 0;
    }
}
Student::~Student()
{
    if (marks != nullptr)
    {
        delete[] marks;
        marks = nullptr;
    }
    if (totalMarks != nullptr)
    {
        delete[] totalMarks;
        totalMarks = nullptr;
    }
}
void Student::getInputFromUser()
{
    cout << "Enter Roll Number: ";
    cin >> rollNo;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(name, name_size);
    cout << "Enter number of quizzes: ";
    cin >> noofQuizzes;
    if (marks != nullptr)
    {
        delete[] marks;
        marks = nullptr;
    }
    if (totalMarks != nullptr)
    {
        delete[] totalMarks;
        totalMarks = nullptr;
    }
    marks = new int[noofQuizzes];
    totalMarks = new int[noofQuizzes];
    inputMarks();
}
void Student::inputMarks()
{
    for (int i = 0; i < noofQuizzes; i++)
    {
        cout << "Enter total marks for quiz " << i + 1 << ": ";
        int total;
        cin >> total;
        if (total < 0)
        {
            cout << "Total marks cannot be negative. Please enter again." << endl;
            i--;
        }
        else
        {
            totalMarks[i] = total;
            cout << "Enter marks obtained in quiz " << i + 1 << ": ";
            int mark;
            cin >> mark;
            if (mark < 0 || mark > total)
            {
                cout << "Marks obtained cannot be negative or greater than total marks. Please enter again." << endl;
                i--;
            }
            else
            {
                marks[i] = mark;
            }
        }
    }
}
void Student::display() const
{
    cout << "Roll Number: " << rollNo << endl;
    cout << "Name: " << name << endl;
    cout << "Number of Quizzes: " << noofQuizzes << endl;
    float maxPerc = -1.0, minPerc = 101.0;
    for (int i = 0; i < noofQuizzes; i++)
    {
        cout << "Quiz " << i + 1 << ": " << marks[i] << "/" << totalMarks[i] << endl;
        float perc = ((float)marks[i] / totalMarks[i]) * 100;
        if (perc > maxPerc)
        {
            maxPerc = perc;
        }
        if (perc < minPerc)
        {
            minPerc = perc;
        }
    }
    if (noofQuizzes > 0)
    {
        cout << "Highest Percentage: " << maxPerc << "%" << endl;
        cout << "Lowest Percentage: " << minPerc << "%" << endl;
    }
}
Student::Student(const Student &s)
{
    rollNo = s.rollNo;
    for (int i = 0; i < name_size; i++)
    {
        name[i] = s.name[i];
    }
    noofQuizzes = s.noofQuizzes;
    marks = new int[noofQuizzes];
    totalMarks = new int[noofQuizzes];
    for (int i = 0; i < noofQuizzes; i++)
    {
        marks[i] = s.marks[i];
        totalMarks[i] = s.totalMarks[i];
    }
}
void Student::storeInFile(ofstream &out) const
{
    out << rollNo << endl;
    out << name << endl;
    out << noofQuizzes << endl;
    for (int i = 0; i < noofQuizzes; i++)
    {
        out << marks[i] << " " << totalMarks[i] << endl;
    }
}
void Student::readFromFile(ifstream &in)
{
    in >> rollNo;
    in.ignore();
    in.getline(name, name_size);
    in >> noofQuizzes;
    if (marks != nullptr)
    {
        delete[] marks;
        marks = nullptr;
    }
    if (totalMarks != nullptr)
    {
        delete[] totalMarks;
        totalMarks = nullptr;
    }
    marks = new int[noofQuizzes];
    totalMarks = new int[noofQuizzes];
    for (int i = 0; i < noofQuizzes; i++)
    {
        in >> marks[i] >> totalMarks[i];
    }
}
Student &Student::operator=(Student &s2)
{
    if (this == &s2)
    {
        return *this;
    }
    if (marks != nullptr)
    {
        delete[] marks;
        marks = nullptr;
    }
    if (totalMarks != nullptr)
    {
        delete[] totalMarks;
        totalMarks = nullptr;
    }
    rollNo = s2.rollNo;
    for (int i = 0; i < name_size - 1 && s2.name[i] != '\0'; i++)
    {
        name[i] = s2.name[i];
    }
    name[name_size - 1] = '\0';
    noofQuizzes = s2.noofQuizzes;
    marks = new int[noofQuizzes];
    totalMarks = new int[noofQuizzes];
    for (int i = 0; i < noofQuizzes; i++)
    {
        marks[i] = s2.marks[i];
        totalMarks[i] = s2.totalMarks[i];
    }
    return *this;
}
void printStudent(const Student s)
{
    s.display();
}