#include <iostream>
#include <fstream>
#include "Array.h"
using namespace std;

int Array_::arr_count = 0;

Array_::Array_() {
    arrSize = 0;
    curElemNum = 0;
    point = nullptr;
    arr_count++;
}

Array_::Array_(int arrSize, int curElemNum) {
    this->arrSize = arrSize;
    this->curElemNum = curElemNum;
    this->point = new int[arrSize];
    arr_count++;
}

Array_::Array_(const Array_& obj) {
    this->arrSize = obj.arrSize;
    this->curElemNum = obj.curElemNum;
    point = new int[arrSize];
    copy(obj.point, obj.point + arrSize, this->point);
    arr_count++;
}

Array_::~Array_() {
    delete[] point;
    arr_count--;
}

char* Array_::addChar(char* str, int& i, bool last, int& strLen, int& N) {
    int elem = point[curElemNum];
    int len = elem == 0?1:0;
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
    for (curElemNum = 0; curElemNum < arrSize; curElemNum++)
    {
        if (curElemNum< arrSize-1)
        {            
            str = _strdup(addChar(str, i, false, strLen, N));
        }
        else {
            str = _strdup(addChar(str, i, true, strLen, N));
        }
    }
    curElemNum = 0;
    str[i] = 0;
    /*char* res = new char[strLen + 1];
    res = _strdup(str);
    delete[] str;*/
    return str;
}

void Array_::addElem(unsigned int num, int first, ...) {
    int lastElemNum;
    if (num > 0) {
        if (point == nullptr){
            point = new int[num];
            arrSize = num;
            lastElemNum = 0;
        }
        else {
            lastElemNum = arrSize;
        }
        int* p = &first;
        while (num--) {

            if (lastElemNum + 1 < arrSize) {
                point[lastElemNum] = *p;
                lastElemNum++;
            }
            else {
                arrSize *= 2;
                point = (int*)realloc(point, sizeof(int) * arrSize);
                point[lastElemNum] = *p;
                lastElemNum++;

                /*int* pointTemp = new int[arrSize];
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
                delete[] pointTemp;*/
            }
            p++;
        }
        arrSize = lastElemNum;
        point = (int*)realloc(point, sizeof(int) * arrSize);
    }
    else printf("The number of new elements cannot be negative!");

    /*arrSize = lastElemNum+1;
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
    delete[] pointTemp;*/
}

void Array_::replaceElem(int position, int newElem) {
    if (position < arrSize && position >= 0) {
        point[position] = newElem;
    }
    else printf("Index outside the array");
}

void Array_::deleteElem(int position) {
    if (position < arrSize && position >= 0) {
        for (curElemNum = position; curElemNum < arrSize; curElemNum++)
        {
            point[curElemNum] = point[curElemNum + 1];
        }
        curElemNum = 0;

        changeArrSize(arrSize - 1);
    }
    else throw out_of_range("Index out of range");
}

int Array_::searchElem(int elem) {
    while (true)
    {
        if (point[curElemNum] == elem) {
            return curElemNum;
        }
        if (curElemNum == arrSize-1 && point[curElemNum] != elem) {
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

int Array_::getCurElemNum() {
    return curElemNum;
}

void Array_::changeArrSize(int newSize) {

    arrSize = newSize;
    point = (int*)realloc(point, sizeof(int) * arrSize);
}

int& Array_::operator[](const int index) {
    if (index >= 0 && index < arrSize) {
        return point[index];
    }
    else throw out_of_range("Index out of range");
}

Array_ operator+(Array_& ar1, Array_& ar2) {
    int sz1 = ar1.arrSize;
    int sz2 = ar2.arrSize;
    Array_ ar3 = ar1;

    ar3.changeArrSize(sz1 + sz2);
    for (int i = 0; i < sz2; i++)
    {
        ar3[i + sz1] = ar2[i];
    }
    return ar3;
}

void Array_::operator=(const Array_& ar) {
    this->arrSize = ar.arrSize;
    this->curElemNum = ar.curElemNum;
    point = new int[arrSize];
    copy(ar.point, ar.point + arrSize, this->point);
}

Array_& Array_::operator--() {
    for (curElemNum = 0; curElemNum < arrSize; curElemNum++)
    {
        point[curElemNum]--;
    }
    return *this;
}

Array_ operator-(const Array_& ar1, int elem) {
    Array_ rez = ar1;
    int i = rez.searchElem(4);
    rez.deleteElem(i);
    return rez;
}

ostream& operator<<(ostream& os, Array_ &ar) {
    os << "Array size = " << ar.getArrSize() << "\nCurrent element number = " << ar.getCurElemNum() << "\nArray: " << ar.toString();
    return os;
}

istream& operator>>(istream& is, Array_ &ar) {
    int arrsize;
    cout << "Enter array size: ";
    is >> arrsize;
    for (int i = 0; i < arrsize; i++)
    {
        int elem;
        cout << endl << "Enter elem to add: ";
        is>> elem;
        ar.addElem(1, elem);
    }
    return is;
}

ofstream& operator<<(ofstream& os, Array_& ar) {
    os << ar.getArrSize() << " " << ar.getCurElemNum();
    for (int i = 0; i < ar.getArrSize(); i++)
    {
        os << " " << ar.getElem(i);
    }
    return os;
}

ifstream& operator>> (ifstream& is, Array_& ar) {
    int arrsize;
    is >> arrsize;
    is >> ar.curElemNum;
    for (int i = 0; i < arrsize; i++)
    {
        int elem;
        is >> elem;
        ar.addElem(1, elem);
    }
    return is;
}

void Array_::writeToBinFile(char* path) {
    ofstream bin_file(path);
    if (bin_file.fail()) {
        throw exception("Cannot open the file to write");
        return;
    }
    bin_file.write((char*)&(*this), sizeof(Array_));
    bin_file.close();
}

void Array_::readFromBinFile(char* path) {
    ifstream bin_file(path);
    if (bin_file.fail()) {
        throw exception("Cannot open the file to read");
        return;
    }
    Array_ ar;
    bin_file.read((char*)&ar, sizeof(Array_));
    *this = ar;
    bin_file.close();

}
