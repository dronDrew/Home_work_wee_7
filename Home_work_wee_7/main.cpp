#include "dependies.h"
#include "Template_list.h"
#include "My_exeptation.h"
#include "fraction.h"
#include "Complex.h"
#include "Circle.h"
#include "point.h"
#include "Area.h"

using namespace std;
int main() {
	math::Fraction rtf;
	excep g;
	g.Init();
	List::List<int> a;
	a.Add_to_head(10);
	a.Add_to_head(99);
	a.Add_to_head(6);
	a.Add_to_Tail(1000);
	a.Add_to_Tail(2000);
	a.Add_to_Tail(5000);
	a.Add_to_positition(5, 4);
	a.Remove_all();
	//a.Remove_from_head();
	//a.Remove_from_tail();
	//a.Remove_from_tail();
	//std::cout << a.Get_value_from_head();-
	//std::cout << a.get_value_from_tail();
	std::cout << a.Get_value_from_position(1)<< std::endl;
	std::cout << a.get_value_from_tail()<<std::endl;
	//a.Remove_from_head();
	g.Remove();
	math::Complex nbv;
	Geometry::circle round(10);
	Geometry::squer qwf;
		return 0;
}