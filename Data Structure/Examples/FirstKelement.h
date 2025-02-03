#pragma once
#include "queueArray.h"
#include "stackArray.h"

using namespace DynamicQueueModule;

Queue<int> modifyQueue(Queue<int>* q, int k) {
    if (isEmpty(q) || size(q) < k) {
        // Return by dereferencing the pointer to get the object
        return *q;
    }

    // Create a stack to hold k elements
    auto stack = Stack::createStack(k);

    // Push the first k elements into the stack
    for (int i = 0; i < k; i++) {
        int data = deQueue(q);  // Dequeue the element
        stack->Push(stack, data);  // Push onto the stack
    }

    // Pop elements from the stack and enqueue them back
    while (!stack->isEmpty(stack)) {
        int data = stack->Pop(stack);  // Pop from the stack
        enQueue(q, data);  // Enqueue back into the queue
    }

    // Move the remaining elements (after the first k) to the back of the queue
    int remainingSize = size(q) - k;
    for (int i = 0; i < remainingSize; i++) {
        int data = deQueue(q);  // Dequeue from the front
        enQueue(q, data);  // Enqueue at the back
    }

    // Return the modified queue
    return *q;
}
