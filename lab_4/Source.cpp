#include "Array.h"
#include "Tests.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
using namespace std;

void main(){
        
    Queue q1;

    try {
        q1.enqueue(1);
        q1.enqueue(2);
        q1.enqueue(3);
        q1.enqueue(4);
        q1.enqueue(5);
    }
    catch (exception e) {
        cout << e.what() << endl;
    }

    Stack s1;
    try {
        s1.enqueue(1);
        s1.enqueue(2);
        s1.enqueue(3);
        s1.enqueue(4);
        s1.enqueue(5);
    }
    catch (exception e) {
        cout << e.what() << endl;
    }

    Test test;

    cout << "Test1: " << test.Test1_Queue_EnqueueAndPop(q1) << "\n\n";
    cout << "Test2: " << test.Test2_Stack_EnqueueAndPop(s1) << "\n\n";
    cout << "Test3: " << test.Test3_PopEmptyQueue(q1) << "\n\n";
    cout << "Test4: " << test.Test4_EnqueueFullQueue() << "\n\n";
    cout << "Test5: " << test.Test5_PopEmptyStack(s1) << "\n\n";
    cout << "Test6: " << test.Test6_EnqueueFullStack() << "\n\n";

    int wait;
    std::cin >> wait;
}