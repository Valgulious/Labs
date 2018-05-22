#ifndef STRING_STRING_H
#define STRING_STRING_H
#include <iostream>
//#include "StringIter.h"

using namespace std;

struct List
{
    int firstSymbol = 0, lastSymbol = -1;
    char * symbols;
    List * next, * prev;
};

class String
{
public:
    String(int size = 10);
    String(char const * symbols, int size = 10);
    String(const String &);
    int length();
    int find(String *);
    int deleteSubStr(String *);
    String& operator = (String );
    friend const bool operator == (String & string1, String & string2);
    friend String operator + (const String & string1, const String & string2);
    friend ostream& operator << (ostream& s, String string);

    friend class StringIter;

    /** Функции
     * Длина - done
     * Конкотенация (+) - done
     * Присваивание (=) - done
     * Конструктор копирования - done
     * Печать (<<) - done
     * Копирование(subStr)
     * Поиск - done
     * Удаление
     * Сравнение (==) - done
     */

private:
    List* list;
    List * primaryInitialization (int);
    void addNewNode();
    void writeStringInList(char const *);
    int SIZE;
    int findSubStr(const char *, const char *);
};

class StringIter {
    const List * iterList;
    const String * str;
    int index;

public:
    StringIter(const String * string)
    {
        str = string;
        iterList = str -> list;
        index = iterList -> firstSymbol;
    }
    void first()
    {
        while (iterList -> prev) {
            iterList = iterList -> prev;
        }
        index = iterList -> firstSymbol;
    }
    void next()
    {
        index++;
        if (index > iterList -> lastSymbol) {
            if (iterList -> next) {
                iterList = iterList -> next;
                index = iterList -> firstSymbol;
            } else {
                index = -1;
            }
        }}
    void goToIndex(int ind)
    {
        iterList = str -> list;
        index = iterList -> firstSymbol;
        for (int i = 0; i < ind; i++) {
            this -> next();
        }}
    char curentItem()
    {
        return iterList -> symbols[index];
    }

    int getIndex()
    {
        return index;
    }
};


#endif //STRING_STRING_H
