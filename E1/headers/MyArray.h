//
// Created by pskowronski on 18.02.2020.
//

#ifndef E1_MYARRAY_H
#define E1_MYARRAY_H

#include <string>

class MyArray {
private:
    int size;
    int *array;
public:
    MyArray();

    bool addAtIndex(int index, int element);

    void addAtTail(int element);

    bool deleteAtIndex(int index);

    std::string toString();
};

#endif //E1_MYARRAY_H
