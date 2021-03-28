#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <sstream>
#include <map>
using namespace std;
#include "RationalNumbers.h"

int gcd(const int& a, const int& b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void Rational::Irreducible(const int& num, const int& denom) {
        int nod = gcd(num, denom);
        numerator /= nod;
        denominator /= nod;
    };

Rational::Rational() {
        numerator = 0;
        denominator = 1;
    }
Rational::Rational(const int& number) {
        numerator = number;
        denominator = 1;
    }
Rational::Rational(const int& num, const int& denom) {
        numerator = num;
        denominator = denom;
        this->Irreducible(numerator, denominator);
        if (numerator > 0 and denominator < 0) {
            numerator = -numerator;
            denominator = abs(denominator);
        }
        else if (numerator == 0) {
            Rational();
        }
    }

Rational::Rational(const double& num) {
    double integral = floor(num);
    double frac = num - integral;
    const int precision = 1000000000;
    int gcd_ = gcd(round(frac * precision), precision);
    int denominator = precision / gcd_;
    int numerator = (round(frac * precision) / gcd_)+integral*denominator;
    this->numerator = numerator;
    this->denominator = denominator;
}

Rational::Rational(const float& number) : Rational((double)number){}

Rational::operator double() const {
    int num = this->Numerator();
    int denom = this->Denominator();
    double result = (double)num / denom;
    return result;
}

Rational::operator float() const {
    int num = this->Numerator();
    int denom = this->Denominator();
    float result = (float)num / denom;
    return result;
}

Rational::operator int() const {
    if (this->Denominator() == 1)
        return this->Numerator();
}

int Rational::Numerator() const {
        return numerator;
    }
int Rational::Denominator() const {
        return denominator;
    }
void Rational::SetNumerator(const int& n) {
        numerator = n;
        this->Irreducible(numerator, denominator);
    }
void Rational::SetDenominator(const int& n){
        denominator = n;
        this->Irreducible(numerator, denominator);
    }


//FractionsWithCommonDenominator - структура дробей с общим знаменателем
struct FractionsWithCommonDenominator {
    int numerator_a; // приведённый числитель a
    int numerator_b; // приведённый числитель b
    int common_denominator; // общий знаменатель
};

//ToCommonDenominator - метод приведения двух рациональный чисел к общему знаменателю
FractionsWithCommonDenominator ToCommonDenominator(const Rational& a, const Rational& b) {
    int num_a = a.Numerator() * b.Denominator();
    int num_b = b.Numerator() * a.Denominator();
    int com_denom = a.Denominator() * b.Denominator();
    return { num_a, num_b, com_denom };
}

bool operator==(const Rational& a, const Rational& b){
    FractionsWithCommonDenominator fracts = ToCommonDenominator(a, b);
    return (fracts.numerator_a == fracts.numerator_b);
}

bool operator!=(const Rational& a, const Rational& b) {
    FractionsWithCommonDenominator fracts = ToCommonDenominator(a, b);
    return (fracts.numerator_a != fracts.numerator_b);
}

Rational operator+(const Rational& a, const Rational& b){
    FractionsWithCommonDenominator fracts = ToCommonDenominator(a, b);
    return {fracts.numerator_a + fracts.numerator_b, fracts.common_denominator};
}

Rational operator-(const Rational& a, const Rational& b){
    FractionsWithCommonDenominator fracts = ToCommonDenominator(a, b);
    return { fracts.numerator_a - fracts.numerator_b, fracts.common_denominator };
}

Rational operator*(const Rational& a, const Rational& b){
    return { a.Numerator() * b.Numerator(), a.Denominator() * b.Denominator() };
}

Rational operator/(const Rational& a, const Rational& b){
    return { a.Numerator() * b.Denominator(), a.Denominator() * b.Numerator() };
}

bool operator<(const Rational& a, const Rational& b) {
    FractionsWithCommonDenominator fracts = ToCommonDenominator(a, b);
    return (fracts.numerator_a < fracts.numerator_b);
}

bool operator>(const Rational& a, const Rational& b) {
    FractionsWithCommonDenominator fracts = ToCommonDenominator(a, b);
    return (fracts.numerator_a > fracts.numerator_b);
}

ostream& operator<<(ostream& output, const Rational& r){
    if (r.Denominator() == 1)
        output << r.Numerator();
    else
        output << r.Numerator() << "/" << r.Denominator();
    return output;
}

istream& operator>>(istream& input, Rational&r){
    int num, denom;
    input >> num;
    input.ignore(1);
    input >> denom;
    r.SetNumerator(num);
    r.SetDenominator(denom);
    return input;
}
Rational Rational::operator-() const {
    int num = this->Numerator();
    int denom = abs(this->Denominator());
    return { -num, denom };
}