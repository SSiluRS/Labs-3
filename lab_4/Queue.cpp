
#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue(int arrSize, int curElemNum): Array_(arrSize, curElemNum), first(0), last(0) {}

Queue::Queue(const Queue& obj) :Array_(obj) {
	this->first = obj.first;
	this->last = obj.last;
}

bool Queue::full() const {
	return (last+1) % (arrSize+1) == first;
}

bool Queue::empty() const {
	return first == last;
}

int Queue::getFirstElem() const {
	return point[first];
}

int Queue::getLastElem()  const {
	return point[last];
}

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

Queue::~Queue() {}