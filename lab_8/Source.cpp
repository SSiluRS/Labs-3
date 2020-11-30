#include "Array.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <set>
#include <algorithm>
#include <deque>
#include <chrono>
using namespace std;

void main(){
    srand(time(NULL));
    auto begin = chrono::steady_clock::now();
    set<Array_*> set_;
    for (int i = 0; i < 10000; i++)
    {
        Array_* ar = new Array_();
        for (int j = 0; j < 10; j++)
        {
            int r = rand() % 100;
            ar->addElem(1, r);
        }

        set_.insert(ar);
    }
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - begin);
    cout << "Set:\nFill = " << (double)(elapsed.count())/1000 << endl;

    begin = chrono::steady_clock::now();
    set_.find(new Array_(1, rand() % 100));
    now = std::chrono::steady_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - begin);
    cout << "Find = "<<(double)(elapsed.count()) / 1000<< "sec" << endl;

    begin = chrono::steady_clock::now();
    set_.clear();
    now = std::chrono::steady_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - begin);
    cout << "Clear = " << (double)(elapsed.count()) / 1000 << "sec" << endl;



    begin = chrono::steady_clock::now();
    deque<Array_*> deq;
    for (int i = 0; i < 10000; i++)
    {
        Array_* ar = new Array_();
        for (int j = 0; j < 10; j++)
        {
            int r = rand() % 100;
            ar->addElem(1, r);
        }

        deq.push_back(ar);
    }
    now = std::chrono::steady_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - begin);
    cout << "\nDeque:\nFill = "<< (double)(elapsed.count()) / 1000 << "sec" << endl;

    begin = chrono::steady_clock::now();
    find(deq.begin(), deq.end(), (new Array_(1, rand() % 100)));
    now = std::chrono::steady_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - begin);
    cout << "Find = " << (double)(elapsed.count()) / 1000 <<  "sec" << endl;
    
    begin = chrono::steady_clock::now();
    sort(deq.begin(), deq.end());
    now = std::chrono::steady_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - begin);
    cout << "Sort = " << (double)(elapsed.count()) / 1000 << "sec" <<endl;

    begin = chrono::steady_clock::now();
    deq.clear();
    now = std::chrono::steady_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - begin);
    cout << "Clear = " << (double)(elapsed.count()) / 1000 << "sec"<<endl;


    int wait;
    std::cin >> wait;
}