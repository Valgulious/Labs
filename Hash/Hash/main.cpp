#include <iostream>
#include <cmath>
#include "HashTable.h"

using namespace std;

int main() {
    HashTable  h(10,0.75);
    Hash h1, h2,h3,h4,h5,h6,h7,h8, h9,h10;

    h1.phone = "9084515899";
    h1.name = "Petr";

    h2.phone = "9084515896";
    h2.name = "Petr";

    h3.phone = "9084515898";
    h3.name = "Petr1";

    h4.phone = "9084515897";
    h4.name = "Petr3";

    h5.phone = "9084515890";
    h5.name = "Petr3";

    h6.phone = "9084515891";
    h6.name = "Petr3";

    h7.phone = "9084515892";
    h7.name = "Petr3";

    h8.phone = "9084515893";
    h8.name = "Petr3";

    h9.phone = "9084515894";
    h9.name = "Petr3";

    h10.phone = "9084515895";
    h10.name = "Petr3";



    h.addRecord(h2);
    h.addRecord(h3);
    h.addRecord(h4);
    h.addRecord(h1);
    h.addRecord(h5);
    h.addRecord(h6);
    h.addRecord(h7);
//    h.addRecord(h8);
//    h.addRecord(h9);
//    h.addRecord(h10);

    h.print();

    cout << h.deleteRecord(h6) << endl;
    cout << h.deleteRecord(h7) << endl;
    cout << h.deleteRecord(h5) << endl;
    cout << h.deleteRecord(h4) << endl;
    cout << h.deleteRecord(h3) << endl;

    h.print();
//    h1.FIO = "aaa";
//    h1.name_of_lesson = "bbbbb";
//    h1.lesson_number = "2";
//    h1.class_number = "D738";
//
//    h2.FIO = "aaa";
//    h2.name_of_lesson = "bbbbb";
//    h2.lesson_number = "1";
//    h2.class_number = "D738";
//
//    for (int i=1;i<10;i++) {
//        h.addRecord(h1);
//        h1.class_number[0]++;
//        h1.class_number[3]--;
//        h.addRecord(h2);
//        h2.class_number[0]++;
//        h2.class_number[3]--;
//    }
//    h.print();
//    //h.addRecord(h2);
//   // h1.FIO = "aaaa";
//    for (int i=1;i<10;i+=2) {
//        cout<<h1.class_number<<endl;
//        h.deleteRecord(h1);
//        h1.class_number[0]-=2;
//        h1.class_number[3]+=2;
//    }
////    h.deleteRecord(h2);
////    h.deleteRecord(h3);
//    h.print();
//    h1.FIO = "kkk";
//    h1.name_of_lesson = "bbbbb";
//    h1.lesson_number = "2";
//    h1.class_number = "J732";
//
//    h2.FIO = "ccc";
//    h2.name_of_lesson = "bbbbb";
//    h2.lesson_number = "1";
//    h2.class_number = "D738";
//
//    for (int i=1;i<10;i++) {
//        h.addRecord(h2);
//        h2.class_number[0]++;
//        h1.class_number[3]--;
//        h.addRecord(h1);
//        h1.class_number[0]--;
//        h1.class_number[3]++;
//    }
//    h.print();
    return 0;
}