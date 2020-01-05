#include "BigInt.h"

#pragma region CONSTRUCTORS
BigInt::BigInt()
{
    allocatedDigits = 32;
    digitCount = 0;
    digits = new char[allocatedDigits];
}

// Starting number is an int
// Be careful to not pass a number bigger than the int limit as an argument!
BigInt::BigInt(int number)
{
    allocatedDigits = 16;
    digitCount = 0;
    digits = new char[allocatedDigits];

    appendDigits(number);
}

BigInt::BigInt(std::string digitString)
{
    allocatedDigits = 16;
    digitCount = 0;
    digits = new char[allocatedDigits];

    appendDigits(digitString);
}
#pragma endregion CONSTRUCTORS

#pragma region PARAMETERS
int BigInt::getDigitCount()
{
    if (digitCount == 0)
        return 1;

    return digitCount;
}

char* BigInt::getDigitsArray()
{
    if (digitCount == 0)
    {
        char* temporary = new char[1];
        temporary[0] = '0';
        return temporary;
    }

    return digits;
}

std::string BigInt::getDigitsString()
{
    if (digitCount == 0)
    {
        return "0";
    }

    return std::string(digits, digitCount);
}
#pragma endregion PARAMETERS

#pragma region PRIVATE
int BigInt::int_pow(int x, int e) // Because cmath pow uses floating point
{
    return (e == 0) ? 1 : x * int_pow(x, e - 1);
}

// Double the size of digits array to allow more digits
void BigInt::allocateMoreDigits()
{
    allocatedDigits *= 2;
    char* newDigits = new char[allocatedDigits];

    // Copy digits
    for (int i = 0; i < digitCount; i++)
    {
        newDigits[i] = digits[i];
    }

    delete(digits);
    digits = newDigits;
}

void BigInt::swap(char* a, char* b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

// Reverses the order of the digits
void BigInt::reverse()
{
    for(int i = 0; i < digitCount/2; i++)
    {
        swap(&digits[i], &digits[digitCount-i-1]);
    }
}
#pragma endregion PRIVATE

#pragma region APPEND
// Appends an int that is a single digit
void BigInt::appendDigit(int digit)
{
    if (digit < 0 || digit > 9)
        return;

    if (digitCount + 1 > allocatedDigits)
    {
        allocateMoreDigits();
    }

    digits[digitCount] = 48+digit;
    digitCount++;
}

// Appends a character representing a single digit integer
void BigInt::appendDigit(char digit)
{
    if (digit < 48 || digit > 57)
        return;

    if (digitCount + 1 > allocatedDigits)
    {
        allocateMoreDigits();
    }

    digits[digitCount] = digit;
    digitCount++;
}

void BigInt::appendDigits(std::string digitString)
{
    for(int i = 0; i < digitString.size(); i++)
    {
        appendDigit(digitString[i]);
    }
}

void BigInt::appendDigits(int number)
{
    int temp = number;
    int n = 0;

    // Count number of digits
    while (temp != 0)
    {
        n++;
        temp /= 10;
    }

    for (int i = n-1; i >= 0; i--)
    {
        int digit = number / int_pow(10, i);
        digit %= 10;

        appendDigit(digit);
    }
}
#pragma endregion APPEND

#pragma region OPERATORS
BigInt BigInt::operator + (BigInt const &other)
{
    BigInt newBigInt;
    const BigInt* biggerNumber = (digitCount > other.digitCount) ? this : &other;
    const BigInt* smallerNumber = (digitCount <= other.digitCount) ? this : &other;
    int difference = (*biggerNumber).digitCount - (*smallerNumber).digitCount;

    int carry = 0;
    for (int i = (*biggerNumber).digitCount-1; i >= 0; i--)
    {
        int a = (*biggerNumber).digits[i]-48;
        int b = (i-difference >= 0) ? (*smallerNumber).digits[i-difference]-48 : 0;
        int result = a+b+carry;
        int digit = result % 10;
        carry = result / 10;
        newBigInt.appendDigit(digit);

        if (i == 0 && carry != 0)
            newBigInt.appendDigit(carry);
    }

    newBigInt.reverse();

    return newBigInt;
}

BigInt& BigInt::operator+=(BigInt const &other)
{
    *this = *this + other;
    return *this;
}

BigInt BigInt::operator ++()
{
    BigInt increment;
    increment.appendDigit(1);

    *this = *this + increment;

    return *this;
}

BigInt BigInt::operator ++(int)
{
    BigInt temp = *this;

    ++(*this);

    return temp;
}

// Doesn't take into account when you subtract a larger number from a smaller one
BigInt BigInt::operator - (BigInt const &other)
{
    BigInt newBigInt;
    const BigInt* biggerNumber = (digitCount >= other.digitCount) ? this : &other;
    const BigInt* smallerNumber = (digitCount < other.digitCount) ? this : &other;
    int difference = (*biggerNumber).digitCount - (*smallerNumber).digitCount;

    int carry = 0;
    for (int i = (*biggerNumber).digitCount-1; i >= 0; i--)
    {
        int a = (*biggerNumber).digits[i]-48;
        int b = (i-difference >= 0) ? (*smallerNumber).digits[i-difference]-48 : 0;
        int result = a-b-carry;
        int digit = 0;

        if (result >= 0)
        {
            digit = result;
            carry = 0;
        }else if (result < 0){
            digit = 10 + result;
            carry = 1;
        }

        newBigInt.appendDigit(digit);
    }

    newBigInt.reverse();

    return newBigInt;
}
#pragma endregion OPERATORS