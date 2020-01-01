#include <iostream>
#include "BigInt.h"

using namespace std;

void sumNumbers()
{
    BigInt sum;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        BigInt t;
        string number;

        cin >> number;
        t.appendDigits(number);

        sum = sum + t;
    }

    char* digits = sum.getDigitsArray();
    for (int i = 0; i < sum.getDigitCount(); i++)
    {
        cout << digits[i];
    }
    cout << endl;
}

void increment()
{
    BigInt a;
    BigInt increment(1);
    
    for (int i = 0; i < 100; i++)
    {
        a += increment;
        char* digits = a.getDigitsArray();
        for (int i = 0; i < a.getDigitCount(); i++)
        {
            cout << digits[i];
        }
        cout << endl;
    }
}

void mixedAppend()
{
    BigInt a(7062183);
    a.appendDigits("872");
    a.appendDigits(123594);
    a.appendDigit('8');
    a.appendDigit(2);
    a.appendDigits("00");

    BigInt b(92);

    a += b;

    char* digits = a.getDigitsArray();
    for (int i = 0; i < a.getDigitCount(); i++)
    {
        cout << digits[i];
    }
    cout << endl;
}

int main()
{
    sumNumbers()
}