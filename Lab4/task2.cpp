/*Name :Ali Haider
Roll Number : BITF24M004
Section : Morning*/
#include <iostream>
#include <fstream>
#include "PacketManager.h"
using namespace std;
int main()
{
    string nameOfFile;
    cout << "Enter the name of the input file: ";
    cin >> nameOfFile;
    ifstream fin;
    fin.open(nameOfFile);
    while (!fin)
    {
        cout << "ERROR: The file\"" << nameOfFile << "\" does not exist!!" << endl;
        cout << "Re-enter the input file name: ";
        cin >> nameOfFile;
        fin.open(nameOfFile);
    }
    PacketManager manager(fin);
    cout << "Packets originally read from the file are:" << endl;
    manager.displayPackets();
    manager.extractMessage();
    manager.displayMessage();
    fin.close();
}