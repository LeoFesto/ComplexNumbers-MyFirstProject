#include "ComplexNumbers.h"
#include <cmath>
Complex::Complex(const Rational& re, const Rational& im) {
	Re = re;
	Im = im;
}

Complex::Complex(): Re(0), Im(0) {};

Complex::Complex(const Rational& im): Re(0),Im(im) {}; // Rational -> Complex (Re == 0; Im != 0)

Complex::operator Rational() const { // Complex -> Rational (Re != 0; Im == 0)
	return { this->Re };
}

Rational Complex::GetRe() const {
	return this->Re;
}

Rational Complex::GetIm() const {
	return this->Im;
}

void Complex::SetRe(Complex& number, const Rational& value) {
	number.Re = value;
}

void Complex::SetIm(Complex& number, const Rational& value) {
	number.Im = value;
}

Complex Complex::operator+(const Complex& other) {
	Rational re_ = this->Re + other.Re;
	Rational im_ = this->Im + other.Im;
	return { re_, im_ };
}

Complex Complex::operator*(const Complex& other) {
	Rational re_ = (this->Re * other.Re) - (this->Im * other.Im);
	Rational im_ = (this->Re * other.Im) + (other.Re * this->Im);
	return { re_, im_ };
}

Complex& Complex::operator=(const Complex& other) {
	this->Re = other.Re;
	this->Im = other.Im;
	return *this;
}

bool Complex::operator==(const Complex& other) {
	return (this->Re == other.Re and this->Im == other.Im);
}

bool Complex::operator!=(const Complex& other) {
	return (this->Re != other.Re) or (this->Im != other.Im);
}

Complex Complex::operator-(const Complex& other) {
	Rational re_ = this->Re - other.Re;
	Rational im_ = this->Im - other.Im;
	return { re_, im_ };
}

Complex Complex::operator/(const Complex& other) {
	Rational re_ = (this->Re * other.Re + this->Im * other.Im) / (other.Re * other.Re + other.Im * other.Im);
	Rational im_ = (this->Im * other.Re - this->Re * other.Im) / (other.Re * other.Re + other.Im * other.Im);
	return { re_, im_ };
}

ostream& operator<<(ostream& output, const Complex& number) {
	if(number.GetIm().Denominator() == 1)
		output << number.GetRe() << " + " << number.GetIm() << "i";
	/*else if (number.GetIm().Denominator() == number.GetRe().Denominator()) {
		output << "(" << number.GetRe().Numerator() << " + " << number.GetIm().Numerator() << "i)/" << number.GetIm().Denominator();
	}*/
	else
		output << number.GetRe() << " + (" << number.GetIm() << ")i";
	return output;
}

Complex& Complex::operator+=(const Complex& other) {
	*this = *this + other;
	return *this;
}

Complex& Complex::operator-=(const Complex& other) {
	*this = *this - other;
	return *this;
}

Complex& Complex::operator*=(const Complex& other) {
	*this = *this * other;
	return *this;
}
Complex& Complex::operator/=(const Complex& other) {
	*this = *this / other;
	return *this;
}
Complex Complex::operator-()const {
	Rational re_ = this->Re;
	Rational im_ = this->Im;
	return { -re_, -im_ };
}

Complex Complex::Pow(const int& n) {
	Complex temp = *this;
	Complex result = *this;
	for (int i = 0; i < n-1; i++) {
		result *= temp;
	}
	return result;
}


Complex Complex::operator+(const Rational& other) {
	Rational re_ = this->Re + other;
	return { re_, this->Im };
}

Complex Complex::operator-(const Rational& other) {
	return { this->Re - other, this->Im };
}

Complex Complex::operator/(const Rational& other) {
	return { this->Re / other, this->Im / other };
}

Complex Complex::operator*(const Rational& other) {
	return { this->Re * other, this->Im * other };
}


double Abs(const Complex& number) {
	return sqrt((double)number.GetRe() * (double)number.GetRe() + (double)number.GetIm() * (double)number.GetIm());
}

