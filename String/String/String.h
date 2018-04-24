#ifndef STRING_STRING_H
#define STRING_STRING_H
#include <iostream>

using namespace std;

struct List
{
    int firstSymbol, lastSymbol;
    char* symbols;
    List* next, *prev;
};

class String
{
public:
    String(unsigned int size = 5);
    String(unsigned int size = 5, char* symbols);
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
    List * primaryInitialization (unsigned int);
    void addToEnd (unsigned int, List**);
    unsigned int SIZE;
};


#endif //STRING_STRING_H
