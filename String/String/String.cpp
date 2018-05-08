#include <cstring>
#include "String.h"

String::String(int size)
{
    SIZE = size;
    list = primaryInitialization(SIZE);
}

String::String( char const *  symbols, int size)
{
    SIZE = size;
    list = primaryInitialization(SIZE);
    writeStringInList(symbols);
}

String::String(const String & string)
{
    this -> SIZE = string.SIZE;
    this -> list = primaryInitialization(this -> SIZE);

    List * pv = string.list;

    while (pv) {
        this->writeStringInList(pv -> symbols);
        pv = pv -> next;
    }

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
        if ((pv -> lastSymbol + 1) >= SIZE) {
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

String String::operator = (String string)
{
    List * pv = this->list;

    while (pv) {
        pv -> firstSymbol = 0;
        pv -> lastSymbol = -1;
        pv = pv -> next;
    }

    pv = string.list;

    while (pv) {
        this->writeStringInList(pv->symbols);
        pv = pv -> next;
    }

    return *this;
}

int String::length()
{
    List * pv = this -> list;
    int lengthOfString = 0;

    while (pv) {
        lengthOfString = lengthOfString + pv -> lastSymbol - pv -> firstSymbol + 1;
        pv = pv -> next;
    }
    return lengthOfString;
}