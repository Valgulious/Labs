#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#include "iostream"

using namespace std;
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
    Queue& operator = (const Queue& q);

private:
    T* array = nullptr;
    int SIZE, head = 0, tail = -1;
};

template <class T>
Queue<T>::Queue(int n)
{
    SIZE = n;
    array = new T[n];
}

template <class T>
Queue<T>::Queue(const Queue & q)
{
    this->SIZE = q.SIZE;
    this->array = new T[SIZE];
    this->head = q.head;
    this->tail = q.tail;
    for (int i = 0; i < SIZE; i++) this->array[i] = q.array[i];
}

template <class T>
Queue<T>::~Queue()
{
    delete [] array;
}

template <class T>
int Queue<T>::print()
{
    if (length()) {
        if (tail >= head) {
            for (int i = head; i <= tail; i++) cout << array[i];
        }
        else {
            for (int i = head; i < SIZE; i++) cout << array[i];
            for (int i = 0; i <= tail; i++) cout << array[i];
        }
        cout << endl;
        return 0;
    } else return 1;
}

template <class T>
void Queue<T>::printAll()
{
    for (int i = 0; i < SIZE; i++) cout << array[i];
    cout << endl << "H = " << head << " T = " << tail << endl;
}

template <typename T>
int Queue<T>::pushElement(T element)
{
    if (length() != SIZE) {
        tail++;
        if (tail == SIZE) tail = 0;
        array[tail] = element;
        return 0;
    } else return 1;
}

template <typename T>
T Queue<T>::popElement()
{
    if (length()) {
        int i = head;
        if (tail == head) {
            tail = -1;
            head = 0;
        } else {
            head++;
            if (head == SIZE) head = 0;
        }
        return array[i];
    } else return 1; // Подумать над тем, что будет возвращать если очередь пуста
}

template <class T>
int Queue<T>::length()
{
    if (tail == -1) {
        return 0;
    } else if (tail >= head) {
        return tail - head + 1;
    } else return SIZE - head + tail + 1;
}

// Нужно константное чтение
//template <class T>
//Queue& Queue<T>::operator = (const Queue &q)
//{
//    int emptySize = tail >= head ? (SIZE - tail - 1 + head) : (head - tail - 1);
//    for (int i = 0; i < emptySize; i++) pushElement();
//}


#endif //QUEUE_QUEUE_H
