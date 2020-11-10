#include "Queue.h"   
#include "Tests.h"
#include "Stack.h"
#include <iostream>

using namespace std;

bool Test::Test1_Queue_EnqueueAndPop(Queue& qq) {
    int* expected = new int[5]{ 5,4,3,2,1 };

    int* actual = new int[5];
    char a;
    try {
        for (int i = 0; i < 5; i++)
        {
            a = qq.pop();
            if (a == 'e') throw exception("Stack is empty");
            actual[i] = a;
        }
        for (int i = 0; i < 5; i++)
        {
            if (actual[i] != expected[i]) {
                cout << "Actual:" << "\t" << "Expected:" << endl;
                for (int i = 0; i < 5; i++)
                {
                    cout << actual[i] << "\t" << expected[i] << endl;
                }
                return false;
            }
        }
    }
    catch (exception e) {
        cout << e.what() << endl;
        return false;
    }
    return true;
}


bool Test::Test2_Stack_EnqueueAndPop(Stack& ss) {
    int* expected = new int[5]{ 1,2,3,4,5 };

    int* actual = new int[5];
    char a;
    try {
        for (int i = 0; i < 5; i++)
        {
            a = ss.pop();
            if (a == 'e') throw exception("Stack is empty");
            actual[i] = a;
        }
        for (int i = 0; i < 5; i++)
        {
            if (actual[i] != expected[i]) {
                cout << "Actual:" << "\t" << "Expected:" << endl;
                for (int i = 0; i < 5; i++)
                {
                    cout << actual[i] << "\t" << expected[i] << endl;
                }
                return false;
            }
        }
    }
    catch (exception e) {
        cout << e.what() << endl;
        return false;
    }
    return true;
}

bool Test::Test3_PopEmptyQueue(Queue& qq) {
    char expected = 'e';

    char actual = qq.pop();
    
    if (actual == expected) return true;

    else {
        cout << "Expected: " << expected << "\t" << "Actual: " << actual << endl;
        return false;
    }

}

bool Test::Test4_EnqueueFullQueue() {
    Queue qq(1, 0);
    qq.enqueue(1);

    char expected = 'e';

    char actual = qq.enqueue(5);

    if (actual == expected) return true;
    else {
        cout << "Expected: " << expected << "\t" << "Actual: " << actual << endl;
        return false;
    }

}

bool Test::Test5_PopEmptyStack(Stack& qq) {
    char expected = 'e';

    char actual = qq.pop();

    if (actual == expected) return true;
    else {
        cout << "Expected: " << expected << "\t" << "Actual: " << actual << endl;
        return false;
    }

}

bool Test::Test6_EnqueueFullStack() {
    Stack ss(1, 0);
    ss.enqueue(1);

    char expected = 'e';

    char actual = ss.enqueue(5);

    if (actual == expected) return true;
    else {
        cout <<"Expected: "<<expected<<"\t"<< "Actual: " << actual << endl;
        return false;
    }

}