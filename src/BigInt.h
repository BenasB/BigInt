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
    void swap(char*, char*);
    int int_pow(int, int);
public:
    BigInt();
    BigInt(int number);
    BigInt(std::string);
    void appendDigit(int);
    void appendDigit(char);
    void appendDigits(std::string);
    void appendDigits(int);

    int getDigitCount();
    char* getDigitsArray();
    std::string getDigitsString();

    BigInt operator + (BigInt const&);
    BigInt operator - (BigInt const&);
    BigInt& operator+=(BigInt const&);
    BigInt operator ++();
    BigInt operator ++(int);
};