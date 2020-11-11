#include "Queue.h"   
#include "Tests.h"
#include "Stack.h"
#include <iostream>

using namespace std;

bool Test::Test1_AddNegativeNumberOfElements(Array_ ar) {
    char expected = 'e';
    char actual = ar.addElem(0, 1, 5, 6);
    if (expected != actual)
    {
        cout << "Expected: " << expected << "\t" << "Actual: " << actual << endl;
        return false;
    }
    return true;
}


bool Test::Test2_IndexOutOfRange(Array_ ar) {
    out_of_range expected("Index out of range");

    try
    {
        ar.deleteElem(-1);
        cout << ar << endl;
        return 0;
    }
    catch (exception actual)
    {
        if (strcmp(expected.what(), actual.what()) == 0) {
            cout << expected.what() << endl;
            return true;
        }
    }
}