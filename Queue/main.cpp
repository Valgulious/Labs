#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue<int> q(5);
    Queue<int> q2;
    for (int i = 1; i <= 5; i++) q.pushElement(i);
    q.print();
    q.printAll();
    Queue<int> q1;
//    q1.print();
//    q1.printAll();
//    q1.popElement();
//    q1.popElement();
    q2.printAll();
    for (int i = 1; i <= 7; i++) q2.pushElement(i);
    q2.printAll();
    q1 = q2 = q;
    q2.printAll();
    q.printAll();
    q1.printAll();
//    q.popElement();
//    q.pushElement(9);
//    q.printAll();
//    q.print();
//    cout << "length = " << q.length() << endl;
//    for (int i = 0; i < 5; i++) q.popElement();
//    q.printAll();
//    q.print();
//    cout << "length = " << q.length() << endl;
//    q.pushElement(9);
//    q.printAll();
//    q.print();
    return 0;
}