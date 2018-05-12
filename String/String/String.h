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
    String(int size = 10);
    String(char const * symbols, int size = 10);
    String(const String &);
    int length();
    String& operator = (String );
    friend const bool operator == (String & string1, String & string2);
    friend String operator + (const String & string1, const String & string2);
    friend ostream& operator << (ostream& s, String string);

    /** Функции
     * Длина - done
     * Конкотенация (+) - done
     * Присваивание (=) - done
     * Конструктор копирования - done
     * Печать (<<) - done
     * Копирование
     * Поиск
     * Удаление
     * Сравнение (==) - done
     */

private:
    List* list;
    List * primaryInitialization (int);
    void addNewNode();
    void writeStringInList(char const *);
    int SIZE;
};


#endif //STRING_STRING_H
