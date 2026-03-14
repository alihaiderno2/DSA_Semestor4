/*Ali Haider
Bitf24m004
Morning*/
#include <iostream>
using namespace std;
int sumDigits(int num);
int main()
{
    cout << "The sum of the digits is " << sumDigits(357) << endl;
    cout << "The sum of the digits is " << sumDigits(-123) << endl;
    cout << "The sum of the digits is " << sumDigits(0) << endl;
}
int sumDigits(int num)
{
    if (num < 0)
    {
        return sumDigits(-num);
    }
    else if (num == 0)
    {
        return 0;
    }
    else
    {
        return num % 10 + sumDigits(num / 10);
    }
}