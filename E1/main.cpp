#include <iostream>
#include "headers/MyArray.h"
#include "headers/MyList.h"
#include "headers/MyHeap.h"

int main() {

    MyHeap myHeap(40);
    myHeap.readFromFile("Data/heap1.txt");
    std::cout<<myHeap.toString()<<std::endl;
    myHeap.pop(11);
    std::cout<<myHeap.toString()<<std::endl;
    myHeap.pop(1);
    std::cout<<myHeap.toString()<<std::endl;
    myHeap.pop(9);
    std::cout<<myHeap.toString()<<std::endl;
    myHeap.push(11);
    std::cout<<myHeap.toString()<<std::endl;
    myHeap.push(12);
    std::cout<<myHeap.toString()<<std::endl;
    return 0;
}
