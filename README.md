# BigInt

[![Build Status](https://travis-ci.com/BenasB/BigInt.svg?branch=master)](https://travis-ci.com/BenasB/BigInt)
[![codecov](https://codecov.io/gh/BenasB/BigInt/branch/master/graph/badge.svg)](https://codecov.io/gh/BenasB/BigInt)
[![GitHub license](https://img.shields.io/badge/license-MIT-brightgreen)](https://github.com/BenasB/BigInt/blob/master/LICENSE)

An implementation of a C++ type for a large integer number

## Features
* Represent an arbitrarily long integer (negatives not supported yet)
* Multiple ways to append digits
* Addition

## Usage

Create a variable of type BigInt, append digits and perform arithmetic operations. You can then print it out using a `string` or `char*`.

```cpp
BigInt a(7062183);
a.appendDigits("872");
a.appendDigits(123594);
a.appendDigit('8');
a.appendDigit(2);
a.appendDigits("00");

BigInt b(92);

a += b;

std::cout << a.getDigitsString();
```

## Todo
* Remove digits
* Negative numbers
* Subtraction
* Multiplication
* Division

## Testing

[Catch2](https://github.com/catchorg/Catch2) is the testing framework used for this project. All testing related files are located in `testing/`.

## Purpose

The purpose of this project is to learn how projects in C++ work, how to work with [CMake](https://cmake.org), [Travis CI](https://travis-ci.com), [Catch2](https://github.com/catchorg/Catch2), [CodeCov](https://codecov.io) and learn about general computer science and algorithms while implementing a `BigInt` type. Inspired by [Algorithms Illuminated](http://www.algorithmsilluminated.org) by Tim Roughgarden.