#include <iostream>

int const DEGREE = 2;
int const STEP = 4;

using namespace std;

struct BTreeNode {
    int *keys;
    BTreeNode **children;
    int n;
    bool leaf;
    BTreeNode(int _degree, bool _leaf) {
        this->leaf = _leaf;

        this->keys = new int[(2*DEGREE)-1];
        this->children = new BTreeNode *[2*DEGREE];

        n = 0;
    }
};

struct BTree {
    BTreeNode *root;
    BTree() {
        root = nullptr;
    }
};

int printBTreeNode(BTreeNode *_BTreeNode);
int search(BTreeNode *_BTreeNode, int _key);
int findKey(BTreeNode *_BTreeNode, int _key);
void insertNonFull(BTreeNode *_BTreeNode, int _key);
void splitChild(BTreeNode *_BTreeNode, int idx, BTreeNode *child);
int remove(BTreeNode *_BTreeNode, int _key);
int removeFromLeaf(BTreeNode *_BTreeNode, int _idx);
int removeFromNoLeaf(BTreeNode *_BTreeNode, int _idx);
int getPred(BTreeNode *_BTreeNode, int _idx);
int getSucc(BTreeNode *_BTreeNode, int _idx);
void fill(BTreeNode *_BTreeNode, int _idx);
void borrowFromPrev(BTreeNode *_BTreeNode, int _idx);
void borrowFromNext(BTreeNode *_BTreeNode, int _idx);
void merge(BTreeNode *_BTreeNode, int _idx);

void printBTree(BTree *_BTree);
int search(BTree *_BTree, int _key);
void insert(BTree *_BTree, int _key);
int remove(BTree *_BTree, int _key);

int main() {

    BTree t;

    for (int i = 0; i < 10; i++) {
        insert(&t, i);
//        printBTree(&t);
//        cout << endl;
    }
    printBTree(&t);
    cout << remove(&t,6) << endl;
    cout << endl;
    printBTree(&t);
    cout << search(&t, 3) << endl;
}

int findKey(BTreeNode *_BTreeNode, int _key)
{
    int idx = 0;
    while (idx < _BTreeNode->n && _BTreeNode->keys[idx] < _key)
        idx++;
    return idx;
}

int remove(BTreeNode *_BTreeNode, int _key)
{
    int idx = findKey(_BTreeNode, _key);

    if (idx < _BTreeNode->n && _BTreeNode->keys[idx] == _key) {
        if (_BTreeNode->leaf)
            return removeFromLeaf(_BTreeNode, idx);
        else
            return removeFromNoLeaf(_BTreeNode, idx);
    }
    else {
        if (_BTreeNode->leaf) {
            cout << "The key " << _key << " is does not exist in the tree\n";
            return 1;
        }

        bool flag = (idx==_BTreeNode->n);

        if (_BTreeNode->children[idx]->n < DEGREE)
            fill(_BTreeNode, idx);

        if (flag && idx > _BTreeNode->n)
            return remove(_BTreeNode->children[idx-1], _key);
        else
            return remove(_BTreeNode->children[idx], _key);
    }
}

int removeFromLeaf(BTreeNode *_BTreeNode, int _idx)
{
    for (int i=_idx+1; i < _BTreeNode->n; ++i)
        _BTreeNode->keys[i-1] = _BTreeNode->keys[i];
    _BTreeNode->n--;
    return 0;
}

int removeFromNoLeaf(BTreeNode *_BTreeNode, int _idx)
{
    int k = _BTreeNode->keys[_idx];

    if (_BTreeNode->children[_idx]->n >= DEGREE) {
        int pred = getPred(_BTreeNode, _idx);
        _BTreeNode->keys[_idx] = pred;
        return remove(_BTreeNode->children[_idx], pred);
    }

    else if  (_BTreeNode->children[_idx+1]->n >= DEGREE) {
        int succ = getSucc(_BTreeNode, _idx);
        _BTreeNode->keys[_idx] = succ;
        return remove(_BTreeNode->children[_idx-1], succ);
    }
    else {
        merge(_BTreeNode, _idx);
        return remove(_BTreeNode->children[_idx], k);
    }
}

