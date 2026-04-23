/* ALi Haider
BITF24M004
Morning
*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
const int NAME_LENGTH = 25;
// The structure to store the bowling figures
struct BowlingFigures
{
    char name[NAME_LENGTH + 1];
    int wickets;
    int runs;
};
// Function Headers
BowlingFigures *readFromFile(char *fileName, int &count);
void printBowlingFigures(const BowlingFigures *bf, int count);
void sortBowlingFigures1(BowlingFigures *bf, int count);
void sortBowlingFigures2(BowlingFigures *bf, int count);
void sortByName(BowlingFigures *bf, int count);
// Main function
int main()
{
    int count, choice = 0;
    char fileName[100] = "";
    cout << "Enter the name of the input file: ";
    cin.getline(fileName, 100);
    BowlingFigures *bowlingStats = readFromFile(fileName, count);
    if (bowlingStats == NULL)
    {
        // If file doesn't contain the right data or file can't be opened
        cout << "Error opening file or invalid data." << endl;
        return 0;
    }
    cout << endl
         << setw(25) << "--------" << endl;
    cout << setw(23) << "MENU" << endl;
    cout << setw(25) << "--------" << endl;
    do
    {
        // Menu driven inputs
        cout << "1. Sort BowlingFigures using Insertion sort " << endl;
        cout << "2. Sort BowlingFigures using Selection sort" << endl;
        cout << "3. Sort BowlingFigures by Name (using Bubble sort) " << endl;
        cout << "4. Quit " << endl;
        cout << endl
             << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            sortBowlingFigures1(bowlingStats, count);
        }
        else if (choice == 2)
        {
            sortBowlingFigures2(bowlingStats, count);
        }
        else if (choice == 3)
        {
            sortByName(bowlingStats, count);
        }
    } while (choice != 4);
    // Freeing the space acquired
    delete[] bowlingStats;
    return 0;
}
// File reading function
BowlingFigures *readFromFile(char *fileName, int &count)
{
    ifstream fin;
    fin.open(fileName);
    if (!fin)
    {
        return NULL;
    }
    fin >> count;
    // if invalid count
    if (count <= 0)
    {
        return NULL;
    }
    // dynamically allocating the array for the bowling figures
    BowlingFigures *figures = new BowlingFigures[count];
    for (int i = 0; i < count; i++)
    {
        fin.ignore();
        // ignoring the \n character after reading through fin >>
        fin.getline(figures[i].name, NAME_LENGTH + 1);
        fin >> figures[i].wickets;
        fin >> figures[i].runs;
    }
    cout << "Following " << count << " Bowling figures were read from the input file:" << endl;
    printBowlingFigures(figures, count);
    fin.close();
    return figures;
}
// Simply printing the records
void printBowlingFigures(const BowlingFigures *bf, int count)
{
    cout << "\n\n";
    for (int i = 0; i < count; i++)
    {
        cout << setw(25) << bf[i].name << "  " << bf[i].wickets << "-" << bf[i].runs << endl;
    }
    cout << "\n\n";
}
// Sorting using insertion Sort
void sortBowlingFigures1(BowlingFigures *bf, int count)
{
    cout << endl
         << "The " << count << " Bowling figures after sorting by Insertion Sort are : " << endl;
    for (int i = 1; i < count; i++)
    {
        BowlingFigures temp = bf[i];
        int j = i - 1;
        // only moving forward if the wickets are greater or wickets are equal but runs are less
        while (j >= 0 && (temp.wickets > bf[j].wickets || (temp.wickets == bf[j].wickets && temp.runs < bf[j].runs)))
        {
            bf[j + 1] = bf[j];
            j--;
        }
        bf[j + 1] = temp;
    }
    printBowlingFigures(bf, count);
}
// Sorting using selection sort
void sortBowlingFigures2(BowlingFigures *bf, int count)
{
    cout << endl
         << "The " << count << " Bowling figures after sorting by Selection Sort are : " << endl;
    for (int i = 0; i < count - 1; i++)
    {
        int max = i;
        for (int j = i + 1; j < count; j++)
        {
            // only considering max if the wickets are greater
            if (bf[max].wickets <= bf[j].wickets)
            {
                // if wickets are equal then only only making the max if the runs are less
                if (bf[max].wickets == bf[j].wickets)
                {
                    if (bf[max].runs > bf[j].runs)
                    {
                        max = j;
                    }
                }
                else
                {
                    max = j;
                }
            }
        }
        BowlingFigures temp = bf[i];
        bf[i] = bf[max];
        bf[max] = temp;
    }
    printBowlingFigures(bf, count);
}
// Using bubble sort to sort by name
void sortByName(BowlingFigures *bf, int count)
{
    cout << endl
         << "The " << count << " Bowling figures sorted by name are : " << endl;
    for (int i = count - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            // using strcmp to compare the names and sorting in increasing order
            if (strcmp(bf[j].name, bf[j + 1].name) > 0)
            {
                BowlingFigures temp = bf[j + 1];
                bf[j + 1] = bf[j];
                bf[j] = temp;
            }
        }
    }
    printBowlingFigures(bf, count);
}