#pragma once
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <sstream>
#include <cmath>
#include <map>

using namespace std;

int gcd(const int& a, const int& b);
class Rational{
private:
    int numerator; // числитель рационального числа
    int denominator; // знаменатель рационального числа
    // Irreducible - метод приведения к несократимой дроби
    void Irreducible(const int& num, const int& denom);
public:
    Rational();
    Rational(const int& number);
    Rational(const double& number);
    Rational(const float& number);
    Rational(const int& num, const int& denom);
    int Numerator() const;
    int Denominator() const;
    void SetNumerator(const int& n);
    void SetDenominator(const int& n);
    Rational operator-() const;
    operator double() const;
    operator float() const;
    operator int() const;
};

struct FractionsWithCommonDenominator;
FractionsWithCommonDenominator ToCommonDenominator(const Rational& a, const Rational& b);
bool operator==(const Rational& a, const Rational& b);
bool operator!=(const Rational& a, const Rational& b);


Rational operator+(const Rational& a, const Rational& b);
template<typename T>
Rational operator+(const Rational& a, const T& b) { return { a + (Rational)b }; };


Rational operator-(const Rational& a, const Rational& b) ;
template<typename T>
Rational operator-(const Rational& a, const T& b) { return { a - (Rational)b }; };


Rational operator*(const Rational& a, const Rational& b);
template<typename T>
Rational operator*(const Rational& a, const T& b) { return { a * (Rational)b }; };


Rational operator/(const Rational& a, const Rational& b);
template<typename T>
Rational operator/(const Rational& a, const T& b) { return { a / (Rational)b }; };


bool operator<(const Rational& a, const Rational& b);
bool operator>(const Rational& a, const Rational& b);
ostream& operator<<(ostream& output, const Rational& r);
istream& operator>>(istream& input, Rational& r);

