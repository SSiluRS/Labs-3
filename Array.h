#pragma once

#ifndef _Array_h
#define _CRT_SECURE_NO_WARNINGS
#define _Array_h

class Array_ {
    private:
        int arrSize;
        int curElemNum;
        int* point;
        int lastElemNum;
    public:
        Array_();
        Array_(int arrSize, int curElemNum);
        Array_(const Array_& obj);
        ~Array_();
        void printArray();
        void addElem(unsigned int num, int first, ...);
        void replaceElem(int position, int newElem);
        void deleteElem(int position);
        int searchElem(int elem);
        int getElem(int position);
};

#endif
