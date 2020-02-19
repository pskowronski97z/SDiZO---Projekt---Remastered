//
// Created by pskowronski on 19.02.2020.
//

#include "../headers/MyList.h"

void MyList::insertAfter(int prevValue, int element) {
    ListNode *prevNode;
    prevNode = getNodeByValue(prevValue);
    if (!size)
        createFirstNode(element);
    else if (prevNode == nullptr)
        addAtBegin(element);
    else if (prevNode == tail)
        addAtTail(element);
    else
        insertAfter(prevNode, element);
}

ListNode *MyList::getNodeByValue(int value) {
    ListNode *iterator = head;
    while (iterator != nullptr) {
        if (iterator->value == value)
            return iterator;
        iterator = iterator->next;
    }
    return iterator;
}

std::string MyList::toString() {
    std::string result = "Lista pusta";
    ListNode *iterator = head;
    if (size) {
        result = "";
        while (iterator != nullptr) {
            result.append(std::to_string(iterator->value));
            result.append(" ");
            iterator = iterator->next;
        }
        result.append("\n");
        iterator = tail;
        while (iterator != nullptr) {
            result.append(std::to_string(iterator->value));
            result.append(" ");
            iterator = iterator->prev;
        }
    }
    result.append("\n");
    return result;
}

void MyList::addAtBegin(int element) {
    ListNode *newNode;
    if (!size)
        createFirstNode(element);
    else {
        newNode = new ListNode;
        head->prev = newNode;
        newNode->prev = nullptr;
        newNode->next = head;
        newNode->value = element;
        head = newNode;
        size++;
    }
}

void MyList::createFirstNode(int element) {
    head = new ListNode;
    tail = head;
    head->prev = nullptr;
    head->next = nullptr;
    head->value = element;
    size++;
}

void MyList::addAtTail(int element) {
    ListNode *newNode;
    if (!size)
        createFirstNode(element);
    else {
        newNode = new ListNode;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = nullptr;
        newNode->value = element;
        tail = newNode;
        size++;
    }
}

bool MyList::insertAtIndex(int index, int element) {
    ListNode *iterator = head;
    if ((index < 0) || (index > size))
        return false;
    else if (!size)
        createFirstNode(element);
    else if (index == size)
        addAtTail(element);
    else if (!index)
        addAtBegin(element);
    else {
        for (int i = 1; i < index; i++)
            iterator = iterator->next;
        insertAfter(iterator, element);
    }
    return true;
}

void MyList::insertAfter(ListNode *prevNode, int element) {
    ListNode *newNode = new ListNode;
    newNode->prev = prevNode;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->next->prev = newNode;
    newNode->value = element;
    size++;
}

void MyList::deleteAtBegin() {
    ListNode *buffer;
    buffer = head;
    head = head->next;
    head->prev = nullptr;
    delete[] buffer;
    size--;
}

void MyList::deleteAtTail() {
    ListNode *buffer;
    buffer = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete[] buffer;
    size--;
}

bool MyList::deleteNode(ListNode *node) {
    if (node == nullptr)
        return false;
    else {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete[] node;
        size--;
    }
    return true;
}

bool MyList::deleteByIndex(int index) {
    ListNode *iterator = head;
    if ((!size) || (index < 0) || (index >= size))
        return false;
    else if (((index == 0) || (index == size - 1)) && (size == 1)) {
        delete[] head;
        head = nullptr;
        tail = nullptr;
        size--;
    } else if (!index)
        deleteAtBegin();
    else if (index == size - 1)
        deleteAtTail();
    else {
        for (int i = 1; i <= index; i++)
            iterator = iterator->next;
        deleteNode(iterator);
    }
    return true;
}

bool MyList::deleteByValue(int value) {
    ListNode *node = getNodeByValue(value);
    if (node == nullptr)
        return false;
    else if (node == head)
        deleteAtBegin();
    else if (node == tail)
        deleteAtTail();
    else
        deleteNode(node);
    return true;
}
