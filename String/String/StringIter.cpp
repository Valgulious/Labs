#include "StringIter.h"

StringIter::StringIter(const String *){
    while (iterList -> prev) {
        iterList = iterList -> prev;
    }
    index = iterList -> firstSymbol;
}

int StringIter::next()
{
    index++;
    if (index > iterList -> lastSymbol) {
        if (iterList -> next) {
            iterList = iterList -> next;
            index = iterList -> firstSymbol;
        } else {
            index--;
            return -1;
        }
    }
}

void StringIter::goToIndex(int ind)
{
    iterList = str -> list;
    index = iterList -> firstSymbol;
    for (int i = 0; i < ind; i++) {
        this -> next();
    }
}

char StringIter::curentItem()
{
    return iterList -> symbols[index];
}
