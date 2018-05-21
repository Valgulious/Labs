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
    String string1(string);
    this->list = string1.list;

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
        for (int i = pv -> firstSymbol; i <= pv -> lastSymbol; i++) {
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

int String::findSubStr(const char *p, const char *s)
{
    for (int i = 0; s[i]; ++i) {
        for (int j = 0; ; ++j) {
            if (!p[j]) return i;
            if (s[i+j] != p[j]) break;
        }
    }
    return -1;
}

int String::find(String subStr)
{
    auto * string = new char[this->length()];
    auto * subString = new char[subStr.length()];
    int i = -1, j = 0;
    List * pv = this -> list;

    if (subStr.length() <= this -> length()) {
        while (pv) {
            if (i == -1) i = pv -> firstSymbol;
            string[j] = pv -> symbols[i];
            j++; i++;
            if (i > pv -> lastSymbol) {
                pv = pv -> next;
                i = -1;
            }
        }

        j = 0;
        i = -1;
        pv = subStr.list;
        while (pv) {
            if (i == -1) i = pv -> firstSymbol;
            subString[j] = pv -> symbols[i];
            j++; i++;
            if (i > pv -> lastSymbol) {
                pv = pv -> next;
                i = -1;
            }
        }

        return findSubStr(subString, string);
    } else {
        return -2;
    }

}

int String::deleteSubStr(String subStr)
{
    int k = find(subStr);
    List * pv = this -> list;

    if (k >= 0) {
        int j = pv -> firstSymbol;
        for (int i = 0; i <= k; i++) {
            j++;
            if (j > pv -> lastSymbol) {
                pv = pv -> next;
                j = pv -> firstSymbol;
            }
        }

        if ((pv -> lastSymbol - j + 1) == subStr.length()) {
            if (j - 1 == -1) {
                pv -> prev -> next = pv -> next;
                pv -> next -> prev = pv -> prev;
                delete pv;
                return 0;
            } else pv -> lastSymbol = j - 1;

        }
    } else return k;
}

//int String::deleteSubStr(String subStr)
//{
//    int k = find(subStr);
//    List * pv = this->list;
//    int j = pv -> firstSymbol;
//
//    while (k != -1) {
//        for (int i = 0; i < k; i++) {
//            j++;
//            if (j > pv -> lastSymbol) {
//                pv = pv -> next;
//                j = pv -> firstSymbol;
//            }
//        }
//
//        if (subStr.length() >= pv -> lastSymbol - j + 1)
//            pv->lastSymbol = j - 1;
//
//        if (pv -> lastSymbol == -1) {
//            pv -> prev -> next = pv -> next;
//            pv -> next -> prev = pv -> prev;
//        }
//
//        k = find(subStr);
//    }
//}

//int String::deleteSubStr(String subStr)
//{
//
//    int k = find(subStr);
//    size_t len;
//    List * pv = this->list;
//    int j = pv->firstSymbol;
//    while (k != -1) {
//        for (int i = 0; i < k; i++) {
//            j++;
//            if (j > pv->lastSymbol) {
//                pv = pv->next;
//                j = pv->firstSymbol;
//            }
//        }
//        len = k + strlen(subStr) - 1;
//        k = find(subStr);
//    }
//}