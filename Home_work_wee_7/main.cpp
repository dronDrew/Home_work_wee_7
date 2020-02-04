#include "dependies.h"
#include "Template_list.h"

using namespace std;
int main() {
	List::List<int> a;
	a.Add_to_head(10);
	a.Add_to_head(99);
	a.Add_to_head(6);
	a.Add_to_Tail(1000);
	a.Add_to_Tail(2000);
	a.Add_to_Tail(5000);
	a.Add_to_positition(5, 4);
	//a.Remove_all();
	//a.Remove_from_head();
	//a.Remove_from_tail();
	//a.Remove_from_tail();
	//std::cout << a.Get_value_from_head();
	//std::cout << a.get_value_from_tail();
	std::cout << a.Get_value_from_position(1);
	//a.Remove_from_head();
		return 0;
}