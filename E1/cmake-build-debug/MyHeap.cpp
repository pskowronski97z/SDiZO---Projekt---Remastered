//
// Created by pskowronski on 20.02.2020.
//

#include <fstream>
#include "../headers/MyHeap.h"

MyHeap::MyHeap(int buffer) {
    storage = new int[buffer];
    size = 0;
    lChild = 0;
    rChild = 0;
    cr = cl = cp = "  ";
    cr = "┌╴";
    cl = "└╴";
    cp = "| ";
    heapRep = "";
}

void MyHeap::push(int value) {
    int index = size;
    int parent = (index - 1) / 2;
    size++;
    while ((index > 0) && (storage[parent] < value)) {
        storage[index] = storage[parent];
        index = parent;
        parent = (index - 1) / 2;
    }
    storage[index] = value;
}

std::string MyHeap::toString() {
    std::string result = "";
    heapRep = "";
    if (!size) {
        result = "Kopiec pusty";
        result.append("\n");
    } else {
        printBT("", "", 0);
        result = heapRep;
    }
    return result;
}

void MyHeap::printBT(std::string sp, std::string sn, int v) {
    std::string s;
    if (v < size) {
        s = sp;
        if (sn == cr) s[s.length() - 2] = ' ';
        printBT(s + cp, cr, 2 * v + 2);
        s = s.substr(0, sp.length() - 2);
        heapRep.append(s);
        heapRep.append(sn);
        heapRep.append(std::to_string(storage[v]));
        heapRep.append("\n");
        s = sp;
        if (sn == cl) s[s.length() - 2] = ' ';
        printBT(s + cp, cl, 2 * v + 1);
    }
}

int MyHeap::getIndex(int value) {
    for (int i = 0; i < size; i++)
        if (storage[i] == value)
            return i;
    return -1;
}

void MyHeap::pop(int value) {
    int index = getIndex(value);
    int parent;
    if (index != -1) {
        parent = (index - 1) / 2;
        while ((index > 0) && (storage[parent] < storage[size - 1])) {
            storage[index] = storage[parent];
            index = parent;
            parent = (index - 1) / 2;
        }
        storage[index] = storage[size - 1];
        size--;
        heapify(index);
    }
}

void MyHeap::heapify(int index) {
    lChild = 2 * index + 1;
    rChild = 2 * index + 2;
    if ((lChild < size) && (storage[lChild] > storage[index]))
        toSwap = lChild;
    else
        toSwap = index;
    if ((rChild < size) && (storage[rChild] > storage[toSwap]))
        toSwap = rChild;
    if (toSwap != index) {
        std::swap(storage[index], storage[toSwap]);
        heapify(toSwap);
    }
}

void MyHeap::clear() {
    if (size) {
        delete[] storage;
        size = 0;
    }
}

MyHeap::~MyHeap() {
    clear();
}

bool MyHeap::readFromFile(std::string filename) {
    clear();
    std::fstream fin;
    fin.open(filename);
    int temp;
    int buffer;
    if (fin.eof() || fin.fail())
        return false;
    else {
        fin >> buffer;
        for (int i = 0; i < buffer; i++) {
            fin >> temp;
            push(temp);
        }
    }
    fin.close();
    return true;
}
