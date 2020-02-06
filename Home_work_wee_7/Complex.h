#pragma once
#include "dependies.h"
namespace math {
	class Complex
	{
		double real_part;
		double imaginary_part;
	public:
		explicit Complex();
		explicit Complex(double real_part);
		explicit Complex(double real_part, double imaginary_part);
		Complex(Complex& other);
		~Complex();
		Complex& operator +(Complex& other);
		Complex& operator -(Complex& other);
		bool operator ==(Complex& other);
		bool operator !=(Complex& other);
		friend std::istream& operator>>(std::istream&, Complex&);
		friend std::ostream& operator<<(std::ostream&, Complex&);

	};
}

