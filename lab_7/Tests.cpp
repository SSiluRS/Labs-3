#include "Queue.h"   
#include "Tests.h"
#include "Stack.h"
#include "Array.h"
#include <iostream>
#include "MyTemplate.h"

using namespace std;

bool Test::Test1_Push_and_Pop_Front_MyClass() {
    Stack* expected = new Stack(5, 0);
    expected->enqueue(1);
    expected->enqueue(3);
    expected->enqueue(3);
    expected->enqueue(4);
    expected->enqueue(5);

    Template_<Array_*> ls;
    ls.push_front(expected);
    Array_* actual = new Array_(*(ls.pop_front()));
    if (strcmp(expected->toString(), actual->toString()) != 0)
    {
        cout << "Expected: " << expected->toString() << "\t" << "Actual: " << actual->toString() << endl;
        return false;
    }
    return true;
}

bool Test::Test2_Push_By_Index_MyClass() {
    try {
        Stack* expected = new Stack(5, 0);
        expected->enqueue(1);
        expected->enqueue(3);
        expected->enqueue(3);
        expected->enqueue(4);
        expected->enqueue(5);

        Array_* ar = new Array_();
        ar->addElem(3, 2, 2, 2);
        Array_* ar1 = new Array_();
        ar1->addElem(3, 3, 3, 3);

        int n = 1;
        Template_<Array_*> ls;
        ls.push_front(ar);
        ls.push_front(ar1);
        ls.pushByIndex(expected, n);
        int a = 12;
        Template_<Array_*>::Elem* q = ls.last;
        int i = 0;
        do
        {
            if (i == n) break;
            i++;
            q = q->next;
            if (q == ls.last) {
                return 0;
            }
        } while (q != ls.last);
        auto actual = new Array_(*(q->data));
        if (strcmp(actual->toString(), expected->toString()) != 0)
        {
            cout << "Expected: " << expected->toString() << "\t" << "Actual: " << actual->toString() << endl;
            return 0;
        }
        return 1;
    }
    catch (exception e) {
        cout << e.what() << endl;
        return 0;
    }
}

bool Test::Test3_Delete_By_Index_MyClass() {
    try
    {
        Template_<Array_*> expected;

        Array_* ar = new Array_();
        ar->addElem(3, 2, 2, 2);
        Array_* ar1 = new Array_();
        ar1->addElem(3, 3, 3, 3);
        Array_* ar2 = new Array_();
        ar1->addElem(3, 1, 1, 1);
        int n = 1;
        Template_<Array_*> ls;
        ls.push_front(ar);
        ls.push_front(ar1);
        ls.push_front(ar2);

        expected.push_front(ar);
        expected.push_front(ar2);

        ls.deleteByIndex(1);

        auto actual = ls.showList_front();
        
        if (strcmp(expected.showList_front(), actual) != 0)
        {
            cout << "Expected: " << expected.showList_front() << "\t" << "Actual: " << actual << endl;
            return 0;
        }
        return 1;
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
        return 0;
    }
}

bool Test::Test4_Find_MyClass() {
    try
    {
        Array_* ar = new Array_();
        ar->addElem(3, 2, 2, 2);

        Array_* expected;
        expected = ar;

        Template_<Array_*> ls;

        Array_* ar1 = new Array_();
        ar1->addElem(3, 3, 3, 3);
        Array_* ar2 = new Array_();
        ar1->addElem(3, 1, 1, 1);

        ls.push_front(ar1);
        ls.push_front(ar);
        ls.push_front(ar2);

        auto actual = ls.find(2.0);

        if (strcmp(expected->toString(), actual->toString()) != 0)
        {
            cout << "Expected: " << expected->toString() << "\t" << "Actual: " << actual->toString() << endl;
            return 0;
        }
        return 1;
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
        return 0;
    }
}

bool Test::Test5_Push_and_Pop_Front_Int() {
    Template_<int> ls;

    Array_ ar;
    for (int i = 0; i < 10; i++)
    {
        ar.addElem(1,i);
        ls.push_front(ar.getElem(i));
    }
    auto expected = ar.toString();
    auto actual = ls.showList_front();
    if (strcmp(expected, actual) != 0)
    {
        cout << "Expected: " << expected << "\t" << "Actual: " << actual << endl;
        return false;
    }
    return true;
}

