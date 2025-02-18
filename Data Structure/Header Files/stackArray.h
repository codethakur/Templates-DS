#pragma once
#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <iostream>
#include <cstring>  // For memcpy
#include <climits>  // For INT_MIN

template<typename T>
class Stack {
private:
    T* array;  // Dynamic array to store elements
    int top;
    int capacity;

public:
    Stack(int cap) : capacity(cap), top(-1), array(new T[cap]) {}

    ~Stack() {
        delete[] array;  // Free allocated memory
    }

    void Push(T data);
    T Pop();
    T Peek() const;
    bool isEmpty() const;
    bool isFull() const;
    int Size() const;
    void doubleStack();
    void deleteStack();
};

// Implementation of template methods must be in the header file
template<typename T>
void Stack<T>::Push(T data) {
    if (isFull()) {
        doubleStack();
    }
    array[++top] = data;
}

template<typename T>
T Stack<T>::Pop() {
    if (isEmpty()) {
        std::cerr << "Stack is Empty\n";
        return T();  // Return default value of T
    }
    return array[top--];
}

template<typename T>
T Stack<T>::Peek() const {
    if (isEmpty()) {
        std::cerr << "Stack is Empty\n";
        return T();  // Return default value of T
    }
    return array[top];
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return (top == -1);
}

template<typename T>
bool Stack<T>::isFull() const {
    return (top == capacity - 1);
}

template<typename T>
int Stack<T>::Size() const {
    return (top + 1);
}

template<typename T>
void Stack<T>::doubleStack() {
    capacity *= 2;
    T* newArray = new T[capacity];

    std::memcpy(newArray, array, (top + 1) * sizeof(T));

    delete[] array;
    array = newArray;
}

template<typename T>
void Stack<T>::deleteStack() {
    delete[] array;
    array = nullptr;
    top = -1;
    capacity = 0;
}

#endif
