#include <iostream>
#include <cmath>
#include "HashTable.h"

using namespace std;

int main() {
    HashTable h = HashTable();
    Hash h1, h2;
    h1.FIO = "aaa";
    h1.name_of_lesson = "bbbbb";
    h1.lesson_number = "2";
    h1.class_number = "D738";
    h2.FIO = "ccc";
    h2.name_of_lesson = "bbbbb";
    h2.lesson_number = "3";
    h2.class_number = "D738";
//    h.addRecord(h1);
//    h.addRecord(h2);
//    h.addRecord(h2);
//    h.deleteRecord(h1);
//    h.print();
    string s = h1.class_number + h1.lesson_number;
    int a = (int(s[0]) + int(s[1]))*(int(s[0]) + int(s[1]));
    int b = (int(s[2]) + int(s[3]))*(int(s[2]) + int(s[3]));
    int c = (a+b)*int(s[4]);
    cout << (int)sqrt(c)/100 << ' ' << int('D');
    return 0;
}