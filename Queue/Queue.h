#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#include "iostream"

using namespace std;
template <class T>
class Queue
{
public:
    Queue(int n = 10);
    ~Queue();
    int print();
    void printAll();
    int pushElement(T);
    T popElement();
    int length();

private:
    T* array = nullptr;
    int SIZE, head = 0, tail = -1;
};


#endif //QUEUE_QUEUE_H
