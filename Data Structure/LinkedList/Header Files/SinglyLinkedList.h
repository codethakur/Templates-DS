#pragma once
#ifndef SINGLELYNKEDLIST_H
#define SINGLELYNKEDLIST_H

#include <iostream>
#include <stdexcept>
#include <memory>

namespace SinglyLinkedList
{
    struct ListNode
    {
        int data;
        std::shared_ptr<ListNode> next;
    };

    class LinkedList
    {
    public:
        // Insert a node at the front of the list
        std::shared_ptr<ListNode> insertAtFront(std::shared_ptr<ListNode> head, int data)
        {
            // Use make_shared to allocate memory for the new node
            auto temp = std::make_shared<ListNode>();
            temp->data = data;
            temp->next = nullptr; // New node's next should point to nullptr

            if (head == nullptr) {
                head = std::move(temp);  
            }
            else {
                temp->next = head;  // New node points to the old head
                head = std::move(temp); // Head now points to the new node
            }

            return head;  // Return the updated head pointer
        }

        // Display the entire linked list

        std::shared_ptr<ListNode> insertAtEnd(std::shared_ptr<ListNode> head, int data)
        {
            // If the list is empty, create a new node and make it the head
            if (head == nullptr) {
                auto temp = std::make_shared<ListNode>();
                temp->data = data;
                temp->next = nullptr;
                return temp; // Return the new node as the head
            }

            // Otherwise, traverse to the end of the list and insert the new node
            auto current = head;
            while (current->next != nullptr) {
                current = current->next;
            }

            // Now current points to the last node, insert the new node
            auto temp = std::make_shared<ListNode>();
            temp->data = data;
            temp->next = nullptr; // The new node's next will be null
            current->next = temp; // The last node now points to the new node

            return head; // Return the head (unchanged)
        }

        std::shared_ptr<ListNode> insertAtMiddle(std::shared_ptr<ListNode>&head, int data)
        {
            if (!head) {
                throw std::runtime_error("List is empty!");
            }

            auto temp = std::make_shared<ListNode>();
            temp->data = data;
            temp->next = nullptr;

            // If the list has only one node, we can insert it after the head
            if (!head->next) {
                head->next = temp;
                return head;
            }

            // Use two pointers: slow and fast
            auto slow = head;
            auto fast = head;

            // Traverse the list, fast moves twice as fast as slow
            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;       // slow moves one step
                fast = fast->next->next; // fast moves two steps
            }

            // Insert temp after the slow pointer (at the middle)
            temp->next = slow->next;
            slow->next = temp;

            return head; // Return the updated list
        }

        std::shared_ptr<ListNode> insertAtGivenPosition(std::shared_ptr<ListNode>&head, int data, int position)
        {
            if (head == nullptr) {
                throw  std::runtime_error("List is empty!");
                return nullptr;
            }
            else
            {
                // Use make_shared to allocate memory for the new node
                auto temp = std::make_shared<ListNode>();
                temp->data = data;
                temp->next = nullptr; // New node's next should point to nullptr
                
                if (position <= 1) {
                    head->next = temp;
                    return head;
                }
                auto curr = head;
                while (--position && curr!= nullptr)
                {
                    curr = curr->next;
                }
                if (curr == nullptr) {
                    throw std::runtime_error("position is not valid");
                    return nullptr;
                }
                temp->next = curr->next;
                curr->next = temp;
            }

            return head;

        }

        void deleteFirstNode(std::shared_ptr<ListNode>&head)
        {
            if (head == nullptr) {
                throw std::runtime_error("List is not found");
                return;
            }
            head = head->next;
        }

        void deleteLastNode(std::shared_ptr<ListNode>& head) 
        {
            if (!head) {
                throw std::runtime_error("List is not found");
            }

            if (!head->next) { // If there is only one node in the list
                std::cerr << "There was only one node, deleting it!\n";
                head = nullptr; // ||   head.reset();
                return;
            }

            // Use a pointer to traverse, but don't modify `head` itself
            auto current = head;
            while (current->next->next) { 
                current = current->next;
            }

            current->next = nullptr; 
        }
        void deleteIntermediate(std::shared_ptr<ListNode>& head)
        {
            if (!head) {
                throw std::runtime_error("List is not found");
            }

            if (!head->next) { // If there is only one node in the list
                std::cerr << "There was only one node, deleting it!\n";
                head = nullptr; // ||   head.reset();
                return;
            }

            // Use a pointer to traverse, but don't modify `head` itself
            auto current = head;
        }

        void DisplayLinkedList(std::shared_ptr<ListNode> head) const
        {
            if (head == nullptr) {
                throw  std::runtime_error("List is empty!");
                return;
            }

            auto current = head;
            while (current != nullptr) {
                std::clog << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    };
}

#endif // SINGLELYNKEDLIST_H
