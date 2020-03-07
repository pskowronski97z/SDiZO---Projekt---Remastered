//
// Created by pskowronski on 06.03.2020.
//

#ifndef E1_BSTTREE_H
#define E1_BSTTREE_H

#include <string>

struct BSTNode {
    BSTNode *parent;
    BSTNode *left;
    BSTNode *right;
    int key;
};

class BSTTree {
private:
    BSTNode *root;
    std::string cr, cl, cp, treeRep;

    void recursiveClear(BSTNode *node);
    int logX(int x);
    void printBT(std::string sp, std::string sn, BSTNode *node);
    void rotateRight(BSTNode *node);
    void rotateLeft(BSTNode *node);
    BSTNode *findSuccesor(BSTNode *node);

public:
    bool readFromFile(std::string filename);
    void clear();
    bool addNode(int key);
    bool deleteNode(BSTNode *node);
    bool findNode(int key);
    std::string toString();
    void dswBalancing();
    BSTNode *findNodePtr(int key);
    BSTNode *findMin(BSTNode *node);
    BSTNode *getRoot();
    BSTTree();
    ~BSTTree();
};

#endif //E1_BSTTREE_H
