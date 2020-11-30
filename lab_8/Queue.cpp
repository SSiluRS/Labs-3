
#include "Queue.h"
#include <iostream>

using namespace std;
/// <summary>
/// Конструктор по умолчанию с параметрами
/// </summary>
/// <param name="arrSize"></param>
/// <param name="curElemNum"></param>
Queue::Queue(int arrSize, int curElemNum): Array_(arrSize, curElemNum), first(0), last(0) {}

/// <summary>
/// Конструктор копирования
/// </summary>
/// <param name="obj"></param>
Queue::Queue(const Queue& obj) :Array_(obj) {
	this->first = obj.first;
	this->last = obj.last;
}

/// <summary>
/// Метод проверки на заполненность очереди
/// </summary>
/// <returns></returns>
bool Queue::full() const {
	return (last+1) % (arrSize+1) == first;
}
/// <summary>
/// Метод проверки на пустоту очереди
/// </summary>
/// <returns></returns>
bool Queue::empty() const {
	return first == last;
}
/// <summary>
/// Метод получения первого элемента очереди
/// </summary>
/// <returns></returns>
int Queue::getFirstElem() const {
	return point[first];
}

/// <summary>
/// Метод получения последнего элемента очереди
/// </summary>
/// <returns></returns>
int Queue::getLastElem()  const {
	return point[last];
}

/// <summary>
/// Метод вытаскивания элементов стека по принципу FIFO
/// </summary>
/// <returns></returns>
char Queue::pop() {
	try {
		if (empty()) throw exception("Stack is empty");
		int x = point[last - 1];
		last = (last - 1);
		return x;
	}
	catch (exception e) {
		cout << e.what() << endl;
		return 'e';
	}
}
 
/// <summary>
/// Помещение очередного элемента в очередь
/// </summary>
/// <param name="value"></param>
/// <returns></returns>
char Queue::enqueue(int value) {
	try {
		if (full()) throw exception("Queue is full");
		if (point == nullptr) {
			point = new int[arrSize];
		}
		point[last] = value;
		last = (last + 1) % (arrSize + 1);
		return last;
	}
	catch (exception e) {
		cout << e.what() << endl;
		return 'e';
	}
}
/// <summary>
/// Фукнция вывода очереди
/// </summary>
/// <returns>Очередь в виде строки</returns>
char* Queue::toString() {
	char* str1 = new char[256]{ "\ntoString func from Queue: " };
	int N = 5;
	char* str = new char[N] {0};
	int strLen = 0;
	int i = 0;
	for (curElemNum = 0; curElemNum < arrSize; curElemNum++)
	{
		Array_::addChar(str, i, strLen, N);
	}
	str[i - 1] = '\0';
	curElemNum = 0;
	strcat_s(str1, strlen(str) + strlen(str1) + 2, str);
	strcat_s(str, strlen(str) + 3, "\n");
	return str1;
}

Queue::~Queue() {}