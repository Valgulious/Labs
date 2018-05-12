#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#include "iostream"

template <class T>
class Queue
{
public:
    Queue(int n = 10);
    Queue(const Queue&);
    ~Queue();
    int print();
    void printAll();
    int pushElement(T);
    T popElement();
    int length();
    Queue& operator = ( Queue& q);

private:
    T* array = nullptr;
    int SIZE, head = 0, tail = -1;
};

#include "QueueImp.h"
#endif //QUEUE_QUEUE_H
