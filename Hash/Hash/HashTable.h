#ifndef HASH_HASHTABLE_H
#define HASH_HASHTABLE_H
#include <iostream>

using namespace std;

struct Hash {
    int hash_key = -1;
    unsigned short int status = 0;
    string FIO = "----------", name_of_lesson = "--------", class_number = "----", lesson_number = "-";
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
    int SIZE, count = 0;
    float RATIO;

    int hash1 (string, string);
    int hash2 (int);
    void add(Hash, int);
    int compare(Hash, int);
    void resizeTable();
};

#endif //HASH_HASHTABLE_H