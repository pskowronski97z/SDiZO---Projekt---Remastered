//
// Created by pskowronski on 18.02.2020.
//

#ifndef E1_MYARRAY_H
#define E1_MYARRAY_H

#include <string>

class MyArray {
private:
    int size=0;
    int *array=nullptr;

public:
    std::string toString();
    bool addAtIndex(int index, int element);
    void addAtTail(int element);
    bool deleteAtIndex(int index);
    bool readFromFile(const std::string& filename);
    void clear();
    bool isInArray(int value);
    ~MyArray();
};

#endif //E1_MYARRAY_H
