#include "HashTable.h"
#include <cmath>

HashTable::HashTable(int n, float k) {
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
             << hash_table[i].phone
             << ' '
             << hash_table[i].name
             << ' '
             << hash_table[i].hash_key
             << ' '
             << hash_table[i].status
             << endl;
    }
}

int HashTable::hash1(string phone) {
//    string s = class_number + lesson_number;
//    int a = (int(s[0])+int(s[1])+int(s[2])+int(s[3])+int(s[4]))%SIZE;
    int a = 0;
    for (int i = 0; i < phone.length(); i++) {
        a += int(phone[i]);
    }
    return a%SIZE;
}

int HashTable::hash2 (int i) {
    int a = (i+(SIZE-1))%SIZE;
    return a;
}

void HashTable::add(Hash h, int i){
    hash_table[i].phone = h.phone;
    hash_table[i].hash_key = i;
    hash_table[i].name = h.name;
    hash_table[i].status = 1;
    count++;
}

int HashTable::addRecord(Hash h) {
    int hash = hash1(h.phone);
    if (searchRecord(h) == -1) {
        if (hash_table[hash].status == 0) {
            add(h, hash);
        } else if (hash_table[hash].status == 1) {
            while (hash_table[hash].status == 1) {
                if (hash_table[hash].phone == h.phone) return -2;
                else hash = hash2(hash);
            }
            add(h, hash);
        } else add(h, hash);
    } else return -1;
    float b = float(count)/float(SIZE);
    if ( b > RATIO) resizeTable();
    return 0;
}

void HashTable::resizeTable() {
    Hash* new_table = new Hash[SIZE];

    for (int i = 0; i < SIZE; i++) {
        new_table[i].status = hash_table[i].status;
        new_table[i].hash_key = hash_table[i].hash_key;
        new_table[i].phone = hash_table[i].phone;
        new_table[i].name = hash_table[i].name;
        hash_table[i].status = 0;
        
    }
    delete [] hash_table;
    hash_table = new Hash[SIZE*2];
    SIZE = SIZE*2;
    count = 0;
    for (int i = 0; i < SIZE/2; i++){
        if (new_table[i].status == 1) addRecord(new_table[i]);
    }
    delete [] new_table;
}

int HashTable::compare(Hash h, int i) {
    if (hash_table[i].phone == h.phone
        and hash_table[i].name == h.name
        and hash_table[i].status == 1) {
        return true;
    } else return false;
}

int HashTable::searchRecord(Hash h) {
    int deep = 0;
    int hash = hash1(h.phone);
    while (deep <= SIZE and hash_table[hash].status != 0){
        if (compare(h, hash)) return hash;
        else hash = hash2(hash);
        deep++;
    }
    return -1;
}

int HashTable::deleteRecord(Hash h) {
    int hash = searchRecord(h);
    if (hash != -1) {
        hash_table[hash].status = 2;
        count--;

        if ((float(count)/float(SIZE)) <= 0.25) {
            Hash* new_table = new Hash[SIZE];

            for (int i = 0; i < SIZE; i++) {
                new_table[i].status = hash_table[i].status;
                new_table[i].hash_key = hash_table[i].hash_key;
                new_table[i].phone = hash_table[i].phone;
                new_table[i].name = hash_table[i].name;
                hash_table[i].status = 0;

            }
            delete [] hash_table;
            hash_table = new Hash[int(SIZE/2)];
            int size = SIZE;
            SIZE = int(SIZE/2);
            count = 0;
            for (int i = 0; i < size; i++){
                if (new_table[i].status == 1) addRecord(new_table[i]);
            }
            delete [] new_table;
        }

        return 0;
    } else return 1;
}
