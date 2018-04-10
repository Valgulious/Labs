#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue<int> q(5);
    for (int i = 1; i <= 5; i++) q.pushElement(i);
    q.print();
    q.printAll();
    Queue<int> q1(q);
    q1.print();
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