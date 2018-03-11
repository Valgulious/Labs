#include "HashTable.h"
#include <cmath>

HashTable::HashTable(int n, int k) {
    hash_table = new Hash[n];
    SIZE = n;
    RATIO = k;
}

HashTable::~HashTable() {
    delete [] hash_table;
}

void HashTable::print() {
    for (int i = 0; i<SIZE; i++){
        cout << i
             << ' '
             << hash_table[i].lesson_number
             << ' '
             << hash_table[i].class_number
             << ' '
             << hash_table[i].name_of_lesson
             << ' '
             << hash_table[i].FIO
             << ' '
             << hash_table[i].hash_key
             << ' '
             << hash_table[i].status
             << endl;
    }
}

int HashTable::hash1(string class_number, string lesson_number) {
    string s = class_number + lesson_number;
    int a = ((int(s[0]) + int(s[1]))*2 + (int(s[2]) + int(s[3]))*3) * (int(s[4])*int(s[4]));
    return sqrt(a)/100 - 10;
}

int HashTable::hash2 (int i) {
    int a = i+3;
    if (a >= SIZE) return a-SIZE;
    else return a;
}

void HashTable::add(Hash h, int i){
    hash_table[i].lesson_number = h.lesson_number;
    hash_table[i].class_number = h.class_number;
    hash_table[i].hash_key = i;
    hash_table[i].FIO = h.FIO;
    hash_table[i].name_of_lesson = h.name_of_lesson;
    hash_table[i].status = 1;
    count += 1;
}

int HashTable::addRecord(Hash h) {
    int hash = hash1(h.class_number, h.lesson_number);
    // сначала надо проверить есть ли в таблице такая же запись
    if (searchRecord(h)) {
        if (hash_table[hash].status == 0) {
            add(h, hash);
        } else if (hash_table[hash].status == 1) {
            while (hash_table[hash].status == 1) {
                if (hash_table[hash].class_number == h.class_number
                        and hash_table[hash].lesson_number == h.lesson_number) return -1;
                else hash = hash2(hash);
            }
            add(h, hash);
        } else add(h, hash);
    } else return -1;
    //написать увеличение/уменьшение размера таблицы
}

bool HashTable::compare(Hash h, int i) {
    if (hash_table[i].class_number == h.class_number
        and hash_table[i].lesson_number == h.lesson_number
        and hash_table[i].FIO == h.FIO
        and hash_table[i].name_of_lesson == h.name_of_lesson) {
        return true;
    } else return false;
}

int HashTable::searchRecord(Hash h) {
    int hash = hash1(h.class_number, h.lesson_number);
    while (hash_table[hash].status == 1){
        if (compare(h, hash)) return 0;
        else hash = hash2(hash);
    }
    return 1;
}

int HashTable::deleteRecord(Hash h) {
    int hash = hash1(h.class_number, h.lesson_number);
    while (hash_table[hash].status == 1) {
        if (compare(h, hash)) {
            hash_table[hash].status = 2;
        } else hash = hash2(hash);
    }
}

