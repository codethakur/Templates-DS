
#include"queueArray.h"
#include <iostream>
#include <climits>
#include <cstring>
#include <stdexcept>

namespace DynamicQueueModule {

   /* template <typename T>
    struct Queue {
        int front, rear;
        int capacity;
        int size;
        T* array;
    };*/

    template <typename T>
    Queue<T>* createQueue(int capacity);

    template <typename T>
    int size(Queue<T>* q);

    template <typename T>
    void reSize(Queue<T>* q);

    template <typename T>
    T frontElement(Queue<T>* q);

    template <typename T>
    T rearElement(Queue<T>* q);

    template <typename T>
    T isEmpty(Queue<T>* q);

    template <typename T>
    T isFull(Queue<T>* q);

    template <typename T>
    void enQueue(Queue<T>* q, T data);

    template <typename T>
    T deQueue(Queue<T>* q);

    template <typename T>
    void destroyQueue(Queue<T>* q);

} // namespace DynamicQueueModule

