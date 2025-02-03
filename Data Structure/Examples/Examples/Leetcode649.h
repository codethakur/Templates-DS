#pragma once
#include "queueArray.h"
#include <string>

using namespace DynamicQueueModule;

std::string predictPartyVictory(std::string senate) {
    int n = senate.length();

    Queue<int>* Rqueue = createQueue<int>(n);
    Queue<int>* Dqueue = createQueue<int>(n);

    for (size_t i = 0; i < n; i++) {
        (senate[i] == 'R')?
            enQueue(Rqueue, static_cast<int>(i)): // Explicit casting (optional)
                enQueue(Dqueue, static_cast<int>(i));
    }

    while (!isEmpty(Rqueue) && !isEmpty(Dqueue)) { // Both should be non-empty
        int r_index = frontElement(Rqueue);
        int d_index = frontElement(Dqueue);

        deQueue(Rqueue);
        deQueue(Dqueue);

        if (r_index < d_index) {
            enQueue(Rqueue, r_index + n);
        }
        else {
            enQueue(Dqueue, d_index + n); // Fixed to enqueue in the correct queue
        }
    }

    std::string result = (size(Rqueue) > size(Dqueue)) ? "Radiant" : "Dire";

    destroyQueue(Rqueue);
    destroyQueue(Dqueue);

    return result;
}
