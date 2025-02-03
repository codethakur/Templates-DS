#include <iostream>
#include <vector>
#include"Deque .h"
using namespace DequeCircularArray;

int maxResult(std::vector<int>& nums, int k) {
    int n = nums.size();

    // Create deque using your custom implementation
    Deque<int>* dq = createQueue<int>(n);
    std::vector<int> maxSum(n, 0);

    maxSum[0] = nums[0];
    pushFront(dq, 0);  // Store index instead of value

    for (int i = 1; i < n; i++) {
        // Remove elements from deque that are out of window range
        while (!isEmpty(dq) && getFrontElement(dq) < i - k) {
            deleteFront(dq);
        }

        // Compute max sum at index `i`
        int frontIndex = getFrontElement(dq);
        maxSum[i] = nums[i] + maxSum[frontIndex];

        // Maintain decreasing order of maxSum[] in the deque
        while (!isEmpty(dq) && maxSum[getRearElement(dq)] <= maxSum[i]) {
            deleteRear(dq);
        }

        // Push current index into deque
        pushRear(dq, i);
    }

    int result = maxSum[n - 1];
    destroyQueue(dq); // Free memory

    return result;
}

