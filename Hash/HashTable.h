#ifndef HASH_HASHTABLE_H
#define HASH_HASHTABLE_H
#include <iostream>

using namespace std;

struct Hash {
    unsigned short int status = 0, lesson_number;
    string FIO, name_of_lesson, class_number;
};

class HashTable
{

public:

    HashTable(int n = 10, float k = 0.8);
    int addRecord (Hash);
    int searchRecord (Hash);
    int deleteRecord (Hash);
    void print();
    ~HashTable();

private:
    Hash* hash_table;
    int SIZE;

    int hash1 (string class_number, int lesson_number);
    int hash2 ();

};


#endif //HASH_HASHTABLE_H
