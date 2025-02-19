#include<vector>

static std::unique_ptr<BinarySearchTreeNode> ArrtoTree(const std::vector<int>& array, int left, int right) {
    if (left > right) return nullptr;

    unsigned int mid = left + (right - left) / 2;

    auto newNode = std::make_unique<BinarySearchTreeNode>(); 
    newNode->data = array[mid];

    newNode->left = ArrtoTree(array, left, mid - 1);
    newNode->right = ArrtoTree(array, mid + 1, right);

    return newNode;
}

#if 0
#pragma once
#include"BinarySearchTree.h"
#include<memory>
#include<vector>

static std::unique_ptr<BinarySearchTreeNode> ArrtoTree(const std::vector<int>& array, int left, int right) {
    if (left > right) return nullptr;

    unsigned int mid = left + (right - left) / 2;

    auto newNode = std::make_unique<BinarySearchTreeNode>(); 
    newNode->data = array[mid];

    newNode->left = ArrtoTree(array, left, mid - 1);
    newNode->right = ArrtoTree(array, mid + 1, right);

    return newNode;
}

#endif
