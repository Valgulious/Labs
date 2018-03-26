#include <iostream>
#include <cmath>
#include "HashTable.h"

using namespace std;

int main() {
    HashTable  h(15,0.8);
    Hash h1, h2,h3,h4,h5,h6,h7,h8, h9,h10;
    h1.FIO = "aaa";
    h1.name_of_lesson = "bbbbb";
    h1.lesson_number = "2";
    h1.class_number = "D738";

    h2.FIO = "aaa";
    h2.name_of_lesson = "bbbbb";
    h2.lesson_number = "1";
    h2.class_number = "D738";

    for (int i=1;i<10;i++) {
        h.addRecord(h1);
        h1.class_number[0]++;
        h1.class_number[3]--;
        h.addRecord(h2);
        h2.class_number[0]++;
        h2.class_number[3]--;
    }
    h.print();
    //h.addRecord(h2);
   // h1.FIO = "aaaa";
    for (int i=1;i<10;i+=2) {
        cout<<h1.class_number<<endl;
        h.deleteRecord(h1);
        h1.class_number[0]-=2;
        h1.class_number[3]+=2;
    }
//    h.deleteRecord(h2);
//    h.deleteRecord(h3);
    h.print();
    h1.FIO = "kkk";
    h1.name_of_lesson = "bbbbb";
    h1.lesson_number = "2";
    h1.class_number = "J732";

    h2.FIO = "ccc";
    h2.name_of_lesson = "bbbbb";
    h2.lesson_number = "1";
    h2.class_number = "D738";

    for (int i=1;i<10;i++) {
        h.addRecord(h2);
        h2.class_number[0]++;
        h1.class_number[3]--;
        h.addRecord(h1);
        h1.class_number[0]--;
        h1.class_number[3]++;
    }
    h.print();
    return 0;
}