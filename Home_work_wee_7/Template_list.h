#pragma once
#include"dependies.h"
#include "My_exeptation.h"
namespace List {
	template<typename T>
	class List {
		struct elem
		{
			T data;
			elem* prev;
			elem* next;
			elem(T data);//done
		};
	public:
		elem* top;
		List();//done
		void Add_to_head(T data);//done
		void Add_to_Tail(T data);//done
		void Add_to_positition(T data, int position);//done
		void Remove_from_head();//done
		void Remove_from_tail();//done
		void Remove_position(int position);//done
		void Remove_all();//done
		T Get_value_from_position(int position);//done
		T Get_value_from_head();//done
		T get_value_from_tail();//done
	};
}

template<typename T>
List::List<T>::elem::elem(T data)
{
	this->data = data;
	this->next = nullptr;
	this->prev = nullptr;
}
template<typename T>
List::List<T>::List() {
	this->top = nullptr;
}
template<typename T>
void List::List<T>::Add_to_head(T data) {
	try
	{
		if (this->top == nullptr) {
			this->top = new elem(data);
		}
		else
		{
			elem* point = this->top;
			point->prev = new elem(data);
			point->prev->next = this->top;
			this->top = point->prev;

		}
	}
	catch (const std::bad_alloc &be)
	{
		
		custom_Excep a(0, "Can`t organize memory for data");
		a.what();
		return;
	}
}
template<typename T>
void List::List<T>::Add_to_Tail(T data) {
	try
	{
		if (this->top == nullptr) {
			this->top = new elem(data);
		}
		else
		{
			elem* point = this->top;
			while (point->next != nullptr) {
				point = point->next;
			}
			point->next = new elem(data);
			point->next->prev = point;
		}
	}
	catch (const std::bad_alloc & be)
	{
		custom_Excep a(0, "Can`t organize memory for data");
		a.what();
		return;
	}
}
template<typename T>
void List::List<T>::Add_to_positition(T data, int position) {
	try
	{
		if (this->top == nullptr) {
			throw custom_Excep(10, "Your list is empty");
		}
		else
		{
			int i{ 0 };
			elem* point = this->top;
			elem* newnode;
			while (i<position-1) {
				point = point->next;
				if (point==nullptr)
				{
					throw custom_Excep(13, "No such position in list");
				}
				i++;
			}
			elem* temp_2 = point->next;
			newnode = new elem(data);
			newnode->prev = point;
			newnode->next = temp_2;
			point->next = newnode;
			temp_2->prev = newnode;
		}
	}
	catch (custom_Excep & a)
	{
		a.what();
		return ;
	}
	catch (const std::bad_alloc & be)
	{
		custom_Excep a(0, "Can`t organize memory for data");
		a.what();
		return;
	}
}
template<typename T>
void List::List<T>::Remove_from_head() {
	try
	{
		if (this->top == nullptr) {
			throw custom_Excep(10, "Your list is empty");
		}
		elem* point = this->top;
		if (point->next==nullptr)
		{
			delete point;
			point = nullptr;
			this->top = point;
		}
		else
		{
			this->top = point->next;
			delete point->next->prev;
			this->top->prev = nullptr;
		}
	}
	catch (custom_Excep & a)
	{
		a.what();
		return ;
	}
}
template<typename T>
void List::List<T>::Remove_from_tail() {
	try
	{
		if (this->top == nullptr) {
			throw custom_Excep(10, "Your list is empty");
		}
		elem* point = this->top;
		if (point->next == nullptr) {
			delete point;
			point = nullptr;
			this->top = point;
		}
		else
		{
			while (point->next->next != nullptr)
			{
				point = point->next;
			}
			delete point->next;
			point->next = nullptr;
		}
	}
	catch (custom_Excep & a)
	{
		a.what();
		return ;
	}

}
template<typename T>
void List::List<T>::Remove_position(int position) {
	try
	{
		if (this->top==nullptr)
		{
			throw custom_Excep(10, "Your list is empty");
		}
		else
		{
			int i{ 0 };
			elem* point = this->top;
			while (i<position-1)
			{
				point = point->next;
				i++;
				if (point == nullptr) {
					throw custom_Excep(13, "No such position in list");
				}
			}
			elem *temp = point->next->next;
			if (temp == nullptr) {
				this->Remove_from_tail();
			}
			else
			{
				delete temp->prev;
				temp->prev = point;
				point->next = temp;
			}
		}
	}
	catch (custom_Excep & a)
	{
		a.what();
		return ;
	}
}
template<typename T>
void List::List<T>::Remove_all() {
	try
	{
		if (this->top == nullptr) {
			throw custom_Excep(10, "Your list is empty");
		}
		while (this->top!=nullptr)
		{
			this->Remove_from_head();
		}
	}
	catch (custom_Excep & a)
	{
		a.what();
		return ;
	}
}
template<typename T>
T List::List<T>::Get_value_from_head() {
	try
	{
		if (this->top==nullptr)
		{
			throw custom_Excep(10, "Your list is empty");
		}
		return this->top->data;
	}
	catch (custom_Excep & a)
	{
		a.what();
		return 0;
	}
}
template<typename T>
T List::List<T>::get_value_from_tail() {
	try
	{
		if (this->top == nullptr)
		{
			throw custom_Excep(10,"Your list is empty");
		}
		elem* point = this->top;
		while (point->next!=nullptr)
		{
			point = point->next;
		}
		return point->data;
	}
	catch (custom_Excep &a)
	{
		a.what();
		return 0;
	}
}
template<typename T>
T List::List<T>::Get_value_from_position(int position) {
	excep g;
	g.Init();
	try
	{
		if (position < 0||this->top==nullptr) {
			throw 5;
		}
		else if(position==0)
		{
			this->Get_value_from_head();
		}
		else
		{
			int i{ 0 };
			elem* point = this->top;
			while (i<position)
			{
				point = point->next;
				i++;
				if (point == nullptr) {
					throw 5;
				}
			}
			return point->data;
		}

	}
	catch (int a)
	{
		g.Search(a);
		g.Remove();
		return 0 ;
	}
}