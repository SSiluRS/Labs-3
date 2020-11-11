
#include "Stack.h"
#include <iostream>

using namespace std;
/// <summary>
/// Конструктор по умолчанию с параметрами
/// </summary>
/// <param name="arrSize"></param>
/// <param name="curElemNum"></param>
Stack::Stack(int arrSize, int curElemNum) : Array_(arrSize, curElemNum), first(0), last(0) {}

/// <summary>
/// Конструктор копирования
/// </summary>
/// <param name="obj"></param>
Stack::Stack(const Stack& obj) : Array_(obj) {
	this->first = obj.first;
	this->last = obj.last;
}

/// <summary>
/// Метод проверки на заполненность стека
/// </summary>
/// <returns></returns>
bool Stack::full() const {
	return (last + 1) % (arrSize + 1) == first;
}
/// <summary>
/// Метод проверки на пустоту стека
/// </summary>
/// <returns></returns>
bool Stack::empty() const {
	return first == last;
}

/// <summary>
/// Метод получения первого элемента стека
/// </summary>
/// <returns></returns>
int Stack::getFirstElem() const {
	return point[first];
}

/// <summary>
/// Метод получения последнего элемента стека
/// </summary>
/// <returns></returns>
int Stack::getLastElem()  const {
	return point[last];
}

/// <summary>
/// Метод вытаскивания элементов стека по принципу FILO
/// </summary>	
/// <returns></returns>
char Stack::pop() {
	try {
		if (empty()) throw exception("Queue is empty");
		int x = point[first];
		first = (first + 1) % (arrSize + 1);
		return x;
	}
	catch (exception e) {
		cout << e.what() << endl;
		return 'e';
	}
}
 
/// <summary>
/// Помещение очередного элемента в стек
/// </summary>
/// <param name="value"></param>
/// <returns></returns>
char Stack::enqueue(int value) {
	try {
		if (full()) throw exception("Queue is full");
		if (point == nullptr) {
			point = new int[arrSize];
		}
		point[last] = value;
		last = (last + 1) % (arrSize + 1);
		return last+'0';
	}
	catch (exception e) {
		cout << e.what() << endl;
		return 'e';
	}
}

Stack::~Stack() {}