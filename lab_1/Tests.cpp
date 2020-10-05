#include "Array.h"   
#include "Tests.h"
#include <iostream>

using namespace std;

bool Test::Test1_Add_Elem(Array_ &actual) {

    //Expected
    int expected[10]{ 1,2,3,4,5,6,7,8,9,10 };

    //Actual
    actual.addElem(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);

    bool rez = true;
    std::cout << "Expected:\tActual:\n";
    for (int i = 0; i < 10; i++)
    {
        printf("%i\t\t%i\n", expected[i], actual.getElem(i));
        if (expected[i] != actual.getElem(i))
        {
            rez = false;
        }
    }

    return rez;
}

bool Test::Test2_Get_15th_Elem(Array_ &arr) {
    try
    {
        int actual = arr.getElem(15);
    }
    catch (const out_of_range&)
    {
        return false;
    }
    return true;    
}
bool Test::Test3_Get_5th_Elem(Array_ &arr) {
    try
    {
        int actual = arr.getElem(5);
    }
    catch (const out_of_range&)
    {
        return false;
    }
    return true;
}

bool Test::Test4_Search_6(Array_ &arr) {
    int expected = 5;

    int actual = arr.searchElem(6);

    if (expected == actual)
    {
        return true;
    }
    else return false;
}

bool Test::Test5_Search_16(Array_ &arr) {
    int expected = -1;

    int actual = arr.searchElem(16);

    if (expected == actual)
    {
        return true;
    }
    else {
        std::cout << "\nExpected: " << expected << "; Actual: " << actual << std::endl;
        return false;
    }
}

bool Test::Test6_Delete_5th_Elem(Array_ &actual) {
    int expected[10]{ 1,2,3,4,5,7,8,9,10 };
    try
    {
        actual.deleteElem(5);
    }
    catch (const std::out_of_range&)
    {
        cout << "Out of range";
        return false;
    }

    bool rez = true;

    std::cout << "Expected:\tActual:\n";
    for (int i = 0; i < 9; i++)
    {
        printf("%i\t\t%i\n", expected[i], actual.getElem(i));
        if (expected[i] != actual.getElem(i))
        {
            cout << "Wrong answer";
            rez = false;
        }
    }
    return rez;
}

bool Test::Test7_Replace_4th_Elem_To_11(Array_ &actual) {
    int expected[10]{ 1,2,3,4,11,7,8,9,10 };
   
    actual.replaceElem(4, 11);

    if (expected[4] == actual.getElem(4))
    {
        return true;
    }
    else {
        std::cout << "\nExpected: " << expected[4] << "; Actual: " << actual.getElem(4) << std::endl;
        return false;
    }
}

bool Test::Test8_toString(Array_ arr) {
    char* expected = new char[256]{"1, 2, 3, 4, 11, 7, 8, 9, 10"};

    char* actual = arr.toString();
            
    cout << endl << "Expected: " << expected << endl << "Actual:   " << actual;

    if (strcmp(expected, actual) == 0) {
        return true;
    }
    else {
        return false;
    }
}