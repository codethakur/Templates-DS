#include "./Header/ThreadBinaryTree.h"
#include <iostream>
#include <vector>
int main()
{
    std::vector<int> data = {10, 5, 15, 2,  12, 20};

    threadedTree Tree;
    auto root = Tree.buildThreadTree(data);

    std::cout << "Inorder:" << std::endl;
    Tree.inorder(root);

    std::cout << "\nPreOrder:" << std::endl;
    Tree.preorder(root);
    std::cout << "\n-----------------------\n";
    Tree.deleteNode(root, 5);
    Tree.preorder(root);

    return 0;
}

/*
        10
       /  \
      5    15
     / \   /  \
    2   7 12   20

*/
/*
                                        [false | 5 | 10 | 15 | false]
                                                /               \

                                 [false | 2 | 5 | 7 | false]                                     [false | 12 | 15 | 20 | false]
                                          /        \                                                     /            \


[true | NULL | 2 | 5 | true]  [true | 5 | 7 | 10 | true]  [true | 10 | 12 | 15 | true]   [true | 15 | 20 | NULL | true]

*/
