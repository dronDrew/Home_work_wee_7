#pragma once
#include "dependies.h"
namespace Geometry {
	class circle
	{
		float radius;
	public:
		circle();
		circle(float radius);
		void SetRadius(float radius);
		float Getradius();
		float Getleng_circull();
		bool operator==(circle& a);
		bool operator>(circle& a);
		bool operator<(circle& a);
		circle& operator+=(circle& a);
		circle& operator-=(circle& a);
		circle& operator+=(int& a);
		circle& operator-=(int& a);
		circle& operator+=(float& a);
		circle& operator-=(float& a);
		void Print();
	};
}
