#include <iostream>
//#include "BTree.h"

struct BTreeNode {
    int *keys;
    int t;
    BTreeNode **children;
    int n;
    bool leaf;
    BTreeNode(int _t, bool _leaf) {
        this->t = t;
        this->leaf = leaf;
    }
};

struct BTree {
    BTreeNode *root;
    int degree;
    BTree(int _degree) {
        this->degree = _degree;
    }
};

void traverse();
BTreeNode *search(int _key);
int findKey(int _key);
void insertNonFull(int _key);
void splitChild(int idx, BTreeNode *child);
void remove(int _key);
void removeFromLeaf(int _idx);
void removeFomNoLeaf(int _idx);
int getPred(int _idx);
int getSucc(int _idx);
void fill(int _idx);
void borrowFromPrev(int _idx);
void borrowFromNext(int _idx);
void merge(int _idx);

void insert(int _key);

int main() {

    return 0;
}