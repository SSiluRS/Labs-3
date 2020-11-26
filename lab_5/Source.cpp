#include "Array.h"
#include "Tests.h"
#include "Queue.h"
#include "Stack.h"
#include "List.h"
#include <iostream>
#include <fstream>
using namespace std;

void main(){
            
    Test test;
    cout << "Test1: " << test.Test1_Push_and_Pop_Front() << endl;
    cout << "Test2: " << test.Test2_Push_By_Index()<<endl;
    cout << "Test3: " << test.Test3_Delete_By_Index() << endl;
    cout << "Test4: " << test.Test4_Find() << endl;
    cout << "Test5: " << test.Test5_Find_Err() << endl;

    int wait;
    std::cin >> wait;
}