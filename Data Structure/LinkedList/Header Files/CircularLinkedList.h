#pragma once
#include<memory>

typedef struct CLLNode {
	int data;
	std::shared_ptr<CLLNode> next;
};

// Function declarations
void CLLinsertAtFront(std::shared_ptr<CLLNode>& head, int data);
void CLLinsertAtEnd(std::shared_ptr<CLLNode>& head, int data);

void CLLDeleteAtFront(std::shared_ptr<CLLNode>& head);
void CLLDeleteAtEnd(std::shared_ptr<CLLNode>& head);
void CLLDeleteAtPosition(std::shared_ptr<CLLNode>& head, int position);

void displayCLL(const std::shared_ptr<CLLNode>& head);
