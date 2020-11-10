#pragma once

#include "Stack.h"
#include "Queue.h"

class Test {
public:
    bool Test1_Queue_EnqueueAndPop(Queue &qq);
    bool Test2_Stack_EnqueueAndPop(Stack &ss);
    bool Test3_PopEmptyQueue(Queue& qq);
    bool Test4_EnqueueFullQueue();
    bool Test5_PopEmptyStack(Stack& qq);
    bool Test6_EnqueueFullStack();
};

