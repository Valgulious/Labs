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

int String::find(String subStr)
{

    if (subStr.length() <= this -> length()) {
        StringIter iterStr(this);
        StringIter iterSubStr(&subStr);
        for (int i = 0; i < this -> length(); i++) {
            for (int j = 0; ; j++) {
                if (iterSubStr.getIndex() == -1) return i;
                if (iterStr.currentItem() == iterSubStr.currentItem()) {
                    iterStr.next();
                    iterSubStr.next();
                } else {
                    iterSubStr.first();
                    iterStr.next();
                    break;
                }
            }
        }
        return -1;
    } else return -2;

}

String String::subStr(int first, int last)
{
    String subString("",this -> SIZE);
    if ((last - first + 1) <= this -> length()) {
        if ((first <= this -> length() - 1) or (last <= this -> length() - 1)) {
            StringIter stringIter(this);

            stringIter.goToIndex(first);
            for (int i = 0; i < last - first +1; i++) {
                auto * c = new char[1];
                c[0] = stringIter.currentItem();
                subString.writeStringInList(c);
                stringIter.next();
                delete [] c;
            }
            return subString;
        } else return subString;
    } else return subString;
}

int String::deleteSubStr(int first, int last)
{
    if ((last - first + 1) <= this -> length()) {
        if (last <= this -> length()) {
            String string1(this -> subStr(0, first - 1));
            String string2(this -> subStr(last + 1, this -> length() - 1));
            String string3(string1 + string2);

            this -> list = string3.list;
            return 0;
        } else return -1;
    } else return -2;
}

int String::replace(String subString1, String subString2)
{
    if (this -> find(subString1) >= 0) {
        String thisAfterReplace("", this -> SIZE);
        while (this -> find(subString1) >= 0) {
            StringIter stringIter(this);

            stringIter.goToIndex(this -> find(subString1));
            String string1(this -> subStr(0, this -> find(subString1) - 1));

            thisAfterReplace = thisAfterReplace + string1 + subString2;
            this -> deleteSubStr(0, this -> find(subString1) + subString1.length() - 1);
//            String string2(this -> subStr(this -> find(subString1) + subString1.length(),
//                                          this -> length() - 1));

        }
        thisAfterReplace = thisAfterReplace + this -> subStr(0, this -> length() - 1);
        this -> list = thisAfterReplace.list;
    } else return this -> find(subString1);

}