int getPred(BTreeNode *_BTreeNode, int _idx)
{
    BTreeNode *cur = _BTreeNode->children[_idx];
    while (!cur->leaf)
        cur = cur->children[cur->n];

    return cur->keys[cur->n-1];
}

int getSucc(BTreeNode *_BTreeNode, int _idx)
{
    BTreeNode *cur = _BTreeNode->children[_idx+1];
    while (!cur->leaf)
        cur = cur->children[0];

    return cur->keys[0];
}

void fill(BTreeNode *_BTreeNode, int _idx)
{
    if (_idx!=0 && _BTreeNode->children[_idx-1]->n >= DEGREE)
        borrowFromPrev(_BTreeNode, _idx);

    else if (_idx!=_BTreeNode->n && _BTreeNode->children[_idx+1]->n >= DEGREE)
        borrowFromNext(_BTreeNode, _idx);

    else {
        if (_idx != _BTreeNode->n)
            merge(_BTreeNode, _idx);
        else
            merge(_BTreeNode, _idx-1);
    }
}

void borrowFromPrev(BTreeNode *_BTreeNode, int _idx)
{
    BTreeNode *child = _BTreeNode->children[_idx];
    BTreeNode *sibling = _BTreeNode->children[_idx-1];

    for (int i = child->n-1; i >= 0; --i)
        child->keys[i+1] = child->keys[i];

    if (!child->leaf) {
        for(int i = child->n; i >= 0; --i)
            child->children[i+1] = child->children[i];
    };

    child->keys[0] = _BTreeNode->keys[_idx-1];

    if(!child->leaf)
        child->children[0] = sibling->children[sibling->n];

    _BTreeNode->keys[_idx-1] = sibling->keys[sibling->n-1];

    child->n += 1;
    sibling->n -= 1;
}

void borrowFromNext(BTreeNode *_BTreeNode, int _idx)
{
    BTreeNode *child = _BTreeNode->children[_idx];
    BTreeNode *sibling = _BTreeNode->children[_idx+1];

    child->keys[(child->n)] = _BTreeNode->keys[_idx];

    if (!(child->leaf))
        child->children[(child->n)+1] = sibling->children[0];

    _BTreeNode->keys[_idx] = sibling->keys[0];

    for (int i = 1; i < sibling->n; ++i)
        sibling->keys[i-1] = sibling->keys[i];

    if (!sibling->leaf) {
        for(int i = 1; i <= sibling->n; ++i)
            sibling->children[i-1] = sibling->children[i];
    }

    child->n += 1;
    sibling->n -= 1;
}

void merge(BTreeNode *_BTreeNode, int _idx)
{
    BTreeNode *child = _BTreeNode->children[_idx];
    BTreeNode *sibling = _BTreeNode->children[_idx+1];

    child->keys[DEGREE-1] = _BTreeNode->keys[_idx];

    for (int i = 0; i < sibling->n; ++i)
        child->keys[i+DEGREE] = sibling->keys[i];

    if (!child->leaf) {
        for(int i = 0; i <= sibling->n; ++i)
            child->children[i+DEGREE] = sibling->children[i];
    }

    for (int i = _idx+1; i < _BTreeNode->n; ++i)
        _BTreeNode->keys[i-1] = _BTreeNode->keys[i];

    for (int i = _idx+2; i <= _BTreeNode->n; ++i)
        _BTreeNode->children[i-1] = _BTreeNode->children[i];

    child->n += sibling->n+1;
    _BTreeNode->n--;

    delete(sibling);
}

