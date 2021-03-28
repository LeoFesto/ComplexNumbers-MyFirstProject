#pragma once
#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <sstream>
#include "RationalNumbers.h"

using namespace std;

class Complex {
private:
	Rational Re, Im;
public:
	Complex(const Rational& re, const Rational& im);
	Complex();
	Complex(const Rational& im); 
	Complex(const int& im) : Complex((Rational) im) {};
	Complex(const double& im) : Complex((Rational)im) {};
	Complex(const float& im) : Complex((Rational)im) {};
	Rational GetRe() const;
	Rational GetIm() const;
	void SetRe(Complex& number, const Rational& value);
	void SetIm(Complex& number, const Rational& value);
	Complex& operator=(const Complex& other);
	bool operator!=(const Complex& other);
	bool operator==(const Complex& other);


	Complex operator+(const Complex& other);
	Complex operator+(const Rational& other);
	template<typename T>
	Complex operator+(const T& other) { return {*this+(Rational)other}; };


	Complex operator-(const Complex& other);
	Complex operator-(const Rational& other);
	template<typename T>
	Complex operator-(const T& other) { return { *this - (Rational)other }; };

	
	Complex operator*(const Complex& other);
	Complex operator*(const Rational& other);
	template<typename T>
	Complex operator*(const T& other) { return { *this * (Rational)other }; };

	
	Complex operator/(const Complex& other);
	Complex operator/(const Rational& other);
	template<typename T>
	Complex operator/(const T& other) { return { *this / (Rational)other }; };



	Complex& operator+=(const Complex& other);
	Complex& operator-=(const Complex& other);
	Complex& operator*=(const Complex& other);
	Complex& operator/=(const Complex& other);
	Complex operator-()const;
	Complex Pow(const int& n);
	operator Rational() const; // из комплексного в рациональное (без Im)
	double Abs(const Complex& number);
	//?? Arg(const Complex& number);
};
ostream& operator<<(ostream& output, const Complex& other);