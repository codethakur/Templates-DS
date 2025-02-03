#pragma once
#include "Deque .h"
#include<vector>
using namespace DequeCircularArray;

std::vector<std::pair<std::string, int>> companies = {
	{"Amazon", 32}, {"Google", 8}, {"Microsoft", 6}, {"Salesforce", 6},
	{"Uber", 5}, {"Facebook", 5}, {"Adobe", 4}, {"Citadel", 4},
	{"ByteDance", 4}, {"Apple", 3}, {"Twilio", 3}, {"TikTok", 3},
	{"Bloomberg", 2}, {"VMware", 2}, {"Booking.com", 2}, {"DoorDash", 2},
	{"DE Shaw", 2}, {"Quora", 2}
};

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
	int n = nums.size();
	std::vector<int>result;
	Deque<int>* dq = createQueue<int>(n);
	for (int i = 0; i < n; i++) {

		if (!isEmpty(dq) && nums[getFrontElement(dq)] == i - k) {
			deleteFront(dq);
		}
		while (!isEmpty(dq) && nums[getRearElement(dq)] < nums[i]) {
			deleteRear(dq);
		}
		pushRear(dq, i);
		if (i >= k - 1) {
			result.push_back(nums[getFrontElement(dq)]);
		}
	}
	
	
	return result;
	
}

