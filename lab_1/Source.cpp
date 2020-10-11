#include "Array.h"
#include "Tests.h"
#include <iostream>

void main()
{
    Array_ arr = Array_(10, 0);

    Test test;


    std::cout << "\nTest1: " << test.Test1_Add_Elem(arr) << std::endl;
    std::cout << "\nTest2: " << test.Test2_Get_15th_Elem(arr) << std::endl;
    std::cout << "\nTest3: " << test.Test3_Get_5th_Elem(arr) << std::endl;
    std::cout << "\nTest4: " << test.Test4_Search_6(arr) << std::endl;
    std::cout << "\nTest5: " << test.Test5_Search_16(arr) << std::endl << std::endl;
    std::cout << "\nTest6: " << test.Test6_Delete_5th_Elem(arr) << std::endl;
    std::cout << "\nTest7: " << test.Test7_Replace_4th_Elem_To_11(arr) << std::endl;
    std::cout << "\nTest8: " << test.Test8_toString(arr) << std::endl;
    std::cout << "\nTest9: " << test.Test9_Check_Static_Member(arr) << std::endl;


    int wait;
    std::cin >> wait;
}