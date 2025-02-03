#pragma once

#include "Deque .h"
#include <vector>
#include <limits.h>  // For INT_MIN
#include <algorithm>

using namespace DequeCircularArray;

int findMaxValueOfEquation(std::vector<std::vector<int>>& points, int k) {
    int n = points.size();
    Deque<std::pair<int, int>>* dq = createQueue<std::pair<int, int>>(n);
    

    int maxVal = INT_MIN;  // Initialize with INT_MIN for max calculation

    for (const auto& p : points) {
        int xj = p[0], yj = p[1];

        // Remove elements that are out of range |xi - xj| > k
        while (!isEmpty(dq) && xj - getFrontElement(dq).second > k) {
            deleteFront(dq);
        }

        // Calculate max value if deque is not empty
        if (!isEmpty(dq)) {
            auto firstPair = getFrontElement(dq);
            maxVal = std::max(maxVal, firstPair.first + xj + yj);

        }

        // Maintain decreasing order in deque
        while (!isEmpty(dq) && getRearElement(dq).first <= (yj - xj)) {
            deleteRear(dq);
        }

        // Insert current pair
        pushRear(dq, { yj - xj, xj });
    }

    destroyQueue(dq);
    return maxVal;
}
