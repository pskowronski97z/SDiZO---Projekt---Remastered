#include <iostream>
#include "headers/MyArray.h"

int main() {

    MyArray arr;

    arr.addAtTail(2);
    arr.addAtTail(4);
    arr.addAtTail(6);
    arr.addAtTail(8);
    arr.addAtTail(10);

    arr.deleteAtIndex(2);
    arr.deleteAtIndex(3);
    arr.deleteAtIndex(0);
    arr.deleteAtIndex(0);
    arr.deleteAtIndex(0);
    arr.addAtIndex(0,2);
    arr.addAtIndex(1,6);
    arr.addAtIndex(2,8);
    arr.addAtIndex(1,4);
    arr.addAtIndex(0,0);
    std::cout<<arr.toString();

    return 0;
}
