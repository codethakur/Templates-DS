#pragma once
#ifndef BSTTODDL_H
#define BSTTODDL_H
#include "DoublyLinkedList.h"
#include"BinarySearchTree.h"
#include <stack>
#include <memory>
#include"stackArray.h"

using namespace DoublyLinkedList;

namespace BSTtoDLL
{
	class BSTtoDoublyLinkedList
	{
	public:
        std::shared_ptr<ListNode>convertToDLL(std::unique_ptr<BinarySearchTreeNode>& root)
        {
            if (!root) return nullptr;

            static std::shared_ptr<ListNode> head = nullptr;
            static std::shared_ptr<ListNode> prev = nullptr;

            convertToDLL(root->left); 

            std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>();
            newNode->data = root->data;

            if (!head) {
                head = newNode;
            }
            else {
                prev->next = newNode;
                newNode->prev = prev;
            }
            prev = newNode;

            convertToDLL(root->right);
            return head;
        }
        #if 0 

        std::shared_ptr<ListNode> withoutRecursion(std::unique_ptr<BinarySearchTreeNode>& root) {
            if (!root) return nullptr;

            using namespace StackArray;
            
            std::stack<BinarySearchTreeNode*> st; // Use raw pointers for traversal
            BinarySearchTreeNode* curr = root.get(); // Start traversal from root

            std::shared_ptr<ListNode> head = nullptr;
            std::shared_ptr<ListNode> prev = nullptr;

            while (!st.empty() || curr) {
                while (curr) {
                    st.push(curr);
                    curr = curr->left.get(); // Use raw pointer for left traversal
                }

                curr = st.top();
                st.pop();

                // Create DLL node
                std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>();
                newNode->data = curr->data;

                if (!head) {
                    head = newNode; // First node becomes head
                }
                else {
                    prev->next = newNode;
                    newNode->prev = prev;
                }
                prev = newNode; // Move previous forward

                // Move to the right subtree
                curr = curr->right.get(); // Use raw pointer for right traversal
            }

            return head;
        }
       
        #endif
        std::shared_ptr<ListNode> withoutRecursion(std::unique_ptr<BinarySearchTreeNode>& root)
        {
            if (!root) return nullptr;

            BinarySearchTreeNode* curr = root.get(); // Start traversal from root
            StackArray::Stack<BinarySearchTreeNode*> RootStack(5);

            std::shared_ptr<ListNode> head = nullptr;
            std::shared_ptr<ListNode> prev = nullptr;

            while (!RootStack.isEmpty() || curr)
            {
                while (curr) {
                    RootStack.Push(curr);
                    curr = curr->left.get();
                }
                curr = RootStack.Pop(); /* || curr = RootStack.Peek();
                                               RootStack.Pop(); */

                std::shared_ptr<ListNode> newNode = std::make_shared<ListNode>();
                newNode->data = curr->data;

                if (!head) {
                    head = newNode; // First node becomes head
                }
                else
                {
                    prev->next = newNode;
                    newNode->prev = prev;
                }
                prev = newNode;

                curr = curr->right.get();
            }

            return head; 
        }

        std::shared_ptr<BinarySearchTreeNode> DLLtoBST(std::shared_ptr<ListNode>& head)
        {
            if (!head) return nullptr; // Base case

            DoublyLinkedList::LinkedList LL;
            auto temp = LL.FindmidleNode(head); // Find middle element

            if (!temp) return nullptr;

            auto Prev = head;
            while (Prev->next != temp) // Traverse to node before mid
                Prev = Prev->next;

            auto Next = temp->next;

            // Create new BST node using unique_ptr
            std::unique_ptr<BinarySearchTreeNode> root = std::make_unique<BinarySearchTreeNode>();
            root->data = temp->data;

            // Recursively build left and right subtrees
           /* root->left.get() = DLLtoBST(head);
            root->right.get() = DLLtoBST(Next);*/

            return root;
        }







	};
	
}

#endif // !BSTTODDL_H
