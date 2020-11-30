#include "List.h"
#include <iostream>
#include <fstream>
#include "Array.h"
#include "Queue.h"   
#include "Tests.h"
using namespace std;

List_::List_() {
    first = nullptr;
    last = nullptr;
}

/// <summary>
/// Функция вывода списка
/// </summary>
/// <returns>Список в виде строки</returns>
char* List_::showList_front()             //показать список с начала
{
	int length = 0;
	int count = 0;
	if (last == nullptr) throw exception("List is empty!");
	Elem *p = last;
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
		str[j-1] = '\0';
	return str;
}

/// <summary>
/// Функция добавления элемента в конец списка
/// </summary>
/// <param name="obj"></param>
void List_::push_front(Array_* obj) {
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

/// <summary>
/// Функция добавления элемента в список по индексу
/// </summary>
/// <param name="obj">Элемент</param>
/// <param name="n">Индекс</param>
void List_::pushByIndex(Array_* obj,int n) {
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
	else{
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

/// <summary>
/// Удаление элемента из списка
/// </summary>
/// <param name="elem">Элемент</param>
void List_::deleteLink(Elem* elem)   //удаление звена из списка
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

/// <summary>
/// Удаление элемента из списка по индексу
/// </summary>
/// <param name="n">Индекс</param>
void List_::deleteByIndex(int n)   //удаление звена из списка
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

/// <summary>
/// Получить элемент списка
/// </summary>
/// <returns>Элемент, который получаем</returns>
Array_* List_::pop_front() {
	if (last == nullptr)
	{
		throw exception("List is empty!");
	}
	Elem* elem = first;
	Array_ *temp = elem->data;
	deleteLink(first);
	return temp;
}

/// <summary>
/// Поиск элемента по индексу
/// </summary>
/// <param name="n">Индекс</param>
/// <returns>Элемент, который ищем</returns>
Array_* List_::find(int n) {
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
	} while (q!=last);
	throw exception("Element not found!");
}

