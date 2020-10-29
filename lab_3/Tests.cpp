#include "Array.h"   
#include "Tests.h"
#include <iostream>

using namespace std;

bool Test::Test1_WriteAndReadTextFile(Array_& ar) {
    char* path = new char[] { "..//text.txt"};

    auto expected = ar;
    Array_ actual;

    ofstream f1(path);
    if (f1.fail()) {
        cout << "Error while opening the file for writing";
        return 0;
    }
    f1 << expected;
    f1.close();

    ifstream f2(path);
    if (f2.fail()) {
        cout << "Error while opening the file for reading";
        return 0;
    }
    f2 >> actual;

    f2.close();

    for (int i = 0; i < expected.getArrSize(); i++) {
        if (expected[i] != actual[i]) {
            cout << "Expected: " << expected << "\nActual: " << actual << endl;
            return 0;
        }
    }

    return true;
}


bool Test::Test2_WriteAndReadBinFile(Array_ &arr) {
    char* path = new char[] { "..//text_bin.bin"};

    Array_ expected = arr;
    Array_ actual;
    try {
        arr.writeToBinFile(path);
    }
    catch (const ofstream::failure&) {
        cout << "Error while opening the file for writing";
        return 0;
    }

    try {
        actual.readFromBinFile(path);
    }
    catch (const exception& e) {
        cout << e.what() << endl;
        return 0;
    }

    for (int i = 0; i < expected.getArrSize(); i++) {
        if (expected[i] != actual[i]) {
            cout << "Expected: " << expected<<"\n" << "\nActual: " << actual << endl;
            return 0;
        }
    }

    return true;    
}
