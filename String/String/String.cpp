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
    auto *pV = new List;
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

String& String::operator = (String string)
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

const bool operator == (String & string1, String & string2)
{
    if (string1.length() != string2.length()) {
        return false;
    } else {
        List * pv1 = string1.list;
        List * pv2 = string2.list;
        int i = 0, j = 0;

        while (pv1) {
            while ((i < string1.SIZE) and (j < string2.SIZE)) {
                if (pv1 -> symbols[i] != pv2 -> symbols[j]) return false;
                i++; j++;
            }
            if (i == string1.SIZE) {
                pv1 = pv1 -> next;
                i = 0;
            }
            if (j == string2.SIZE) {
                pv2 = pv2 -> next;
                j = 0;
            }
        }
    }
    return true;
}

String operator + (const String & string1, const String & string2)
{
    List * pv = string1.list;

    String string0(string1.SIZE);

    while (pv) {
        string0.writeStringInList(pv->symbols);
        pv = pv -> next;
    }

    pv = string2.list;
    while (pv) {
        string0.writeStringInList(pv->symbols);
        pv = pv -> next;
    }

    return string0;
}

ostream& operator << (ostream& s, String string)
{
    List * pv = string.list;

    while (pv) {
        for (int i = pv ->firstSymbol; i <= pv -> lastSymbol; i++) {
            s << pv -> symbols[i];
        }
        pv = pv -> next;
    }
    return s;
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