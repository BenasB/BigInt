#pragma once

#include <string>

class BigInt
{
private:
    int allocatedDigits;
    char* digits;
    int digitCount;

    void allocateMoreDigits();
    void reverse();
    void swap(char* a, char* b);
public:
    BigInt();
    void appendDigit(int digit);
    void appendDigit(char digit);
    void appendDigits(std::string);
    int getDigitCount();
    char* getDigitsArray();
    BigInt operator + (BigInt const &other);
};