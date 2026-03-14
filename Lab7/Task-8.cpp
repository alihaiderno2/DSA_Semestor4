/*Ali Haider
Bitf24m004
Morning*/
#include <iostream>
using namespace std;
int countVowels(char *str, int length);
int main()
{
    char str[] = "Programming is fun!";
    cout << "COunt of Vowels in " << str << " is " << countVowels(str, 19) << endl;
    char str2[] = "Data Structures is important.";
    cout << "COunt of Vowels in " << str2 << " is " << countVowels(str2, 29) << endl;
    char str3[] = "And there is no bigger lie than a big lie.";
    cout << "COunt of Vowels in " << str3 << " is " << countVowels(str3, 42) << endl;
}
int countVowels(char *str, int length)
{
    if (length <= 0)
    {
        return 0;
    }
    else if (str[length - 1] == 'a' || str[length - 1] == 'e' || str[length - 1] == 'i' || str[length - 1] == 'o' || str[length - 1] == 'u' || str[length - 1] == 'A' || str[length - 1] == 'E' || str[length - 1] == 'I' || str[length - 1] == 'O' || str[length - 1] == 'U')
    {
        return 1 + countVowels(str, length - 1);
    }
    else
    {
        return countVowels(str, length - 1);
    }
}