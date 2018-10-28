#include <iostream>
#include "BTree.h"

int main() {
    BTree t(3);

    t.insert(1);
    t.insert(3);
    t.insert(7);

    return 0;
}