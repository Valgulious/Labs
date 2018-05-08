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
    String operator = (String );

    friend const bool operator == (String & string1, String & string2)
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

    friend String operator + (const String & string1, const String & string2)
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

    friend ostream& operator << (ostream& s, const String string)
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
