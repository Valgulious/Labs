#include <cstring>
#include "String.h"

String::String(int size)
{
    SIZE = size;
    list = primaryInitialization(SIZE);
}

String::String(int size, char const *  symbols)
{
    SIZE = size;
    list = primaryInitialization(SIZE);
    writeStringInList(symbols);
}

List* String::primaryInitialization(int size)
{
    List *pV = new List;
    pV -> symbols = new char[size];
    pV -> next = nullptr;
    pV -> prev = nullptr;
    return pV;
}

void String::addNewNode()
{
    List *pv = list;
    while (pv -> next != nullptr)
    {
        pv = pv -> next;
    }
    pv -> next = primaryInitialization(SIZE);
    pv -> next -> symbols = new char[SIZE];
    pv -> next -> prev = pv;
}

void String::writeStringInList(char const * symbols)
{
    int i = 0, j = 0;
    //char* symbolsCut = new char[SIZE];
    List * pv = list;

    while (pv -> next) pv = pv -> next;

    while (i < strlen(symbols)) {
        j = 0;
        if ((pv -> lastSymbol + 1) == SIZE) {
            addNewNode();
            pv = pv -> next;
        }
        while ((i < strlen(symbols)) and (pv -> lastSymbol < SIZE) and (j < SIZE)) {
            pv -> lastSymbol++;
            pv -> symbols[pv -> lastSymbol] = symbols[i];
            i++; j++;
        }
    }
}