#ifndef STRING_STRING_H
#define STRING_STRING_H
#include <iostream>

using namespace std;

struct List
{
    int firstSymbol = 0, lastSymbol = -1;
    char* symbols;
    List* next, *prev;
};

class String
{
public:
    String(int size);
    String(int size, char const * symbols);
    int length();

    /** Функции
     * Длина
     * Конкотенация (+)
     * Присваивание (=)
     * Конструктор копирование
     * Печать (<<)
     * Копирование
     * Поиск
     * Удаление
     * Сравнение (==)
     */

    List* list;
private:
    List * primaryInitialization (int);
    void addNewNode();
    void writeStringInList(char const *);
    int SIZE;
};


#endif //STRING_STRING_H
