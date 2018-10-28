#include <iostream>
#include "BTree.h"

int main() {
    BTree t(3);

    t.insert(1);
    t.insert(3);
    t.insert(7);
    t.insert(10);
    t.insert(11);
    t.insert(4);
    t.remove(10);
    t.traverse();

    return 0;
}