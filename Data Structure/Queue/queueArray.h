#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#include <iostream>
#include <climits>
#include <cstring>
#include <stdexcept>

namespace DynamicQueueModule {

    template <typename T>
    struct Queue {
        int front, rear;
        int capacity;
        int size;
        T* array;
    };

    // Function to create a queue with a given capacity
    template <typename T>
    Queue<T>* createQueue(int capacity) {
        Queue<T>* q = new Queue<T>();
        if (!q) {
            std::cerr << "Memory allocation failed for queue structure.\n";
            return nullptr;
        }

        q->capacity = capacity;
        q->size = 0;
        q->front = -1;
        q->rear = -1;
        q->array = new T[q->capacity];

        if (!q->array) {
            std::cerr << "Memory allocation failed for queue array.\n";
            delete q;
            return nullptr;
        }

        return q;
    }

    // Function to get the current size of the queue
    template <typename T>
    int size(Queue<T>* q) {
        if (q == nullptr) {
            return 0; // If the queue is destroyed (null), return size as 0
        }
        return q->size;
    }

    // Function to resize the queue dynamically
    template <typename T>
    void reSize(Queue<T>* q) {
        // Double the capacity
        q->capacity *= 2;

        // Allocate a new array with the updated capacity
        T* newArray = new T[q->capacity];

        // Copy the existing elements to the new array in the correct order
        for (int i = 0; i < q->size; ++i) {
            newArray[i] = q->array[(q->front + i) % q->size];
        }

        // Reset front and rear indices
        q->front = 0;
        q->rear = q->size - 1;

        // Free the old array memory
        delete[] q->array;

        // Point the queue to the new array
        q->array = newArray;
    }

    // Function to get the front element of the queue
    template <typename T>
    T frontElement(Queue<T>* q) {
        if (isEmpty(q)) {
            throw std::runtime_error("Queue is empty.");
        }
        return q->array[q->front];
    }

    // Function to get the rear element of the queue
    template <typename T>
    T rearElement(Queue<T>* q) {
        if (isEmpty(q)) {
            throw std::runtime_error("Queue is empty.");
        }
        return q->array[q->rear];
    }

    // Function to check if the queue is empty
    template <typename T>
    T isEmpty(Queue<T>* q) {
        return (q->size == 0);
    }

    // Function to check if the queue is full
    template <typename T>
    T isFull(Queue<T>* q) {
        return (q->size == q->capacity);
    }

    // Function to add an element to the queue
    template <typename T>
    void enQueue(Queue<T>* q, T data) {
        if (isFull(q)) {
            reSize(q);
        }

        q->rear = (q->rear + 1) % q->capacity; // Circular increment
        q->array[q->rear] = data;
        if (q->front == -1) { // If the queue was empty
            q->front = q->rear;
        }
        q->size++;
    }

    // Function to remove an element from the front of the queue
    template <typename T>
    T deQueue(Queue<T>* q) {
        if (isEmpty(q)) {
            throw std::runtime_error("Queue is empty.");
        }

        T data = q->array[q->front];
        if (q->front == q->rear) { // Only one element was in the queue
            q->front = q->rear = -1;
        }
        else {
            q->front = (q->front + 1) % q->capacity;
        }
        q->size--;
        return data;
    }

    // Function to destroy the queue and free memory
    template <typename T>
    void destroyQueue(Queue<T>* q) {
        if (q) {
            delete[] q->array;
            delete q;
        }
    }
}

#endif // DYNAMIC_CIR_ARR_IMP_H
