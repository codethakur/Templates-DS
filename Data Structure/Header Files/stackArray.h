#pragma once
#ifndef STACKARRAY_H
#define STACKARRAY_H

class Stack {
private:
    int* array;
    int top;
    int capacity;

public:
    Stack(int cap) : capacity(cap), top(-1), array(new int[cap]) {}

    static Stack* createStack(int capacity);
    int isEmpty(Stack* S) const;
    int Size(Stack* S) const;
    int isFull(Stack* S) const;
    void Push(Stack* S, int data);
    void doubleStack(Stack* S);
    void PushIntoDoubleStack(Stack* S, int data);
    int Pop(Stack* S);
    int Peek(Stack* S) const;
    void deleteStack(Stack* S);
};

#endif
