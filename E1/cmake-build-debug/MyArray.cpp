//
// Created by pskowronski on 18.02.2020.
//

#include "../headers/MyArray.h"
#include <fstream>

bool MyArray::addAtIndex(int index, int element) {
    int *temp = nullptr;
    int iterator = 0;
    if (!size) {
        array = new int[1];
        array[0] = element;
        size++;
        return true;
    } else if ((index < 0) || (index > size))
        return false;
    else if (index == size)
        addAtTail(element);
    else {
        size++;
        temp = new int[size];
        for (int i = 0; i < size; i++) {
            if (i != index) {
                temp[i] = array[iterator];
                iterator++;
            } else
                temp[i] = element;
        }
        delete[] array;
        array = temp;
    }
    return true;
}

void MyArray::addAtTail(int element) {
    int *temp = nullptr;
    if (!size) {
        array = new int[1];
        array[0] = element;
        size++;
    } else {
        size++;
        temp = new int[size];
        for (int i = 0; i < size - 1; i++)
            temp[i] = array[i];
        temp[size - 1] = element;
        delete[] array;
        array = temp;
    }
}

std::string MyArray::toString() {
    std::string result = "Tablica pusta";
    if (size) {
        result = "";
        for (int i = 0; i < size; i++) {
            result.append(std::to_string(array[i]));
            result.append(" ");
        }
    }
    result.append("\n");
    return result;
}

bool MyArray::deleteAtIndex(int index) {
    int *temp = nullptr;
    int iterator = 0;
    if (!size || (index > size - 1) || (index < 0))
        return false;
    else {
        size--;
        if (!size) {
            delete[] array;
            array = nullptr;
        } else {
            temp = new int[size];
            for (int i = 0; i < size + 1; i++) {
                if (i != index) {
                    temp[iterator] = array[i];
                    iterator++;
                } else
                    continue;
            }
            delete[] array;
            array = temp;
        }
        return true;
    }
}

void MyArray::clear() {
    if (!size) {
        delete[] array;
        size = 0;
    }
}

MyArray::~MyArray() {
    clear();
}

bool MyArray::readFromFile(const std::string &filename) {
    clear();
    std::fstream fin;
    fin.open(filename);
    if (fin.eof() || fin.fail())
        return false;
    else {
        fin >> size;
        array = new int[size];
        for (int i = 0; i < size; i++)
            fin >> array[i];
    }
    fin.close();
    return true;
}

bool MyArray::isInArray(int value) {
    for (int i = 0; i < size; i++)
        if (array[i] == value)
            return true;
    return false;
}
