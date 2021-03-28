#include "RationalNumbers.h"
#include "ComplexNumbers.h"
#include <iostream>
#include <vector>
#include <cassert>



int main()
{
	using R = Rational;
	using C = Complex;
	C a = { 1,2 };
	cout << "Begin: " << a << endl;
	cout << a * 5 << endl;
	cout << a + 5 << endl; // 6+2i
	cout << a - 5 << endl; // -4-3i
	cout << a / 5 << endl;
	cout << (C{ 5, R{18,4} } / 9) << endl;
	cout <<( C{ R{5,9}, R{1,2} });
}
