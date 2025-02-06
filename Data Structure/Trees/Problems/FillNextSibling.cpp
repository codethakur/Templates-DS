#include <iostream>
#include <memory>
#include <queue>

class BinaryTreeSibling {
private:
    int data;
    std::shared_ptr<BinaryTreeSibling> left = nullptr;
    std::shared_ptr<BinaryTreeSibling> right = nullptr;
    std::shared_ptr<BinaryTreeSibling> NextSibling = nullptr;

public:
    // Constructor
    BinaryTreeSibling(int value) : data(value) {}

    // Getter and Setter for data
    int getData() const { return data; }
    void setData(int value) { data = value; }

    // Getters and Setters for left and right children
    std::shared_ptr<BinaryTreeSibling> getLeft() const { return left; }
    void setLeft(std::shared_ptr<BinaryTreeSibling> node) { left = node; }

    std::shared_ptr<BinaryTreeSibling> getRight() const { return right; }
    void setRight(std::shared_ptr<BinaryTreeSibling> node) { right = node; }

    // Getter and Setter for NextSibling
    std::shared_ptr<BinaryTreeSibling> getNextSibling() const { return NextSibling; }
    void setNextSibling(std::shared_ptr<BinaryTreeSibling> node) { NextSibling = node; }
};

class FillNextSibling {
public:
    void withoutRecursion(std::shared_ptr<BinaryTreeSibling> root) {
        if (!root) return;

        std::queue<std::shared_ptr<BinaryTreeSibling>> q;
        q.push(root);
        q.push(nullptr); // Level separator

        while (!q.empty()) {
            auto temp = q.front();
            q.pop(); 

            if (temp) {
                temp->setNextSibling(q.front()); // Set the next sibling

                if (temp->getLeft()) q.push(temp->getLeft());
                if (temp->getRight()) q.push(temp->getRight());
            } else if (!q.empty()) {
                q.push(nullptr); // Add level separator for the next level
            }
        }
    }

    void withRecursion(std::shared_ptr<BinaryTreeSibling> root) {
    if (!root) {
        return;
    }

    // Set the next sibling for the left child
    if (root->getLeft()) {
        root->getLeft()->setNextSibling(root->getRight());
    }

    // Set the next sibling for the right child
    if (root->getRight()) {
        root->getRight()->setNextSibling(
            root->getNextSibling() ? root->getNextSibling()->getLeft() : nullptr
        );
    }

    // Recursive calls
    withRecursion(root->getLeft());
    withRecursion(root->getRight());
}

    // Function to print next sibling of each node
    void printNextSiblings(std::shared_ptr<BinaryTreeSibling> root) {
        if (!root) return;
        
        std::queue<std::shared_ptr<BinaryTreeSibling>> q;
        q.push(root);
        
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();
            
            std::cout << temp->getData() << " -> ";
            if (temp->getNextSibling()) {
                std::cout << temp->getNextSibling()->getData();
            } else {
                std::cout << "NULL";
            }
            std::cout << std::endl;
            
            if (temp->getLeft()) q.push(temp->getLeft());
            if (temp->getRight()) q.push(temp->getRight());
        }
    }
};

#if 0
  auto root = std::make_shared<BinaryTreeSibling>(1);
    root->setLeft(std::make_shared<BinaryTreeSibling>(2));
    root->setRight(std::make_shared<BinaryTreeSibling>(3));
    root->getLeft()->setLeft(std::make_shared<BinaryTreeSibling>(4));
    root->getLeft()->setRight(std::make_shared<BinaryTreeSibling>(5));
    root->getRight()->setLeft(std::make_shared<BinaryTreeSibling>(6));
    root->getRight()->setRight(std::make_shared<BinaryTreeSibling>(7));
    FillNextSibling sibling;
    sibling.withoutRecursion(root);

    sibling.printNextSiblings(root);
#endif


