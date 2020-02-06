#include "Circle.h"
namespace Geometry {
	circle::circle()
	{
		this->radius = 0;
	}
	circle::circle(float radius) {
		this->radius = radius;
	}
	void circle::SetRadius(float radius) {
		this->radius = radius;
	}
	float circle::Getradius() {
		return this->radius;
	}
	float circle::Getleng_circull() {
		return (this->radius * PI);
	}
	bool circle::operator==(circle& a) {
		return this->radius == a.radius;
	}
	bool circle::operator>(circle& a) {
		return this->Getleng_circull() > a.Getleng_circull();
	}
	bool circle::operator<(circle& a) {
		return this->Getleng_circull() < a.Getleng_circull();
	}
	circle& circle::operator+=(circle& a) {
		this->radius += a.radius;
		return *this;
	}
	circle& circle::operator-=(circle& a) {
		this->radius -= a.radius;
		return *this;
	}
	circle& circle::operator+=(int& a) {
		this->radius += a;
		return *this;
	}
	circle& circle::operator-=(int& a) {
		this->radius -= a;
		return *this;
	}
	circle& circle::operator+=(float& a) {
		this->radius += a;
		return *this;
	}
	circle& circle::operator-=(float& a) {
		this->radius -= a;
		return *this;
	}
	void circle::Print() {
		std::cout << "Radious : " << this->radius << std::endl;
		std::cout << "Lenght : " << this->Getleng_circull() << std::endl;

	}
}
