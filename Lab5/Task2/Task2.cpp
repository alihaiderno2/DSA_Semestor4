/*Name :Ali Haider
Roll Number : BITF24M004
Section : Morning*/
#include <iostream>
#include <fstream>
// KSVVW BGSJD SVSIS VXBMN YQUUK BNWCU ANMJS
using namespace std;
struct LetterInfo
{
    char letter;
    int freq;
};
int main()
{
    ifstream fin("input.txt");
    if (!fin)
    {
        cout << "ERror Loading file" << endl;
        return 0;
    }
    char ch;
    LetterInfo informationFromFile[26];
    for (int i = 0; i < 26; i++)
    {
        informationFromFile[i].letter = 'A' + i;
        informationFromFile[i].freq = 0;
    }
    while (fin >> ch)
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            if (ch >= 'a' && ch <= 'z')
            {
                ch -= 32;
            }
            int index = ch - 'A';
            informationFromFile[index].freq++;
        }
    }
    for (int i = 1; i < 26; i++)
    {
        int j = i - 1;
        int val = informationFromFile[i].freq;
        LetterInfo temp = informationFromFile[i];
        while (j >= 0 && val > informationFromFile[j].freq)
        {
            informationFromFile[j + 1] = informationFromFile[j];
            j--;
        }
        informationFromFile[j + 1] = temp;
    }
    for (int i = 0; i < 26; i++)
    {
        cout << informationFromFile[i].letter << " has freq = " << informationFromFile[i].freq << endl;
    }
}