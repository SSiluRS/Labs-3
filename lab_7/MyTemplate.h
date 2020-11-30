#include<sstream>

#pragma once
template<class T>
class Template_
{
	class Elem;
public:
	Template_() {
		first = nullptr;
		last = nullptr;
	}

	void push_front(T obj) {
		Elem* elem = new Elem();
		elem->data = obj;

		if (!first) {
			first = elem;
			last = elem;
		}
		elem->next = last;
		last->prev = elem;
		elem->prev = first;
		first->next = elem;
		first = elem;
	}

	void pushByIndex(T obj, int n) {
		Elem* elem = new Elem();
		elem->data = obj;
		if (!first && n == 0) {
			last = elem;
			first = elem;
			elem->next = elem;
			elem->prev = elem;
			return;
		}
		else if (!first) {

			throw exception("List is empty!");
		}
		Elem* q = last;
		if (n < 0) {
			throw exception("Incorrect parameters!");
		}
		else {
			int i = 0;
			do {

				if (i == n) {
					break;
				}
				q = q->next;
				i++;
				if (q == last)
				{
					throw exception("Index out of bounds!");
				}
			} while (q != last && i < n);
		}
		elem->prev = q->prev;
		elem->next = q->next;
		q->next->prev = elem;
		q->prev->next = elem;
		if (q == last) {
			last = elem;
		}
		if (q == first) {
			first = elem;
		}
		delete q;
	}

	T pop_front() {
		if (last == nullptr)
		{
			throw exception("List is empty!");
		}
		Elem* elem = first;
		T temp = elem->data;
		deleteLink(first);
		return temp;
	}

	void deleteLink(Elem* elem)   //удаление звена из списка
	{
		if (elem == nullptr) {
			throw exception("Incorrect parameter!");
		}

		if (elem->next == elem)    //если в списке единственный элемент
		{
			first = NULL;
			last = NULL;
		}
		else
		{
			if (elem == last) {     //если эдемент на удаление последний
				(last->prev)->next = last->next;
				last = last->next;

			}

			if (elem == first)     //если элемент на удаление первый
			{
				first = first->prev;
				first->next = last;
			}

			(elem->next)->prev = elem->prev;
			(elem->prev)->next = elem->next;

			delete[] elem;
		}

	}

	void deleteByIndex(int n)   //удаление звена из списка
	{
		Elem* el;
		if (n < 0) {
			throw exception("Incorrect parameter!");
		}
		else {
			el = last;
			int i = 0;
			do {

				if (i == n) {
					break;
				}
				el = el->next;
				i++;
				if (el == last)
				{
					throw exception("Element not found!");
				}
			} while (el != last && i < n);

			if (el->next == el)    //если в списке единственный элемент
			{
				first = NULL;
				last = NULL;
			}
			else
			{
				if (el == last) {     //если эдемент на удаление последний
					(last->prev)->next = last->next;
					last = last->next;

				}

				if (el == first)     //если элемент на удаление первый
				{
					first = first->prev;
					first->next = last;
				}

				(el->next)->prev = el->prev;
				(el->prev)->next = el->next;

				delete[] el;
			}
		}

	}

	char* showList_front();

	T find(double n);

private:
	friend class Test;
	class Elem {
	public:
		//”казатель на объект
		T data = NULL;

		//”казатель на следующий элемент списка
		Elem* next = NULL;

		//”казатель на предыдущий элемент списка
		Elem* prev = NULL;
	};
	Elem* first;
	Elem* last;
};

template <class T>
char* Template_<T>::showList_front()           //показать список с начала
{
	int N = 256;
	int length = 0;
	int count = 0;
	if (last == nullptr) throw exception("List is empty!");

	Elem* p = last;
	std::stringstream s;
	int j = 0;
	if (first)
		do
		{
			s << p->data << " ";
			p = p->next;
		} while (p != last);

		char* str = _strdup(s.str().c_str());
		str[strlen(str)-1] = '\0';
		return str;
}

template <>
char* Template_<Array_*>::showList_front()           //показать список с начала
{
	int length = 0;
	int count = 0;
	if (last == nullptr) throw exception("List is empty!");
	Elem* p = last;
	do
	{
		length += strlen(p->data->toString());
		count++;
		p = p->next;
	} while (p != last);
	length += count;

	char* str = new char[length];
	p = last;
	int j = 0;
	if (first)
		do
		{
			char* strPut;
			strPut = p->data->toString();
			for (int i = 0; i < strlen(strPut); i++)
			{
				str[j] = strPut[i];
				j++;
			}
			str[j] = ' ';
			j++;
			p = p->next;
		} while (p != last);
		str[j - 1] = '\0';
		return str;
}

template <class T>
T Template_<T>::find(double n)
{
	Elem* q = last;
	do
	{
		if (q->data == n)
		{
			return q->data;
		}
		q = q->next;
	} while (q != last);
	throw exception("Element not found!");
}


template <> 
Array_* Template_<Array_*>::find(double n)
{
	Elem* q = last;
	do
	{
		int arrSize = q->data->getArrSize();
		for (int i = 0; i < arrSize; i++)
		{
			int el = q->data->getElem(i);
			if (n == el)
			{
				return q->data;
			}
		}
		q = q->next;
	} while (q != last);
	throw exception("Element not found!");
}