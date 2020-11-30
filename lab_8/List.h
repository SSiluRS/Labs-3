#include "Array.h"

#pragma once
class List_
{
	class Elem;
public:
	List_();
	void push_front(Array_* obj);
	void pushByIndex(Array_* obj, int n);
	Array_* pop_front();
	void deleteLink(Elem* elem = nullptr);
	void deleteByIndex(int n = -1);
	char* showList_front();
	Array_* find(int n);

private:
	friend class Test;
	class Elem {
	public:
		//”казатель на объект
		Array_* data = NULL;

		//”казатель на следующий элемент списка
		Elem* next = NULL;

		//”казатель на предыдущий элемент списка
		Elem* prev = NULL;
	};
	Elem* first;
	Elem* last;
};

