
#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(int arrSize, int curElemNum) : Array_(arrSize, curElemNum), first(0), last(0) {}

Stack::Stack(const Stack& obj) : Array_(obj) {
	this->first = obj.first;
	this->last = obj.last;
}

bool Stack::full() const {
	return (last + 1) % (arrSize + 1) == first;
}

bool Stack::empty() const {
	return first == last;
}

int Stack::getFirstElem() const {
	return point[first];
}

int Stack::getLastElem()  const {
	return point[last];
}

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