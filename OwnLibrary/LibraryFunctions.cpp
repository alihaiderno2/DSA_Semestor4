#include "LibraryFunctions.h"
#include "Stack.h"
#include "StackChar.h"
#include "StackString.h"
#include <iostream>
using namespace std;
int LibraryFunctions::logBase2(int num)
{
    if (num <= 0)
    {
        return -1;
    }
    else if (num == 1)
    {
        return 0;
    }
    int i = 0;
    int powers = 2;
    while (powers <= num)
    {
        powers *= 2;
        i++;
    }
    return i;
}
void LibraryFunctions::intSwap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void LibraryFunctions::bubbleSort(int *a, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[j + 1])
            {
                intSwap(a[j], a[j + 1]);
            }
        }
    }
}
void LibraryFunctions::bubbleSortReverse(int *a, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[j + 1])
            {
                intSwap(a[j], a[j + 1]);
            }
        }
    }
}
void LibraryFunctions::selectionSort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        intSwap(a[i], a[min]);
    }
}
void LibraryFunctions::selectionSortReverse(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int max = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[max])
            {
                max = j;
            }
        }
        intSwap(a[i], a[max]);
    }
}
void LibraryFunctions::insertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int val = a[i];
        while (j >= 0 && val < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = val;
    }
}
void LibraryFunctions::insertionSortReverse(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int val = a[i];
        while (j >= 0 && a[j] < val)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = val;
    }
}
void LibraryFunctions::selectionSortByFindMax(int *a, int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int max = i;
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[j] > a[max])
            {
                max = j;
            }
        }
        intSwap(a[i], a[max]);
    }
}
void LibraryFunctions::decimalToBinaryConversion(int num)
{
    Stack s(logBase2(num) + 1);
    while (num > 0)
    {
        s.push(num % 2);
        num /= 2;
    }
    while (!s.isEmpty())
    {
        int value;
        s.pop(value);
        cout << value;
    }
}
int LibraryFunctions::evaluationOfPostfixExpression(const char *exp)
{
    StackChar s(100);
    int i = 0;
    while (exp[i] != '\0')
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            s.push(exp[i]);
        }
        else
        {
            if (exp[i] == '+')
            {
                char a, b;
                s.pop(b);
                s.pop(a);
                s.push(int(a) + int(b));
            }
            else if (exp[i] == '-')
            {
                char a, b;
                s.pop(b);
                s.pop(a);
                s.push(int(a) - int(b));
            }
            else if (exp[i] == '*')
            {
                char a, b;
                s.pop(b);
                s.pop(a);
                s.push(int(a) * int(b));
            }
            else if (exp[i] == '/')
            {
                char a, b;
                s.pop(b);
                s.pop(a);
                s.push(int(a) / int(b));
            }
        }
        i++;
    }
    char result;
    s.pop(result);
    return int(result);
}
string LibraryFunctions::infixToPostfix(string infix)
{
    string postfix = "";
    StackString operands(100);
    for (int i = 0; infix[i] != '\0'; i++)
    {
        string ch = "";
        ch += infix[i];
        if ((ch >= "a" && ch <= "z") || (ch >= "A" && ch <= "Z") || (ch >= "0" && ch <= "9"))
        {
            postfix += ch;
        }
        else if (ch == "(")
        {
            operands.push(ch);
        }
        else if (ch == ")")
        {
            string top;
            while (!operands.isEmpty() && (operands.topVal(top) && top != "("))
            {
                postfix += top;
                operands.pop(top);
            }
            if (!operands.isEmpty())
            {
                operands.pop(top);
            }
        }
        else
        {
            string op = "";
            op += ch;
            if (i + 1 < infix.length())
            {
                char next = infix[i + 1];
                if ((ch == "<" || ch == ">" || ch == "=" || ch == "!" || ch == "+" || ch == "-" || ch == "&" || ch == "|") && (next == '=' || next == '&' || next == '|' || next == '+' || next == '-'))
                {

                    string combined = op + next;
                    if (combined == "<=" || combined == ">=" || combined == "==" || combined == "!=" ||
                        combined == "&&" || combined == "||" || combined == "++" || combined == "--")
                    {
                        op = combined;
                        i++;
                    }
                }
            }
            string top;
            while (!operands.isEmpty() && (operands.topVal(top) && top != "(" && getPrecedence(top) <= getPrecedence(op)))
            {
                postfix += top;
                operands.pop(top);
            }
            operands.push(op);
        }
    }
    while (!operands.isEmpty())
    {
        string top;
        operands.pop(top);
        postfix += top;
    }
    return postfix;
}
int LibraryFunctions::getPrecedence(string op)
{

    if (op == "~" || op == "!" || op == "++" || op == "--")
    {
        return 1;
    }
    else if (op == "*" || op == "/" || op == "%")
    {
        return 2;
    }
    else if (op == "+" || op == "-")
    {
        return 3;
    }
    else if (op == ">" || op == "<" || op == ">=" || op == "<=")
    {
        return 4;
    }
    else if (op == "==" || op == "!=")
    {
        return 5;
    }
    else if (op == "&&")
    {
        return 6;
    }
    else if (op == "||")
    {
        return 7;
    }
    else
    {
        return 8;
    }
}
void LibraryFunctions::merge(int *arr, int l1, int l2, int r1, int r2)
{
    int size = r2 - l1 + 1;
    int *temp = new int[size];
    int i = l1, j = r1;
    int k = 0;
    while (i <= l2 && j <= r2)
    {
        if (arr[j] < arr[i])
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
        else
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }
    while (i <= l2)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r2)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    k = 0;
    while (l1 <= r2)
    {
        arr[l1] = temp[k];
        k++;
        l1++;
    }
    delete[] temp;
}
void LibraryFunctions::mergeSort(int *arr, int start, int end)
{
    cout << "Inside Merge sort " << start << " " << end << endl;
    if (start < end)
    {
        int mid = (end + start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, mid + 1, end);
    }
}
int LibraryFunctions::partition(int* arr,int start,int end){
    int pivot = arr[start];
    int i = start, j = end;
    while(i<j){
        while (i<= end && arr[i] <= pivot)
        {
            i++;
        }
        while (j >= 0 && arr[j]> pivot)
        {
            j--;
        }
        if(i< j){
            intSwap(arr[i],arr[j]);
        }
    }
    intSwap(arr[start],arr[j]);
    return j;
}
void LibraryFunctions::quickSort(int* arr,int start,int end){
    if(start<end){
        int p = partition(arr,start,end);
        quickSort(arr,start,p-1);
        quickSort(arr,p+1,end);
    }
}