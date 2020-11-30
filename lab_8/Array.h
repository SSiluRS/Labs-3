#include <iostream>
#include <fstream>

using namespace std;
#pragma once

#define _CRT_SECURE_NO_WARNINGS


class Array_ {
public:
    Array_(int arrSize=0, int curElemNum=0);
    Array_(const Array_& obj);
    ~Array_();
    virtual char* toString();
    char addElem(unsigned int num, int first, ...);
    void replaceElem(int position, int newElem);
    void deleteElem(int position);
    int searchElem(int elem);
    int getElem(int position);
    int getArrSize();
    int getCurElemNum();
    static int arr_count;
    int& operator[](const int index);
    friend Array_ operator+(Array_& ar1, Array_& ar2);
    friend Array_ operator-(const Array_& ar1, int elem);
    void operator=(const Array_& ar);
    Array_& operator--();
    friend ostream& operator<<(ostream& os, Array_& ar);
    friend istream& operator>>(istream& is, Array_& ar);
    friend ifstream& operator>> (ifstream& is, Array_& ar);
    void writeToBinFile(char* path);
    void readFromBinFile(char* path);
    friend bool operator<(const Array_& ar1, const Array_& ar2);

private:
    friend class Queue;
    friend class Stack;
    void addChar(char*& str, int& i, int& strLen, int& N);
    void changeArrSize(int newSize);
protected:
    int arrSize;
    int curElemNum;
    int* point;
};