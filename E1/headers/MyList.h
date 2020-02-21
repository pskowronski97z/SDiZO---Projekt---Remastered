//
// Created by pskowronski on 19.02.2020.
//

#ifndef E1_MYLIST_H
#define E1_MYLIST_H

#include <string>

struct ListNode{
    int value;
    ListNode *next;
    ListNode *prev;
};

class MyList {

private:
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    int size = 0;

    ListNode *getNodeByValue(int element);
    void createFirstNode(int element);
    void insertAfter(ListNode *prevNode, int element);
    void deleteAtBegin();
    void deleteAtTail();
    bool deleteNode(ListNode *node);

public:
    void insertAfter(int prevValue, int element);
    std::string toString();
    void addAtBegin(int element);
    void addAtTail(int element);
    bool deleteByValue(int value);
    bool deleteByIndex(int index);
    bool insertAtIndex(int index, int element);
    bool readFromFile(std::string filename);
    ~MyList();
    void clear();
};

#endif //E1_MYLIST_H
