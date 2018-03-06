#include "HashTable.h"

HashTable::HashTable(int n = 10, float k = 0.8) {
    hash_table = new Hash[n];
    SIZE = n;
}

HashTable::~HashTable() {
    delete [] hash_table;
}

void HashTable::print() {
    for (int i = 0; i<SIZE; i++){
        cout << hash_table[i].lesson_number
             << ' '
             << hash_table[i].class_number
             << ' '
             << hash_table[i].name_of_lesson
             << ' '
             << hash_table[i].FIO
             << ' '
             << hash_table[i].status
             << endl;
    }
}