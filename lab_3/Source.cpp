#include "Array.h"
#include "Tests.h"
#include <iostream>
#include <fstream>
using namespace std;

void main(){

    Array_ arr1;
    Array_ arr2;
    arr1.addElem(5, 1, 2, 3, 4, 5);
    arr2.addElem(3, 10, 20, 30);

    Test test;

    cout << "Test1: " << test.Test1_WriteAndReadTextFile(arr1)<<"\n\n";
    cout << "Test2: " << test.Test2_WriteAndReadBinFile(arr1) << "\n\n";

    int wait;
    std::cin >> wait;
}