#include "Area.h"
namespace Geometry {
	squer::squer()
	{

	}
	int squer::times_colled = 0;
	double squer::p(double side_a, double side_b, double side_c) {
		return ((side_a + side_b + side_c) / 2);
	}
	double squer::Triangol_sqr_side_hight(double side_a, double hight) {
		times_colled++;
		return ((((1.0 / 2.0) * side_a) * hight));
	}
	double squer::Triangol_sqr_three_sides(double side_a, double side_b, double side_c) {
		times_colled++;
		return (sqrt(p(side_a, side_b, side_c) * (p(side_a, side_b, side_c) - side_a) * (p(side_a, side_b, side_c) - side_b) * (p(side_a, side_b, side_c) - side_c)));
	}
	double squer::Triangol_sqr_two_side_and_corner(double side_a, double side_b, double alpha) {
		times_colled++;
		return (((side_a * side_b) / 2) * sin(alpha * PI / 180));
	}

	double squer::Triangol_sqr_Round_around(double side_a, double side_b, double side_c, double R) {
		++times_colled;
		return ((side_a * side_b * side_c) / (4 * R));
	}
	double squer::Triangol_sqr_round_inside(double side_a, double side_b, double side_c, double r) {
		++times_colled;
		return p(side_a, side_b, side_c) * r;
	}
	//squer
	double squer::Squer_sqr_by_side(double side) {
		++times_colled;
		return (side * side);
	}
	double squer::Squer_sqr_by_diagonal(double diagonal) {
		++times_colled;
		return 1.0 / 2.0 * (diagonal * diagonal);
	}

	//rectangel
	double squer::Rect_sqr(double side_a, double side_b) {
		++times_colled;
		return side_a * side_b;
	}
	//rhombus
	double squer::Rhombus_sqr_by_side_and_hight(double side_a, double hight) {
		++times_colled;
		return side_a * hight;
	}
	double squer::Rhombus_sqr_by_side_and_corner(double side_a, double corner) {
		++times_colled;
		return (side_a * side_a) * sin(corner * PI / 180);
	}
	double squer::Rhombus_sqr_by_diagonal(double diagonal_1, double diagonal_2) {
		++times_colled;
		return 1.0 / 2.0 * diagonal_1 * diagonal_2;
	}
	int squer::Get_time_colled() {
		return times_colled;
	}
}