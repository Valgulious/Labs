#ifndef STRING_STRING_H
#define STRING_STRING_H
#include <iostream>

using namespace std;

class String
{
public:
    struct List
    {
        int firstSymbol, lastSymbol;
        char* symbols[5];
        List* next, pref;
    };
    String();
    String(char*);

};


#endif //STRING_STRING_H
