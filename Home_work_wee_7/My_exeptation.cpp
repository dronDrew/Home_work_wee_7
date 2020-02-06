#include "My_exeptation.h"
excep::error::error(int code, std::string info_error) {
	this->code = code;
	this->info_error = info_error;
	this->next = nullptr;
}
excep::excep() {
	this->begin_list = nullptr;
}
void excep::Add(int code, std::string info_error) {
	if (this->begin_list==nullptr)
	{
		this->begin_list = new error(code, info_error);
	}
	else {
		error* point = this->begin_list;
		while (point->next!=nullptr)
		{
			point = point->next;
		}
		point->next = new error(code, info_error);
	}

}
void excep::Init() {
	std::ifstream file;
	file.open("error_list.txt");
	if (!file.is_open())
	{
		std::cout << "Beware exception don`t work\n";
	}
	else {
		int code_from_file;
		std::string info_from_file;
		while (!file.eof())
		{
			file >> code_from_file;
			std::getline(file, info_from_file);
			this->Add(code_from_file, info_from_file);
		}
	}
}
std::pair<int, std::string> excep::Search(int q) {
	error* point = this->begin_list;
	while (point->code<q)
	{
		point = point->next;
	}
	std::cout <<"code error: "<< point->code <<"  info about error : " << point->info_error << std::endl;
	std::pair<int, std::string> p (point->code, point->info_error);
	return p;
}
void excep::Remove() {
	while (this->begin_list != nullptr)
	{


     if (this->begin_list->next == nullptr) {
	error* point = this->begin_list;
	delete point;
	point = nullptr;
	this->begin_list = point;
	}
	else
	{
	error* point = this->begin_list;
	while (point->next->next != nullptr)
	{
		point = point->next;
	}
	delete point->next;
	point->next = nullptr;

	}
	}
}
custom_Excep::custom_Excep(int code, std::string msg) {
	this->code = code;
	this->msg = msg;
}
std::pair<int, std::string>custom_Excep::what() {
	std::cout << "Code of Error : " << this->code << " Info about error : " << this->msg << std::endl;
	std::pair<int, std::string> p(this->code, this->msg);
	return p;
}