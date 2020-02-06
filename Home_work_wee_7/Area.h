#pragma once
#include "dependies.h"
namespace Geometry {
	class squer
	{

		static int times_colled;
		static double p(double side_a, double side_b, double side_c);
	public:
		squer();
		static int Get_time_colled();
		//triangol
		static double Triangol_sqr_side_hight(double side_a, double hight);
		static double Triangol_sqr_three_sides(double side_a, double side_b, double side_c);
		static double Triangol_sqr_two_side_and_corner(double side_a, double side_b, double  alpha);
		static double Triangol_sqr_Round_around(double side_a, double side_b, double side_c, double R);
		static double Triangol_sqr_round_inside(double side_a, double side_b, double side_c, double r);
		//squer
		static double Squer_sqr_by_side(double side);
		static double Squer_sqr_by_diagonal(double diagonal);
		//rectangel
		static double Rect_sqr(double side_a, double side_b);
		//rhombus
		static double Rhombus_sqr_by_side_and_hight(double side_a, double hight);
		static double Rhombus_sqr_by_side_and_corner(double side_a, double corner);
		static double Rhombus_sqr_by_diagonal(double diagonal_1, double diagonal_2);

	};
}


