#include "Queue.h"   
#include "Tests.h"
#include "Stack.h"
#include "List.h"
#include <iostream>

using namespace std;

bool Test::Test1_Push_and_Pop_Front() {
    Stack* expected = new Stack(5,0);
    expected->enqueue(1);
    expected->enqueue(3);
    expected->enqueue(3);
    expected->enqueue(4);
    expected->enqueue(5);

    List_ ls;
    ls.push_front(expected);
    Array_* actual = ls.pop_front();
    if (expected != actual)
    {
        cout << "Expected: " << expected->toString() << "\t" << "Actual: " << actual->toString() << endl;
        return false;
    }
    return true;
}

bool Test::Test2_Push_By_Index() {
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
        List_ ls;
        ls.push_front(ar);
        ls.push_front(ar1);
        ls.pushByIndex(expected, n);
        List_::Elem* q = ls.last;
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
        if (strcmp(q->data->toString(), expected->toString()) != 0)
        {
            return 0;
        }
        return 1;
    }
    catch (exception e) {
        cout << e.what() << endl;
        return 0;
    }
}

bool Test::Test3_Delete_By_Index() {
    try
    {
        List_ expected;

        Array_* ar = new Array_();
        ar->addElem(3, 2, 2, 2);
        Array_* ar1 = new Array_();
        ar1->addElem(3, 3, 3, 3);
        Array_* ar2 = new Array_();
        ar1->addElem(3, 1, 1, 1);

        int n = 1;
        List_ ls;
        ls.push_front(ar);
        ls.push_front(ar1);
        ls.push_front(ar2);

        expected.push_front(ar);
        expected.push_front(ar2);

        ls.deleteByIndex(1);

        auto actual = ls.showList_front();
        if (strcmp(expected.showList_front(), actual)!=0)
        {
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

bool Test::Test4_Find() {
    try
    {
        Array_* ar = new Array_();
        ar->addElem(3, 2, 2, 2);

        Array_* expected;
        expected = ar;

        List_ ls;

        Array_* ar1 = new Array_();
        ar1->addElem(3, 3, 3, 3);
        Array_* ar2 = new Array_();
        ar1->addElem(3, 1, 1, 1);

        ls.push_front(ar1);
        ls.push_front(ar);
        ls.push_front(ar2);

        auto actual = ls.find(2);

        if (strcmp(expected->toString(),actual->toString())!=0)
        {
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

bool Test::Test5_Find_Err() {
    try
    {
        Array_* ar = new Array_();
        ar->addElem(3, 2, 2, 2);

        Array_* expected;
        expected = ar;

        List_ ls;

        Array_* ar1 = new Array_();
        ar1->addElem(3, 3, 3, 3);
        Array_* ar2 = new Array_();
        ar1->addElem(3, 1, 1, 1);

        ls.push_front(ar1);
        ls.push_front(ar);
        ls.push_front(ar2);

        auto actual = ls.find(4);

        if (strcmp(expected->toString(), actual->toString()) != 0)
        {
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
