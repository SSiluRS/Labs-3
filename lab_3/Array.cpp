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

    /// <summary>
    /// Вспомогательный метод для сторокового представления массива. Добавляет любое int значение в строку
    /// </summary>
    /// <param name="str"></param>
    /// <param name="i"></param>
    /// <param name="strLen"></param>
    /// <param name="N"></param>
    /// <returns></returns>
    char* Array_::addChar(char* str, int& i, int& strLen, int& N) {
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
            str1[i++] = ' ';
            elem %= (int)pow(10, j);
            str1[i] = '\0';
        }
        return str1;
    }

    /// <summary>
    /// Метод для строкового представления массива
    /// </summary>
    /// <returns></returns>
    char* Array_::toString() {
        int N = 5;
        char* str = new char[N]{0};
        int strLen = 0;
        int i = 0;
        for (curElemNum = 0; curElemNum < arrSize; curElemNum++)
        {           
            str = _strdup(addChar(str, i, strLen, N));
        }
        curElemNum = 0;
        return str;
    }

    /// <summary>
    /// Метод для добавления элемента.
    /// Реализован с помощью функции с неизвестным количеством параметров
    /// </summary>
    /// <param name="num"></param>
    /// <param name="first"></param>
    /// <param name=""></param>
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
                }
                p++;
            }
            arrSize = lastElemNum;
            point = (int*)realloc(point, sizeof(int) * arrSize);
        }
        else printf("The number of new elements cannot be negative!");
    }

    /// <summary>
    /// Метод для замены значения элелемента в позиции на данное значение
    /// </summary>
    /// <param name="position"></param>
    /// <param name="newElem"></param>
    void Array_::replaceElem(int position, int newElem) {
        if (position < arrSize && position >= 0) {
            point[position] = newElem;
        }
        else printf("Index outside the array");
    }
    
    /// <summary>
    /// Метод для удаления эелемента по номеру
    /// </summary>
    /// <param name="position"></param>
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

    /// <summary>
    /// Метод для поиска элемента по значению
    /// </summary>
    /// <param name="elem"></param>
    /// <returns></returns>
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

    /// <summary>
    /// Метод для получения эелемента по его индексу
    /// </summary>
    /// <param name="position"></param>
    /// <returns></returns>
    int Array_::getElem(int position) {
        if (position >= arrSize || position < 0)
        {
            throw out_of_range("Index out of range");
        }
        else
            return point[position];
    }

    /// <summary>
    /// Метод для получения разиера массива
    /// </summary>
    /// <returns></returns>
    int Array_::getArrSize() {
        return arrSize;
    }

    /// <summary>
    /// Метод получения номера текущего элемента
    /// </summary>
    /// <returns></returns>
    int Array_::getCurElemNum() {
        return curElemNum;
    }

    /// <summary>
    /// Метод для изменения размера массива
    /// </summary>
    /// <param name="newSize"></param>
    void Array_::changeArrSize(int newSize) {

        arrSize = newSize;
        point = (int*)realloc(point, sizeof(int) * arrSize);
    }

    /// <summary>
    /// Перегрузка индексирования
    /// </summary>
    /// <param name="index"></param>
    /// <returns></returns>
    int& Array_::operator[](const int index) {
        if (index >= 0 && index < arrSize) {
            return point[index];
        }
        else throw out_of_range("Index out of range");
    }

    /// <summary>
    /// Перегрузка бинарного оператора +
    /// </summary>
    /// <param name="ar1"></param>
    /// <param name="ar2"></param>
    /// <returns></returns>
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

    /// <summary>
    /// Перегрузка оператора прсваивания
    /// </summary>
    /// <param name="ar"></param>
    void Array_::operator=(const Array_& ar) {
        this->arrSize = ar.arrSize;
        this->curElemNum = ar.curElemNum;
        point = new int[arrSize];
        copy(ar.point, ar.point + arrSize, this->point);
    }

    /// <summary>
    /// Перегрузка декремента
    /// </summary>
    /// <returns></returns>
    Array_& Array_::operator--() {
        for (curElemNum = 0; curElemNum < arrSize; curElemNum++)
        {
            point[curElemNum]--;
        }
        return *this;
    }

    /// <summary>
    /// Перегрузка бинарного оператора -
    /// </summary>
    /// <param name="ar1"></param>
    /// <param name="elem"></param>
    /// <returns></returns>
    Array_ operator-(const Array_& ar1, int elem) {
        Array_ rez = ar1;
        int i = rez.searchElem(4);
        rez.deleteElem(i);
        return rez;
    }

    /// <summary>
    /// Перегрузка оператора вывода
    /// </summary>
    /// <param name="os"></param>
    /// <param name="ar"></param>
    /// <returns></returns>
    ostream& operator<<(ostream& os, Array_ &ar) {
        os << ar.getArrSize()<< " " << ar.getCurElemNum()<< " " << ar.toString();
        return os;
    }

    /// <summary>
    /// Перегрузка опрератора ввода с консоли
    /// </summary>
    /// <param name="is"></param>
    /// <param name="ar"></param>
    /// <returns></returns>
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

    /// <summary>
    /// Перегрузка оператора чтения из файла
    /// </summary>
    /// <param name="is"></param>
    /// <param name="ar"></param>
    /// <returns></returns>
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

    /// <summary>
    /// Метод для записи объектов в бинарный файл
    /// </summary>
    /// <param name="path"></param>
    void Array_::writeToBinFile(char* path) {
        ofstream bin_file(path);
        if (bin_file.fail()) {
            throw exception("Cannot open the file to write");
            return;
        }
        bin_file.write((char*)&(*this), sizeof(Array_));
        bin_file.close();
    }

    /// <summary>
    /// Метод ля чтения из бинарного файла
    /// </summary>
    /// <param name="path"></param>
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
