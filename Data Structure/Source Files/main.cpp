#include<iostream>
#include "Deque .h"
#include"Leetcode239.h"

int main() {
    using namespace DequeCircularArray;
    auto deque = createQueue<int>(5);
    std::vector<int>nums = { 1,3,-1,-3,5,3,6,7 };
    int k = 3;
    auto maxWindow = maxSlidingWindow(nums, k);
    std::cout<< "max sliding window: ";
    for (const auto num : maxWindow)
        std::cout << num << " ";

    std::cout << "\nEssential coding questions asked by top tech companies:\n";
    for (const auto& company : companies) {
        std::cout << company.first << " -> " << company.second << std::endl;
    }
    #if 0
    //------------------------------------
    std::vector<std::vector<int>> points = { {1, 3}, {2, 0}, {5, 10}, {6, -10} };  

    int k = 1;
    int result = findMaxValueOfEquation(points, k);

    std::cout << "The maximum value of the equation: " << result << std::endl; 
    

    std::vector<int> nums = {5,4,2,4};


    auto total  = continuousSubarrays(nums);
    std::cout << "total number of continuous subarrays: " << total << std::endl;//Output: 8
        
        
 
    std::vector<int> nums = { 1, -1, -2, 4, -7, 3 };
    int k = 2;

    int score = maxResult(nums, k);
    std::cout << "Maximum Score: " << score << std::endl; // Output: 7



    
    //-------------------------------------
    pushRear(deque, 10);
    pushRear(deque, 20);
    pushFront(deque, 5);
    pushFront(deque, 100);
    pushRear(deque,500);

    std::cout << "Front: " << getFrontElement(deque) << "\n"; 
    std::cout << "Rear: " << getRearElement(deque) << "\n"; 

    int frontData = deleteFront(deque);
    int RearData = deleteRear(deque);

    std::cout << "Front: " << getFrontElement(deque) << "\n";
    std::cout << "Rear: " << getRearElement(deque) << "\n";


    deleteFront(deque);
    std::cout << "After deleteFront, Front: " << getFrontElement(deque) << "\n"; 

    destroyQueue(deque);
    
    using namespace DequeCircularArray;
    auto deque = createQueue<int>(5);

    pushRear(deque, 10);
    pushRear(deque, 20);
    pushFront(deque, 5);

    std::cout << "Front: " << getFrontElement(deque) << "\n"; // Output: 5
    std::cout << "Rear: " << getRearElement(deque) << "\n";   // Output: 20

    deleteFront(deque);
    std::cout << "After deleteFront, Front: " << getFrontElement(deque) << "\n"; // Output: 10

    destroyQueue(deque);

    using namespace DynamicQueueModule;

    // Create a stack and queue
    Stack* myStack = Stack::createStack(10);
    Queue<int>* q = createQueue<int>(5);
    std::string senate = { "RDD " };
    auto victory = predictPartyVictory(senate);
    std::cout << "victory: " << victory << std::endl;


    std::vector<int> nums = { 0,0,0,1,0,1,1,0 };

    int k = 3;
    auto totalFlip = minKBitFlips(nums, k);
    std::cout << "Total Flip: " << totalFlip << std::endl;


    int n = 0;
    std::cout << "Enter the size of the deck: ";
    std::cin >> n;
    //-------------------------------------------------
    std::vector<int> deck(n); // Reserve space for exactly `n` elements
    std::cout << "Enter the numbers:" << std::endl;

    for (int i = 0; i < n; i++) {
        std::cin >> deck[i]; // Use array-style indexing to fill the vector
    }

    // Call the function to get the result
    auto result = deckRevealedIncreasing(deck);

    // Print the result
    std::cout << "Deck order for revealing cards in increasing order: ";
    for (int card : result) {
        std::cout << card << " ";
    }
    //--------------------------

    auto value = findTheWinner(5, 2);
    std::cout << "winner: " << value;
    destroyQueue(q);
    myStack->deleteStack(myStack);

    //--------------------------------------
    int element = 5;
    int k = 3;

    // Enqueue elements into the queue
    for (int i = 1; i <= element; i++) {
        enQueue(q, i);
    }

    // Modify the queue
    modifyQueue(q, k);

    // Print the elements of the modified queue
    std::cout << "Modified Queue: ";
    int queueSize = size(q);
    for (int i = 0; i < queueSize; i++) {
        int data = deQueue(q); // Dequeue each element
        std::cout << data << " "; // Print it
        enQueue(q, data); // Enqueue it back to maintain state
    }
    std::cout << std::endl;
    #endif










    /* SetConsoleOutputCP(CP_UTF8);
     std::cout << "नमस्ते!";*/
   
    system("pause>0");
    return 0;
}
