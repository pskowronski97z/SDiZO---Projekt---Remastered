//
// Created by pskowronski on 06.03.2020.
//

#include "../headers/BSTTree.h"
#include <iostream>
#include <string>
#include <fstream>

bool BSTTree::readFromFile(std::string filename) {
    int size;
    int buffer;
    std::fstream fin;
    fin.open(filename);
    if (fin.fail() || fin.eof())
        return false;
    if (root != nullptr)
        clear();
    fin >> size;
    for (int i = 0; i < size; i++) {
        fin >> buffer;
        addNode(buffer);
    }
    fin.close();
    return true;
}

void BSTTree::clear() {
    if(root!= nullptr)
        recursiveClear(root);
}

bool BSTTree::addNode(int key) {
    BSTNode *currentParent = nullptr;
    BSTNode *current = root;
    BSTNode *newNode = nullptr;
    if (current == nullptr) {
        this->root = new BSTNode();
        this->root->key = key;
        return true;
    } else {
        newNode = new BSTNode();
        newNode->key = key;
        while (current != nullptr) {
            if (current->key == key) {
                delete newNode;
                return false;
            } else {
                currentParent = current;
                if (current->key > key)
                    current = current->left;
                else if (current->key < key)
                    current = current->right;
            }
        }
        newNode->parent = currentParent;
        if (currentParent->key > key)
            currentParent->left = newNode;
        else if (currentParent->key < key)
            currentParent->right = newNode;
        return true;
    }
}

bool BSTTree::deleteNode(BSTNode *node) {
    BSTNode *buffer1;
    BSTNode *buffer2;
    if ((node->left == nullptr) || (node->right == nullptr))
        buffer1 = node;
    else
        buffer1 = this->findSuccesor(node);
    if (buffer1->left != nullptr)
        buffer2 = buffer1->left;
    else
        buffer2 = buffer1->right;
    if (buffer2 != nullptr)
        buffer2->parent = buffer1->parent;
    if (buffer1->parent != nullptr) {
        if (buffer1 == buffer1->parent->left)
            buffer1->parent->left = buffer2;
        else
            buffer1->parent->right = buffer2;
    } else
        this->root = buffer2;
    if (buffer1 != node)
        node->key = buffer1->key;
    delete buffer1;
    return true;
}

bool BSTTree::findNode(int key) {
    BSTNode *node;
    node = root;
    while (node != nullptr) {
        if (node->key == key)
            return true;
        else if (node->key > key)
            node = node->left;
        else if (node->key < key)
            node = node->right;
    }
    return false;
}

BSTNode *BSTTree::findNodePtr(int key) {
    BSTNode *node;
    node = root;
    while (node != nullptr) {
        if (node->key == key)
            return node;
        else if (node->key > key)
            node = node->left;
        else if (node->key < key)
            node = node->right;
    }
    return nullptr;
}

BSTNode *BSTTree::findSuccesor(BSTNode *node) {
    BSTNode *buffer = nullptr;
    if (node == nullptr)
        return node;
    else {
        if (node->right != nullptr)
            return this->findMin(node->right);
        buffer = node->parent;
        while ((buffer != nullptr) && (node == buffer->right)) {
            node = buffer;
            buffer = buffer->parent;
        }
        return buffer;
    }
}

BSTNode *BSTTree::findMin(BSTNode *node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

void BSTTree::printBT(std::string sp, std::string sn, BSTNode *node) {
    std::string s = " ";
    if (node) {
        s = sp;
        if (sn == cr) s[s.length() - 2] = ' ';
        printBT(s + cp, cr, node->right);
        s = s.substr(0, sp.length() - 2);
        treeRep.append(s);
        treeRep.append(sn);
        treeRep.append(std::to_string(node->key));
        treeRep.append("\n");
        s = sp;
        if (sn == cl) s[s.length() - 2] = ' ';
        printBT(s + cp, cl, node->left);
    }
}

void BSTTree::dswBalancing() {
    BSTNode *node = this->root;
    int nodeCounter = 0;
    int rotateCounter = 0;
    int iterator = 0;
    while (node != nullptr) {
        if (node->left == nullptr) {
            nodeCounter++;
            node = node->right;
        } else {
            this->rotateRight(node);
            node = node->parent;
        }
    }
    rotateCounter = nodeCounter + 1 - this->logX(nodeCounter + 1);
    node = this->root;
    for (int i = 1; i <= rotateCounter; i++) {
        this->rotateLeft(node);
        node = node->parent->right;
    }
    nodeCounter = nodeCounter - rotateCounter;
    while (nodeCounter > 1) {
        nodeCounter = nodeCounter >> 1;
        node = root;
        for (int i = 1; i <= nodeCounter; i++) {
            rotateLeft(node);
            node = node->parent->right;
        }
    }
}

int BSTTree::logX(int x) {
    int y = 1;
    x = x >> 1;
    while (x > 0) {
        y = y << 1;
        x = x >> 1;
    }
    return y;
}

void BSTTree::rotateRight(BSTNode *node) {
    BSTNode *buffer;
    BSTNode *parent;
    parent = node->parent;
    buffer = node->left;
    if (buffer == nullptr)
        return;
    node->left = buffer->right;
    if (node->left != nullptr)
        node->left->parent = node;
    buffer->right = node;
    buffer->parent = parent;
    node->parent = buffer;
    if (parent == nullptr) {
        this->root = buffer;
        return;
    } else {
        if (parent->left == node)
            parent->left = buffer;
        else
            parent->right = buffer;
        return;
    }
}

void BSTTree::rotateLeft(BSTNode *node) {
    BSTNode *buffer;
    BSTNode *parent;
    parent = node->parent;
    buffer = node->right;
    if (buffer == nullptr)
        return;
    node->right = buffer->left;
    if (node->right != nullptr)
        node->right->parent = node;
    buffer->left = node;
    buffer->parent = parent;
    node->parent = buffer;
    if (parent == nullptr) {
        this->root = buffer;
        return;
    } else {
        if (parent->left == node)
            parent->left = buffer;
        else
            parent->right = buffer;
        return;
    }
}

BSTNode *BSTTree::getRoot() {
    return root;
}

BSTTree::BSTTree() {
    root = nullptr;
    cr = cl = cp = "  ";
    cr = "┌╴";
    cl = "└╴";
    cp = "| ";
    treeRep = "";
}

BSTTree::~BSTTree() {
    clear();
}

std::string BSTTree::toString() {
    std::string result = "";
    treeRep = "";
    if (root == nullptr) {
        result = "Drzewo puste";
        result.append("\n");
    } else {
        printBT("", "", root);
        result = treeRep;
    }
    return result;
}

void BSTTree::recursiveClear(BSTNode *node) {
    if (node->left != nullptr)
        recursiveClear(node->left);
    if (node->right != nullptr)
        recursiveClear(node->right);
    if (node == root) {
        delete root;
        root = nullptr;
        return;
    }
    if (node == node->parent->left) {
        node->parent->left = nullptr;
        delete node;
    } else {
        node->parent->right = nullptr;
        delete node;
    }
}
