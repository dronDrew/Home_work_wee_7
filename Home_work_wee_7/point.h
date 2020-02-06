#pragma once
#include "dependies.h"
namespace Geometry {
	class Point
	{
	private:
		int x;
		int y;
		int z;
		static int sum_of_points;
	public:
		Point();
		Point(int x);
		Point(int x, int y);
		Point(int x, int y, int z);
		~Point();
		inline void Set_x(int x);
		inline void Set_y(int y);
		inline void Set_z(int z);
		inline int Get_x();
		inline int Get_y();
		inline int Get_z();
		void Show_point();
		void init_point();
		static inline int Get_summury_of_object();
	};
}
void Set_point_from_file(Geometry::Point a);
void Save_in_file(Geometry::Point a);
