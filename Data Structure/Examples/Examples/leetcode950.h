#pragma once
#include "queueArray.h"
#include "stackArray.h"
#include <vector>
#include <algorithm>

using namespace DynamicQueueModule;

std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
    int totalCard = deck.size();
    Queue<int>* q = createQueue<int>(totalCard);

    // Fill the queue with indexes 0 to totalCard-1
    for (int i = 0; i < totalCard; i++) {
        enQueue(q, i);
    }

    // Sort the deck in ascending order
    std::sort(deck.begin(), deck.end());

    // Prepare the result vector
    std::vector<int> result(totalCard);

    for (int i = 0; i < totalCard; i++) {
        // Reveal card: Place the current smallest card at the revealed index
        int index = deQueue(q);
        result[index] = deck[i];

        // Move the next card to the bottom of the queue if any remain
        if (!isEmpty(q)) {
            enQueue(q, deQueue(q));
        }
    }

    // Clean up the queue
    destroyQueue(q);
    return result;
}
