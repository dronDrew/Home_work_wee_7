#include "Complex.h"
namespace math {
	Complex::Complex() {
		this->real_part = 0;
		this->imaginary_part = 0;
	}
	Complex::Complex(double real_part) :Complex() {
		this->real_part = real_part;
	}
	Complex::Complex(double real_part, double imaginary_part) : Complex(real_part) {
		this->imaginary_part = imaginary_part;
	}
	Complex::~Complex() {}
	Complex::Complex(Complex& other) {
		this->real_part = other.real_part;
		this->imaginary_part = other.imaginary_part;
	}
	Complex& Complex::operator +(Complex& other) {
		this->real_part += other.real_part;
		this->imaginary_part += other.imaginary_part;
		return *this;
	}
	Complex& Complex::operator -(Complex& other) {
		this->real_part -= other.real_part;
		this->imaginary_part -= other.imaginary_part;
		return *this;
	}
	bool Complex::operator ==(Complex& other) {
		if (this->real_part == other.real_part && this->imaginary_part == other.imaginary_part) {
			return true;
		}
		else
		{
			return false;
		}
	}
	bool Complex::operator !=(Complex& other) {
		return !(*this == other);
	}
	std::istream& operator>>(std::istream& in, Complex& a) {
		std::cout << "Enter real part of Complex number" << std::endl;
		in >> a.real_part;
		std::cout << "Enter imaginary part of Complex number" << std::endl;
		in >> a.imaginary_part;
		return in;
	}
	std::ostream& operator<<(std::ostream& out, Complex& a) {
		if (a.real_part < 0) {
			out << a.real_part << " + i(" << a.imaginary_part << ")" << std::endl;
		}
		else
		{
			out << a.real_part << " + i" << a.imaginary_part << std::endl;
		}
		return out;
	}
}