bool Test::Test6_Push_By_Index_Int() {
    try {

        Template_<int> ls;

        Array_ ar;
        ar.addElem(3, 2, 2, 2);


        int n = 1;
        ls.push_front(2);
        ls.push_front(2);
        ls.push_front(2);
        ls.pushByIndex(1, n);
        auto actual = ls.showList_front();
        ar.replaceElem(1, 1);
        auto expected = ar.toString();

        if (strcmp(actual, expected) != 0)
        {
            cout << "Expected: " << expected << "\t" << "Actual: " << actual << endl;
            return 0;
        }
        return 1;
    }
    catch (exception e) {
        cout << e.what() << endl;
        return 0;
    }
}

bool Test::Test7_Delete_By_Index_Int() {
    try
    {
        Template_<int> ls;

        Array_ ar;
        ar.addElem(2, 2, 2);

        ls.push_front(2);
        ls.push_front(2);
        ls.push_front(2);

        ls.deleteByIndex(2);

        auto actual = ls.showList_front();
        auto expected = ar.toString();

        if (strcmp(expected, actual) != 0)
        {
            cout << "Expected: " << expected << "\t" << "Actual: " << actual << endl;
            return 0;
        }
        return 1;
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
        return 0;
    }
}

bool Test::Test8_Find_Int() {
    try
    {
        Array_* ar = new Array_();
        ar->addElem(3, 2, 3, 2);

        auto expected = 3;

        Template_<int> ls;

        ls.push_front(2);
        ls.push_front(3);
        ls.push_front(2);

        auto actual = ls.find(3);

        if (expected != actual)
        {
            cout << "Expected: " << expected<< "\t" << "Actual: " << actual<< endl;
            return 0;
        }
        return 1;
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
        return 0;
    }
}

bool Test::Test9_Push_and_Pop_Front_Double() {
    Template_<double> ls;

    Array_ ar;
    for (int i = 0; i < 10; i++)
    {
        ar.addElem(1, i+0.5);
        ls.push_front(ar.getElem(i+0.5));
    }
    auto expected = ar.toString();
    auto actual = ls.showList_front();
    if (strcmp(expected, actual) != 0)
    {
        cout << "Expected: " << expected << "\t" << "Actual: " << actual << endl;
        return false;
    }
    return true;
}

bool Test::Test10_Push_By_Index_Double() {
    try {

        Template_<double> ls;

        char expected[] = "2.2 1.1 2.2";


        double n = 1;
        ls.push_front(2.2);
        ls.push_front(2.2);
        ls.push_front(2.2);
        ls.pushByIndex(1.1, n);
        auto actual = ls.showList_front();

        if (strcmp(actual, expected) != 0)
        {
            cout << "Expected: " << expected << "\t" << "Actual: " << actual << endl;
            return 0;
        }
        return 1;
    }
    catch (exception e) {
        cout << e.what() << endl;
        return 0;
    }
}

bool Test::Test11_Delete_By_Index_Double() {
    try
    {
        Template_<double> ls;

        char expected[] = "2.2 2.2";

        ls.push_front(2.2);
        ls.push_front(2.2);
        ls.push_front(2.2);

        ls.deleteByIndex(2);

        auto actual = ls.showList_front();

        if (strcmp(expected, actual) != 0)
        {
            cout << "Expected: " << expected << "\t" << "Actual: " << actual << endl;
            return 0;
        }
        return 1;
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
        return 0;
    }
}

bool Test::Test12_Find_Double() {
    try
    {
        auto expected = 3.3;

        Template_<double> ls;

        ls.push_front(2.2);
        ls.push_front(3.3);
        ls.push_front(2.2);

        auto actual = ls.find(3.3);

        if (expected != actual)
        {
            cout << "Expected: " << expected << "\t" << "Actual: " << actual << endl;
            return 0;
        }
        return 1;
    }
    catch (const std::exception& e)
    {
        cout << e.what() << endl;
        return 0;
    }
}
