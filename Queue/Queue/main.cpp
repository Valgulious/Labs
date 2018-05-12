#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue<int> q(10);
    Queue<int> q1(10);
    Queue<int> q2(5);

    q.printAll();
    cout<<q.length()<<endl;

    for (int i = 1; i <= 10; i++) q.pushElement(i);
    q.print();
    cout<<q.length()<<endl;


    for (int i = 1; i <= 7; i++) q.popElement();
    q.print();
    cout<<q.length()<<endl;

    for (int i = 1; i <= 8; i++) q.pushElement(i);
    q.print();
    cout<<q.length()<<endl;

  q=q1=q2;

    q2.print();
    cout<<q2.length()<<endl;


    return 0;
}