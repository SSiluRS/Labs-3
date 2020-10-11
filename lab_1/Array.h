#pragma once

#define _CRT_SECURE_NO_WARNINGS


class Array_ {
    public:
        Array_();
        Array_(int arrSize, int curElemNum);
        Array_(const Array_& obj);
        ~Array_();
        char* toString();
        void addElem(unsigned int num, int first, ...);
        void replaceElem(int position, int newElem);
        void deleteElem(int position);
        int searchElem(int elem);
        int getElem(int position);
        int getArrSize();
        static int arr_count;

    private:
        int arrSize;
        int curElemNum;
        int* point;
        int lastElemNum;
};
