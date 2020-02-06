#pragma once
#include"dependies.h"
class excep {
	struct error
	{
		int code;
		std::string info_error;
		error* next;
		error(int code, std::string info_error);
	};
	void Add(int code, std::string info_error);
	error* begin_list;
public:
	excep();
	void Init();
	std::pair<int,std::string> Search(int q);
	void Remove();
};
class custom_Excep:virtual public std::exception {
	int code;
	std::string msg;
public:
	custom_Excep(int code, std::string msg);
	std::pair<int, std::string> what();
};

