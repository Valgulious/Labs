#ifndef HASH_HASHTABLE_H
#define HASH_HASHTABLE_H
#include <iostream>

using namespace std;

struct Hash {
    unsigned short int status = 0, lesson_number;
    string FIO, name_of_lesson, class_number;
};

class HashTable {

public:
    Hash* hash_table;
    HashTable(int n = 10, float k = 0.8) {
        hash_table = new Hash[n];
    }

//    int Add(Hash){
//
//    }

    ~HashTable(){
        delete [] hash_table;
    }

private:
    int hash1 (string class_number, int lesson_number) {

    }

};


#endif //HASH_HASHTABLE_H
