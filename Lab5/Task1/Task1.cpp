/*Name :Ali Haider
Roll Number : BITF24M004
Section : Morning*/
#include <iostream>
#include "Stack.h"
#include "Stack.cpp"
using namespace std;
void addingLargeNumbers(char *number1, char *number2)
{
    int size1 = 0, size2 = 0;
    int i = 0;
    while (number1[i] != '\0')
    {
        size1++;
        i++;
    }
    i = 0;
    while (number2[i] != '\0')
    {
        size2++;
        i++;
    }
    int resultSize = 0;
    if (size1 > size2)
    {
        resultSize = size1 + 1;
    }
    else
    {
        resultSize = size2 + 1;
    }
    // Initializing stacks
    Stack stack1(size1), stack2(size2), resultStack(resultSize);
    for (int j = 0; j < size1; j++)
    {
        stack1.push(number1[j] - '0');
    }
    for (int j = 0; j < size2; j++)
    {
        stack2.push(number2[j] - '0');
    }
    int carry = 0;
    while (!stack1.isEmpty() && !stack2.isEmpty())
    {
        int firstDigit = 0, secondDigit = 0;
        stack1.pop(firstDigit);
        stack2.pop(secondDigit);
        carry = carry + firstDigit + secondDigit;
        resultStack.push(carry % 10);
        carry /= 10;
    }
    while (!stack1.isEmpty())
    {
        int digit = 0;
        stack1.pop(digit);
        carry = carry + digit;
        resultStack.push(carry % 10);
        carry /= 10;
    }
    while (!stack2.isEmpty())
    {
        int digit = 0;
        stack2.pop(digit);
        carry = carry + digit;
        resultStack.push(carry % 10);
        carry /= 10;
    }
    if (carry != 0)
    {
        resultStack.push(carry);
    }
    cout<<"Sum of two numbers is ";
    while (!resultStack.isEmpty())
    {
        int ans = 0;
        resultStack.pop(ans);
        cout << ans;
    }
}
int main()
{
    char num1[41];
    char num2[41];
    char *result;
    cout << "Enter the 1st number" << endl;
    cin >> num1;
    cout << "Enter the 2nd number" << endl;
    cin >> num2;
    addingLargeNumbers(num1, num2);
}