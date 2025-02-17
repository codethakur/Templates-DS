#include "CircularLinkedList.h"
#include"iostream"


void CLLinsertAtFront(std::shared_ptr<CLLNode>& head, int data)
{
    std::shared_ptr<CLLNode> newNode = std::make_shared<CLLNode>();


    newNode->data = data;
    newNode->next = newNode;

    if (!head) {
        head = newNode;
        return;
    }
    std::shared_ptr<CLLNode> current = head;
    while (current->next != head) {
        current = current->next;
    }

    newNode->next = head;
    current->next = newNode;
    head = newNode;
}

void CLLinsertAtEnd(std::shared_ptr<CLLNode>& head, int data)
{
    auto newNode = std::make_shared<CLLNode>();


    newNode->data = data;
    newNode->next = newNode;

    if (!head) {
        head = newNode;
        return;
    }
    std::shared_ptr<CLLNode> current = head;
    while (current->next != head) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;


}

void CLLDeleteAtFront(std::shared_ptr<CLLNode>& head)
{
    if (!head) {
        std::cerr << "List is empty!" << std::endl;
        return;
    }

    // If there is only one node in the list
    if (head->next == head) {
        head.reset();  // The list becomes empty
        return;
    }

    // Traverse to the last node (which points to head)
    auto current = head;
    while (current->next != head) {
        current = current->next;
    }

    // Update the last node to point to the second node
    current->next = head->next;

    // Remove the current head (the smart pointer will handle memory deallocation)
    head = head->next;
}

void CLLDeleteAtEnd(std::shared_ptr<CLLNode>& head)
{
    if (!head) {
        std::cerr << "List is empty!" << std::endl;
        return;
    }

    // If there is only one node in the list
    if (head->next == head) {
        head.reset();  // The list becomes empty
        return;
    }
    auto current = head;
    auto temp = head;

    while (current->next != head) {
        temp = current;
        current = current->next;
    }
    temp->next = head;

}

void CLLDeleteAtPosition(std::shared_ptr<CLLNode>& head, int position)
{
    if (!head) {
        std::cerr << "List is empty!" << std::endl;
        return;
    }

    // Deleting the head node (position 1)
    if (position == 1) {
        if (head->next == head) {
            head.reset(); // Only one node, reset the list
        }
        else {
            auto temp = head;
            auto current = head;
            // Traverse to the last node
            while (current->next != head) {
                current = current->next;
            }
            // Now 'current' is the last node
            current->next = head->next;  // Update last node's next to skip the head
            head = head->next;           // Move head to the next node
        }
        return;
    }

    int k = 1;
    auto current = head;
    auto temp = head;

    // Traverse to the position before the node to be deleted
    while (k < position && temp->next != head) {
        current = temp;
        temp = temp->next;
        k++;
    }

    if (temp->next == head) {
        std::cerr << "Position is greater than the number of nodes!" << std::endl;
        return;
    }

    // Now 'temp' points to the node to be deleted, 'current' points to the previous node
    current->next = temp->next;  // Remove the node from the list
}



void displayCLL(const std::shared_ptr<CLLNode>& head)
{
    std::shared_ptr<CLLNode>current = head;
    double length = 0;
    if (head == NULL) {
        std::cerr << "List is empty!";
        return;
    }
    do {
        if (current == head) {
            std::cout << "--";
        }
        std::cout << current->data;
        if (current->next != head) {
            std::cout << "->";
        }
        else {
            std::cout << "--";
        }

        current = current->next;
        length++;
    } while (current != head);
    length = length * 3.25;
    std::cout << "\n" << std::string(length, '-') << std::endl;


}

#if 0
#include <iostream>
 
#include"CircularLinkedList.h"

int main() {
    std::shared_ptr<CLLNode> head = nullptr;

    CLLinsertAtFront(head, 1);
    CLLinsertAtFront(head, 2);
    CLLinsertAtFront(head, 3);
    CLLinsertAtFront(head, 4);
    CLLinsertAtFront(head, 5);
    CLLinsertAtFront(head, 6);
    CLLinsertAtFront(head, 7);
    CLLinsertAtFront(head, 8);
    displayCLL(head);

    std::cout << "CLLinsertAtEnd: 0\n";
    CLLinsertAtEnd(head, 0);
    displayCLL(head);

    std::cout << "\n" << "CLLDeleteAtFront\n";
    CLLDeleteAtFront(head);
    displayCLL(head);

    std::cout << "\n" << "CLLDeleteAtEnd\n";
    CLLDeleteAtEnd(head);
    displayCLL(head);

    std::cout << "\n" << "CLLDeleteAtPosition\n";
    CLLDeleteAtPosition(head, 3);
    displayCLL(head);




    std::cin.get();
}

#endif
