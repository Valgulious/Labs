#ifndef STRING_STRINGITER_H
#define STRING_STRINGITER_H
#include "String.h"

class StringIter {
    const List * iterList;
    const String * str;
    int index;

public:
    StringIter(const String *);
    void first();
    void next();
    void goToIndex(int);
};


#endif //STRING_STRINGITER_H
