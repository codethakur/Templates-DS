#include"stackArray.h"
#include <iostream>
#include <cstring>  // For memcpy
#include <climits>  // For INT_MIN

Stack* Stack::createStack(int capacity) {
    return new Stack(capacity);
}

int Stack::isEmpty(Stack* S) const {
    return (S->top == -1);
}

int Stack::Size(Stack* S) const {
    return (S->top + 1);
}
int Stack::isFull(Stack* S) const {
    return (S->top == capacity - 1);
}

void Stack::Push(Stack* S, int data) {
    if (isFull(S)) {
        std::cerr << "Stack Overflow\n";
    }
    else {
        S->array[++top] = data;
    }
}
void Stack::doubleStack(Stack* S) {
    capacity *= 2;
    int* newArray = new int[capacity];

    std::memcpy(newArray, S->array, (S->top + 1) * sizeof(int));

    delete[] array;
    array = newArray;
}
void Stack::PushIntoDoubleStack(Stack* S, int data) {
    if (isFull(S)) {
        doubleStack(S);
    }
    S->array[++top] = data;
}

int Stack::Pop(Stack* S) {
    if (isEmpty(S)) {
        std::cerr << "Stack is Empty\n";
        return INT_MIN;
    }
    else {
        return S->array[top--];
    }
}
int Stack::Peek(Stack* S) const {
    if (isEmpty(S)) {
        std::cerr << "Stack is Empty\n";
        return INT_MIN;
    }
    else {
        return S->array[top];
    }
}

void Stack::deleteStack(Stack* S) {
    if (S) {
        if (S->array) {
            delete[] S->array;
        }
        delete S;
    }
}
