#include <iostream>
#include "Array.h"
using namespace std;

Array_::Array_() {
    arrSize = 0;
    curElemNum = 0;
    point = nullptr;
    lastElemNum = 0;
}

Array_::Array_(int arrSize, int curElemNum) {
    this->arrSize = arrSize;
    this->curElemNum = curElemNum;
    this->point = new int[arrSize];
    this->lastElemNum = -1;
}

Array_::Array_(const Array_& obj) {
    this->arrSize = obj.arrSize;
    this->curElemNum = obj.curElemNum;
    this->lastElemNum = obj.lastElemNum;
    point = new int[arrSize];
    std::copy(obj.point, obj.point + arrSize, this->point);
}

Array_::~Array_() {
    delete[] point;
}

char* addChar(int* point, int curElemNum, char* str, int& i, bool last, int& strLen, int& N) {
    int elem = point[curElemNum];
    int len = 0;
    char* str1 = new char[N];
    str1 = _strdup(str);
    while (elem) {
        elem /= 10;
        len++;
    }

    elem = point[curElemNum];

    for (int el = 0, j = len - 1; j >= 0; j--)
    {
        el = elem / pow(10, j);
        strLen += len + 2;

        if (strLen >= N) {
            char* strTemp = new char[N];
            N *= 2;
            strTemp = _strdup(str1);
            delete[] str1;
            str1 = new char[N];
            str1 = _strdup(strTemp);
        }

        str1[i++] = el + '0';
        elem %= (int)pow(10, j);
        str1[i] = '\0';
    }
    if (!last) {
        str1[i++] = ',';
        str1[i++] = ' ';
    }
    return str1;
}

char* Array_::toString() {
    int N = 5;
    char* str = new char[N]{0};
    int strLen = 0;
    int i = 0;
    for (curElemNum = 0; curElemNum < arrSize && curElemNum != lastElemNum + 1; curElemNum++)
    {
        if (curElemNum<lastElemNum)
        {            
            str = _strdup(addChar(point, curElemNum, str, i, false, strLen, N));
        }
        else {
            str = _strdup(addChar(point, curElemNum, str, i, true, strLen, N));
        }
    }
    curElemNum = 0;
    char* res = new char[strLen + 1];
    res = _strdup(str);
    delete[] str;
    return res;
}

void Array_::addElem(unsigned int num, int first, ...) {
    if (num > 0) {
        int* p = &first;
        while (num--) {

            if (lastElemNum + 1 < arrSize) {
                point[++lastElemNum] = *p;
            }
            else {
                arrSize *= 2;
                point = (int*)realloc(point, sizeof(char) * arrSize);
                point[++lastElemNum] = *p;

                int* pointTemp = new int[arrSize];
                arrSize *= 2;
                for (int i = 0; i < lastElemNum; i++)
                {
                    pointTemp[i] = point[i];
                }
                delete[] point;
                point = new int[arrSize];
                for (int i = 0; i < lastElemNum; i++)
                {
                    point[i] = pointTemp[i];
                }
                delete[] pointTemp;
            }
            p++;
        }
    }
    else printf("The number of new elements cannot be negative!");

    arrSize = lastElemNum+1;
    int* pointTemp = new int[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        pointTemp[i] = point[i];
    }
    delete[] point;

    point = new int[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        point[i] = pointTemp[i];
    }
    delete[] pointTemp;
}

void Array_::replaceElem(int position, int newElem) {
    if (position <= lastElemNum && position >= 0) {
        point[position] = newElem;
    }
    else printf("Index outside the array");
}

void Array_::deleteElem(int position) {
    if (position <= lastElemNum && position >= 0) {
        for (curElemNum = position; curElemNum < lastElemNum; curElemNum++)
        {
            point[curElemNum] = point[curElemNum + 1];
        }
        lastElemNum--;
        curElemNum = 0;
    }
    else throw out_of_range("Index out of range");
}

int Array_::searchElem(int elem) {
    while (true)
    {
        if (point[curElemNum] == elem) {
            return curElemNum;
        }
        if (curElemNum == lastElemNum && point[curElemNum] != elem) {
            printf("\nThe required element is not in the array");
            return -1;
        }
        curElemNum++;
    }
}

int Array_::getElem(int position) {
    if (position >= arrSize || position < 0)
    {
        throw out_of_range("Index out of range");
    }
    else
        return point[position];
}

int Array_::getArrSize() {
    return arrSize;
}
