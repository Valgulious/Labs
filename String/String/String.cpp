#include <cstring>
#include "String.h"

String::String(unsigned int size)
{
    SIZE = size;
    list = primaryInitialization(SIZE);
}

String::String(unsigned int size, char* symbols)
{
    SIZE = size;
    list = primaryInitialization(SIZE);
    for (int i = 0; i < SIZE; i++) {
        list -> symbols[i] = symbols[i];
    }
}

List* String::primaryInitialization(unsigned int size)
{
    List *pV = new List;
    pV -> symbols = new char[size];
    pV -> firstSymbol = -1;
    pV -> lastSymbol = -1;
    pV -> next = nullptr;
    pV -> prev = nullptr;
    return pV;
}

void String::addToEnd(unsigned int size, List **pBegin)
{

    List *pV = new List;
    pV -> symbols = new char[size];

    List *pv = *pBegin;
    while (pv -> next != nullptr)
    {
        pv = pv -> next;
    }
    pv -> next = pV;
    pV -> next = nullptr;
    pV -> prev = pv;
}