#include "point.h"
namespace Geometry {
	int Point::sum_of_points = 0;

	Point::Point()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
		++sum_of_points;
	}

	Point::Point(int x) :Point() {
		Set_x(x);
	}
	Point::Point(int x, int y) : Point(x) {
		Set_y(y);
	}
	Point::Point(int x, int y, int z) : Point(x, y) {
		Set_z(z);
	}

	Point::~Point()
	{

	}
	inline void Point::Set_x(int x) { this->x = x; }
	inline void Point::Set_y(int y) { this->y = y; }
	inline void Point::Set_z(int z) { this->z = z; }
	inline int Point::Get_x() { return this->x; }
	inline int Point::Get_y() { return this->y; }
	inline int Point::Get_z() { return this->z; }
	void Point::Show_point() {
		std::cout << "The coordinat x is : " << this->x << '\n';
		std::cout << "The coordinat y is : " << this->y << '\n';
		std::cout << "The coordinat z is : " << this->z << '\n';
	}
	void Point::init_point() {
		int user_input{ 0 };
		std::cout << "Enter coordinat for x :\n";
		std::cin >> user_input;
		Set_x(user_input);
		std::cout << "Enter coordinat for y :\n";
		std::cin >> user_input;
		Set_y(user_input);
		std::cout << "Enter coordinat for z :\n";
		std::cin >> user_input;
		Set_z(user_input);
	}
	int inline Point::Get_summury_of_object() {
		return sum_of_points;
	}
}
void Set_point_from_file(Geometry::Point a) {
	std::ifstream file;
	std::string path;
	int temp;
	std::cout << "Please enter path to file with file name and extension\n";
	std::cin >> path;
	file.open(path);
	file >> temp;
	a.Set_x(temp);
	file >> temp;
	a.Set_y(temp);
	file >> temp;
	a.Set_z(temp);
	file.close();
}
void Save_in_file(Geometry::Point a) {
	std::ofstream file;
	std::string path;
	std::cout << "Please enter path to creating and saving data from your object or objects\n";
	std::cin >> path;
	file.open(path, std::ios_base::app);
	file << a.Get_x() << '\n';
	file << a.Get_y() << '\n';
	file << a.Get_z() << '\n';
	file.close();
}
