#pragma once
#include <iostream>
#include <vector>
#include "Deque .h"
using namespace DequeCircularArray;

long long continuousSubarrays(std::vector<int>& nums)
{
    int n = nums.size();
    Deque<int>* maxDq = createQueue<int>(n);
    Deque<int>* minDq = createQueue<int>(n);
    long long count = 0;
    int left = 0; // Left boundary of the window

    for (int right = 0; right < n; right++)
    {
        // Maintain max deque (decreasing order)
        while (!isEmpty(maxDq) && nums[right] > getRearElement(maxDq)) {
            deleteRear(maxDq);
        }
        pushRear(maxDq, nums[right]);

        // Maintain min deque (increasing order)
        while (!isEmpty(minDq) && nums[right] < getRearElement(minDq)) {
            deleteRear(minDq);
        }
        pushRear(minDq, nums[right]);

        // Shrink window if condition is violated
        while (!isEmpty(maxDq) && !isEmpty(minDq) &&
            getFrontElement(maxDq) - getFrontElement(minDq) > 2)
        {
            if (getFrontElement(maxDq) == nums[left]) {
                deleteFront(maxDq);
            }

            if (getFrontElement(minDq) == nums[left]) {
                deleteFront(minDq);
            }
            left++;
        }

        count += (right - left + 1);
    }

    destroyQueue(maxDq);
    destroyQueue(minDq);

    return count;
}
