#pragma once
#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <stdexcept>

namespace DequeCircularArray {

    template <typename T>
    struct Deque {
        int front, rear, size, capacity;
        T* array;
    };

    // Create a new deque
    template <typename T>
    Deque<T>* createQueue(int capacity) {
        Deque<T>* q = new Deque<T>();
        if (!q) {
            throw std::runtime_error("Memory allocation failed for queue structure.");
        }
        q->capacity = capacity;
        q->size = 0;
        q->front = -1;
        q->rear = -1;
        q->array = new T[capacity];
        if (!q->array) {
            delete q;
            throw std::runtime_error("Memory allocation failed for queue array.");
        }
        return q;
    }

    // Check if the deque is empty
    template <typename T>
    bool isEmpty(Deque<T>* q) {
        return q->size == 0;
    }

    // Check if the deque is full
    template <typename T>
    bool isFull(Deque<T>* q) {
        return q->size == q->capacity;
    }

    // Add element at the front
    template <typename T>
    void pushFront(Deque<T>* q, const T& data) {
        if (isFull(q)) {
            throw std::runtime_error("Deque is full.");
        }
        if (q->front == -1) { // First element
            q->front = q->rear = 0;
        }
        else {
            q->front = (q->front - 1 + q->capacity) % q->capacity;
        }
        q->array[q->front] = data;
        q->size++;
    }

    // Add element at the rear
    template <typename T>
    void pushRear(Deque<T>* q, const T& data) {
        if (isFull(q)) {
            throw std::runtime_error("Deque is full.");
        }
        if (q->rear == -1) { // First element
            q->front = q->rear = 0;
        }
        else {
            q->rear = (q->rear + 1) % q->capacity;
        }
        q->array[q->rear] = data;
        q->size++;
    }

    // Get the front element
    template <typename T>
    T getFrontElement(Deque<T>* q) {
        if (isEmpty(q)) {
            throw std::runtime_error("Deque is empty.");
        }
        return q->array[q->front];
    }

    // Get the rear element
    template <typename T>
    T getRearElement(Deque<T>* q) {
        if (isEmpty(q)) {
            throw std::runtime_error("Deque is empty.");
        }
        return q->array[q->rear];
    }

    // Remove the front element
    template <typename T>
    T deleteFront(Deque<T>* q) {
        if (isEmpty(q)) {
            throw std::runtime_error("Deque is empty.");
        }
        T data = q->array[q->front];
        q->front = (q->front + 1) % q->capacity;
        q->size--;
        return data;
    }

    // Remove the rear element
    template <typename T>
    T deleteRear(Deque<T>* q) {
        if (isEmpty(q)) {
            throw std::runtime_error("Deque is empty.");
        }
        T data = q->array[q->rear];
        q->rear = (q->rear - 1 + q->capacity) % q->capacity;
        q->size--;
        return data;
    }

    // Get the size of the deque
    template <typename T>
    int Size(Deque<T>* q) {
        return q ? q->size : 0;
    }

    // Destroy the deque
    template <typename T>
    void destroyQueue(Deque<T>* q) {
        if (q) {
            delete[] q->array;
            delete q;
        }
    }
}

#endif // DEQUE_H
