#include "Array.h"

using namespace std;
#pragma once

#define _CRT_SECURE_NO_WARNINGS

class Stack : public Array_ {
public:
    Stack(int arrSize = 5, int curElemNum = 0);
    Stack(const Stack& obj);
    ~Stack();
    bool empty() const;
    bool full()  const;
    int  getFirstElem() const;
    int  getLastElem()  const;
    char  pop();
    char enqueue(int value);
private:
    unsigned int first;
    unsigned int last;
};
