#include "Array.h"

using namespace std;
#pragma once

#define _CRT_SECURE_NO_WARNINGS

class Queue : public Array_ {

public:
    Queue(int arrSize=5, int curElemNum=0);
    Queue(const Queue& obj);
    ~Queue();
    bool empty() const;
    bool full()  const;
    int  getFirstElem() const;
    int  getLastElem()  const;
    char  pop();
    char enqueue(int value);
    char* toString() override;
private:
    friend class Array_;
    unsigned int first;
    unsigned int last;
};