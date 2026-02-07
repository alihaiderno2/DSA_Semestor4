#pragma once
const int name_size = 40;
#include <fstream>
using namespace std;
class Student
{
private:
    int rollNo;
    char name[name_size];
    int noofQuizzes;
    int *marks;
    int *totalMarks;
    void inputMarks();

public:
    Student();
    Student(int, const char *, int);
    ~Student();
    void getInputFromUser();
    void display() const;
    Student(const Student &s);
    void storeInFile(ofstream &) const;
    void readFromFile(ifstream &);
    Student &operator=(Student &s2);
};