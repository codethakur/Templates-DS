#pragma once
#include "queueArray.h"
#include "stackArray.h"

using namespace DynamicQueueModule;

int findTheWinner(int n, int k) {
    // Create a queue
    Queue<int>* q = createQueue<int>(n);

    // Enqueue all players
    for (int i = 1; i <= n; i++) {
        enQueue(q, i);
    }

    // Perform the elimination process
    while (size(q) > 1) {
        for (int i = 0; i < k - 1; i++) {
            int data = deQueue(q); // Dequeue the front
            enQueue(q, data);     // Re-enqueue it to the back
        }
        deQueue(q); // Eliminate the player at the front
    }

    // The last remaining element is the winner
    int winner = frontElement(q);
    return winner;
}
