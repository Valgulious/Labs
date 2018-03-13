#include <iostream>
#include <cmath>
#include "HashTable.h"

using namespace std;

int main() {
    HashTable h;
    Hash h1, h2,h3,h4,h5,h6,h7,h8, h9,h10;
    h1.FIO = "aaa";
    h1.name_of_lesson = "bbbbb";
    h1.lesson_number = "2";
    h1.class_number = "D738";
    h2.FIO = "ccc";
    h2.name_of_lesson = "bbbbb";
    h2.lesson_number = "3";
    h2.class_number = "D745";
    h3.lesson_number = "2";
    h3.class_number = "D778";
    h4.lesson_number = "4";
    h4.class_number = "D638";
    h5.lesson_number = "3";
    h5.class_number = "D548";
    h6.lesson_number = "1";
    h6.class_number = "D702";
    h7.lesson_number = "2";
    h7.class_number = "D123";
    h8.lesson_number = "6";
    h8.class_number = "D324";
    h9.lesson_number = "6";
    h9.class_number = "D454";
    h10.lesson_number = "3";
    h10.class_number = "D745";
    h.addRecord(h1);
    h.addRecord(h2);
    h.addRecord(h3);
    h.addRecord(h4);
    h.addRecord(h5);
    h.addRecord(h6);
    h.addRecord(h7);
    h.addRecord(h8);
    h.addRecord(h9);
    h.addRecord(h10);
    //h.addRecord(h2);
    h.deleteRecord(h1);
//    h.deleteRecord(h2);
//    h.deleteRecord(h3);
    h.print();
    return 0;
}