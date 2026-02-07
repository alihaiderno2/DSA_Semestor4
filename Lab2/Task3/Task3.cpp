#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    int n;
    ifstream in("phrases.txt");
    in >> n;
    in.ignore();
    if (n > 0)
    {
        int longest = -1, shortest = -1, longestSize = INT_MIN, shortestSize = INT_MAX;
        string *s = new string[n];
        for (int i = 0; i < n; i++)
        {
            getline(in, s[i]);
            cout << s[i] << endl;
            if (int(s[i].size()) > longestSize)
            {
                longestSize = s[i].size();
                longest = i;
            }
            if (int(s[i].size()) < shortestSize)
            {
                shortestSize = s[i].size();
                shortest = i;
            }
        }
        cout << "The input file contains " << n << " phrases" << endl;
        if (longest != -1)
        {
            cout << "Longest Phrase: " << endl;
            cout << s[longest] << "(" << "length: " << longestSize << ")" << endl;
            cout << "Shortest Phrase: " << endl;
            cout << s[shortest] << "(" << "length: " << shortestSize << ")" << endl;
        }
        delete[] s;
    }
}