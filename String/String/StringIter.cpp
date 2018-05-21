#include "StringIter.h"

StringIter::StringIter(const String * string)
{
    str = string;
    iterList = str -> list;
}

void StringIter::first()
{
    while (iterList -> prev) {
        iterList = iterList -> prev;
    }
    index = iterList -> firstSymbol;
}

void StringIter::next()
{
    index++;
    if (index > iterList -> lastSymbol) {
        if (iterList -> next) {
            iterList = iterList -> next;
            index = iterList -> firstSymbol;
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
