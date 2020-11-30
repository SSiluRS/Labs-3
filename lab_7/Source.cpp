
#include "Tests.h"

#include <iostream>
#include <fstream>
using namespace std;

void main(){
            
    Test test;
    cout << "Test1: " << test.Test1_Push_and_Pop_Front_MyClass() << endl;
    cout << "Test2: " << test.Test2_Push_By_Index_MyClass()<<endl;
    cout << "Test3: " << test.Test3_Delete_By_Index_MyClass() << endl;
    cout << "Test4: " << test.Test4_Find_MyClass() << endl;
    cout << "Test5: " << test.Test5_Push_and_Pop_Front_Int() << endl;
    cout << "Test6: " << test.Test6_Push_By_Index_Int() << endl;
    cout << "Test7: " << test.Test7_Delete_By_Index_Int() << endl;
    cout << "Test8: " << test.Test8_Find_Int() << endl;
    cout << "Test9: " << test.Test9_Push_and_Pop_Front_Double() << endl;
    cout << "Test10: " << test.Test10_Push_By_Index_Double() << endl;
    cout << "Test11: " << test.Test11_Delete_By_Index_Double() << endl;
    cout << "Test12: " << test.Test12_Find_Double() << endl;

    

    int wait;
    std::cin >> wait;
}