void insertNonFull(BTreeNode *_BTreeNode, int _key)
{
    int i = _BTreeNode->n-1;

    if (_BTreeNode->leaf) {
        while (i >= 0 && _BTreeNode->keys[i] > _key) {
            _BTreeNode->keys[i+1] = _BTreeNode->keys[i];
            i--;
        }

        _BTreeNode->keys[i+1] = _key;
        _BTreeNode->n = _BTreeNode->n+1;
    }
    else {
        while (i >= 0 && _BTreeNode->keys[i] > _key)
            i--;

        if (_BTreeNode->children[i+1]->n == 2*DEGREE-1) {
            splitChild(_BTreeNode, i+1, _BTreeNode->children[i+1]);

            if (_BTreeNode->keys[i+1] < _key)
                i++;
        }
        insertNonFull(_BTreeNode->children[i+1], _key);
    }
}

void splitChild(BTreeNode *_BTreeNode, int idx, BTreeNode *child)
{
    auto *z = new BTreeNode(DEGREE, child->leaf);
    z->n = DEGREE - 1;

    for (int j = 0; j < DEGREE-1; j++)
        z->keys[j] = child->keys[j+DEGREE];

    if (!child->leaf) {
        for (int j = 0; j < DEGREE; j++)
            z->children[j] = child->children[j+DEGREE];
    }

    child->n = DEGREE - 1;

    for (int j = _BTreeNode->n; j >= idx+1; j--)
        _BTreeNode->children[j+1] = _BTreeNode->children[j];

    _BTreeNode->children[idx+1] = z;

    for (int j = _BTreeNode->n-1; j >= idx; j--)
        _BTreeNode->keys[j+1] = _BTreeNode->keys[j];

    _BTreeNode->keys[idx] = child->keys[DEGREE-1];

    _BTreeNode->n = _BTreeNode->n + 1;
}

int search(BTreeNode *_BTreeNode, int _key)
{
    int i = 0;
    while (i < _BTreeNode->n && _key > _BTreeNode->keys[i])
        i++;

    if (_BTreeNode->keys[i] == _key)
        return 1;

    if (_BTreeNode->leaf)
        return 0;

    return search(_BTreeNode->children[i], _key);
}

void insert(BTree *_BTree, int _key)
{
    if (_BTree->root == nullptr) {
        _BTree->root = new BTreeNode(DEGREE, true);
        _BTree->root->keys[0] = _key;
        _BTree->root->n = 1;
    }
    else {
        if (_BTree->root->n == 2*DEGREE-1) {
            auto *s = new BTreeNode(DEGREE, false);

            s->children[0] = _BTree->root;

            splitChild(s, 0, _BTree->root);

            int i = 0;
            if (s->keys[0] < _key)
                i++;
            insertNonFull(s->children[i], _key);

            _BTree->root = s;
        }
        else
            insertNonFull(_BTree->root, _key);
    }
}

int remove(BTree *_BTree, int _key)
{
    if (!_BTree->root) {
        cout << "The tree is empty\n";
        return 2;
    }

    remove(_BTree->root, _key);

    if (_BTree->root->n == 0) {
        BTreeNode *tmp = _BTree->root;
        if (_BTree->root->leaf)
            _BTree->root = nullptr;
        else
            _BTree->root = _BTree->root->children[0];

        delete tmp;
    }
}

int search(BTree *_BTree, int _key)
{
    return (_BTree->root == nullptr)? 0 : search(_BTree->root, _key);
}

void printBTree(BTree *_BTree)
{
    if (_BTree->root != nullptr) printBTreeNode(_BTree->root);
}

int printBTreeNode(BTreeNode *_BTreeNode)
{
    int h = 0;
    int i;
    for (i = 0; i < _BTreeNode->n; i++) {
        if (!_BTreeNode->leaf)
            h = printBTreeNode(_BTreeNode->children[i]);
        for (int j = 0; j < h; j++) cout << " ";
        cout << " " << _BTreeNode->keys[i] << endl;
    }

    if (!_BTreeNode->leaf) {
        printBTreeNode(_BTreeNode->children[i]);
        cout << endl;
    }
    return h+STEP;
}

