//
// Created by pskowronski on 20.02.2020.
//

#ifndef E1_MYHEAP_H
#define E1_MYHEAP_H
#include <string>

class MyHeap {

private:
    int *storage;
    int size, lChild, rChild, toSwap;
    std::string cr, cl, cp, heapRep;

    void printBT(std::string sp, std::string sn, int v);
    void heapify(int index);

public:
    MyHeap(int buffer);
    ~MyHeap();
    std::string toString();
    void push(int value);
    void pop(int value);
    int getIndex(int value);
    void clear();
    bool readFromFile(std::string filename);

};

#endif //E1_MYHEAP_H
