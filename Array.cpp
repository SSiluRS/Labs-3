#include <iostream>
#include "Array.h"
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

        void Array_::printArray() {
            printf("Array:\n");
            for (curElemNum = 0; curElemNum < arrSize && curElemNum != lastElemNum + 1; curElemNum++)
            {
                printf("%i\n", point[curElemNum]);
            }
            printf("\n");
            curElemNum = 0;
        }

        void Array_::addElem(unsigned int num, int first, ...) {
            if (num > 0) {
                int* p = &first;
                while (num--) {

                    if (lastElemNum + 1 < arrSize) {
                        point[++lastElemNum] = *p;
                    }
                    else {
                        point = (int*)realloc(point, arrSize * sizeof(int));
                        point[++lastElemNum] = *p;
                        arrSize = arrSize * sizeof(int);
                    }
                    p++;
                }
            }
            else printf("The number of new elements cannot be negative!");
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
            else printf("\nIndex outside the array");
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
            if (position <= lastElemNum && position >= 0) {
                return point[position];
            }
            else {
                printf("\nIndex outside the array");
                return -1;
            }
        }



    
