#include "fraction.h"
namespace math {
	int Fraction::summ_of_fractions = 0;
	Fraction::Fraction()
	{
		this->numerator = 0;
		this->denominator = 1;

	}
	Fraction::Fraction(int numerator) :Fraction() {
		Set_numerator(numerator);
	}
	Fraction::Fraction(int numerator, int denominator) : Fraction(numerator) {
		Set_denominator(denominator);
	}
	Fraction::Fraction(Fraction& other) {
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}
	Fraction::~Fraction() {

	}
	//
	void Fraction::Fraction_check() {
		if (this->numerator > this->denominator) {
			std::cout << "You create a improper fraction\n";
		}
		else
		{
			std::cout << "You create a simple fraction\n";
		}
	}
	inline void Fraction::Set_numerator(int numenator) {
		this->numerator = numerator;
	};
	inline void Fraction::Set_denominator(int denominator) {
		try
		{
			if (denominator == 0) throw custom_Excep(0, "denominator can`t be equel to zero");
			this->denominator = denominator;
		}
		catch (custom_Excep & a)
		{
			a.what();
			return;
		}

	};
	void Fraction::Fraction_show() {
		common_denominator();
		set_whole_part();
		if (this->Whole_part > 0) {
			std::cout << "  " << numerator << std::endl;
			std::cout << Whole_part << " -----" << std::endl;
			std::cout << "  " << denominator << std::endl;
		}
		else {
			std::cout << this->numerator << '/' << this->denominator << std::endl;
		}
	}
	inline double Fraction::Get_decimal() {
		return static_cast<double>(this->numerator / this->denominator);

	}
	void Fraction::common_denominator() {
		if (numerator) {
			if (numerator > denominator) {
				int n, d;
				n = numerator;
				d = denominator;
				int temp = d % n;
				while (temp)
				{
					d = n;
					n = temp;
					temp = d % n;
				}
				int nod = n;
				if (nod != 0) {
					numerator /= nod;
					denominator /= nod;
				}
			}
			else
			{
				int n, d;
				n = numerator;
				d = denominator;
				int temp = d % n;
				while (temp)
				{
					d = n;
					n = temp;
					temp = d % n;

				}
				int nod = n;
				if (nod != 0) {
					numerator /= nod;
					denominator /= nod;
				}

			}
		}
	}
	void Fraction::set_whole_part() {
		if (numerator > denominator) {
			this->Whole_part = numerator / denominator;
			numerator %= denominator;
		}
	}
	inline int Fraction::Get_summ_of_fractions() {
		return summ_of_fractions;
	}
	//
	Fraction Fraction:: operator *(Fraction other) {
		Fraction res;
		res.numerator = this->numerator * other.numerator;
		res.denominator = this->denominator * other.denominator;
		return res;
	}
	Fraction Fraction:: operator /(Fraction other) {
		Fraction res;
		res.numerator = this->numerator * other.denominator;
		res.denominator = this->denominator * other.numerator;
		return res;
	}
	Fraction Fraction:: operator +(Fraction other) {
		Fraction res;
		res.numerator = (this->numerator * other.denominator) + (other.numerator * this->denominator);
		res.denominator = this->denominator * other.denominator;
		return res;
	}
	Fraction Fraction:: operator -(Fraction other) {
		Fraction res;
		res.numerator = (this->numerator * other.denominator) - (other.numerator * this->denominator);
		res.denominator = this->denominator * other.denominator;
		return res;
	}
	Fraction Fraction:: operator *(int a) {
		Fraction res;
		res.numerator = this->numerator * a;
		res.denominator = this->denominator * 1;
		return res;
	}
	Fraction Fraction:: operator /(int a) {
		Fraction res;
		res.numerator = this->numerator * 1;
		res.denominator = this->denominator * a;
		return res;
	}
	Fraction Fraction:: operator +(int a) {
		Fraction res;
		res.numerator = (this->numerator * 1) + (a * this->denominator);
		res.denominator = this->denominator * 1;
		return res;
	}
	Fraction Fraction:: operator -(int a) {
		Fraction res;
		res.numerator = (this->numerator * 1) - (a * this->denominator);
		res.denominator = this->denominator * 1;
		return res;
	}
	Fraction Fraction:: operator *(double a) {
		Fraction res;
		long  double a1 = a;
		a1 *= PRESICION;
		res.numerator = this->numerator * a1;
		res.denominator = this->denominator * PRESICION;
		return res;
	}
	Fraction Fraction:: operator /(double a) {
		Fraction res;
		long double a1 = a;
		a1 *= PRESICION;
		res.numerator = this->numerator * PRESICION;
		res.denominator = this->denominator * a1;
		return res;
	}
	Fraction Fraction:: operator +(double a) {
		Fraction res;
		long double a1 = a;
		a1 *= PRESICION;
		res.numerator = (this->numerator * PRESICION) + (a1 * this->denominator);
		res.denominator = this->denominator * PRESICION;
		return res;
	}
	Fraction Fraction:: operator -(double a) {
		Fraction res;
		long double a1 = a;
		a1 *= PRESICION;
		res.numerator = (this->numerator * PRESICION) - (a1 * this->denominator);
		res.denominator = this->denominator * PRESICION;
		return res;
	}
}