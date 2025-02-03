#pragma once
#include "queueArray.h"
#include<vector>

using namespace DynamicQueueModule;

int minKBitFlips(std::vector<int>& nums, int k) {
    int result = 0;
    int n = nums.size();
    Queue<int>* q = createQueue<int>(n);

    for (int i = 0; i < n; i++) {
        // Remove outdated flips
        while (!isEmpty(q) && frontElement(q) + k <= i) {
            deQueue(q);
        }

        // Check if we need to flip
        if ((nums[i] + size(q)) % 2 == 0) {
            if (i + k > n) {
                destroyQueue(q);
                return -1;
            }
            result++;
            enQueue(q, i);
        }
    }

    destroyQueue(q);
    return result;
}