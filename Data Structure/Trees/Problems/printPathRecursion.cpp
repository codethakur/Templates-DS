#include "../Header/Tree.h"
#include <queue>
#include <iostream>
#include <iostream>
#include <vector>
#include <memory>
void printPath(const std::vector<int>& path) {
    for (size_t i = 0; i < path.size(); ++i) {
        // Print leading spaces to represent depth
        for (size_t j = 0; j < i; ++j) {
            std::cout << "  ";
        }
        std::cout << path[i] << "\n";
        // Print connector if not the last node
        if (i < path.size() - 1) {
            for (size_t j = 0; j <= i; ++j) {
                std::cout << "  ";
            }
            std::cout << "|\n";
        }
    }
    std::cout << "\n"; // Separate paths by a newline
}

#if 0
void printPath(std::vector<int>&path)
{
    for(const auto data:path){
        std::cout<<data<<" ";
    }
    std::cout<<std::endl;
}
#endif
void findRootToLeafPaths(const std::shared_ptr<BinaryTreeNode> root, std::vector<int>&path)
{
    if(!root) return;
    path.push_back(root->data);
    if(!root->left && !root->right){
        printPath(path);
    }
    else{
        findRootToLeafPaths(root->left,path);
        findRootToLeafPaths(root->right, path);
    }
    // Backtrack - remove the last node 
    path.pop_back();//Backtrack to explore other paths.
}
void printAllRootToLeafPaths(const std::shared_ptr<BinaryTreeNode> root) {
    std::vector<int> path;
    findRootToLeafPaths(root, path);
}
