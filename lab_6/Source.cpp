#include "Array.h"
#include "Tests.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
using namespace std;

void main(){
        
    Array_ ar;
    ar.addElem(5, 1, 2, 3, 4, 5);

    Test test;

    cout << "Test1: " << test.Test1_AddNegativeNumberOfElements(ar) << "\n\n";
    cout << "Test2: " << test.Test2_IndexOutOfRange(ar) << "\n\n";

    int wait;
    std::cin >> wait;
}