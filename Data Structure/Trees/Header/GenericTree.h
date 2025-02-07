#include <memory>

template <typename T>
struct GenericTree
{
    T data;
    std::shared_ptr<GenericTree<T>> FirstChild; // Use GenericTree<T>
    std::shared_ptr<GenericTree<T>> nextSibling;

    GenericTree(T value) : data(value), FirstChild(nullptr), nextSibling(nullptr) {}
};

class GenericBinaryTree
{
public:
    int sumOfGenericTreeWithRecursion(const std::shared_ptr<GenericTree<char>> &parent)
    {
        if (!parent)
        {
            return 0;
        }
        return parent->data + sumOfGenericTreeWithRecursion(parent->FirstChild) +
               sumOfGenericTreeWithRecursion(parent->nextSibling);
    }

    int siblingCount(const std::shared_ptr<GenericTree<char>> &current)
    {
        if (!current)
        {
            return 0;
        }
        int count = 0;
        std::shared_ptr<GenericTree<char>> temp = current; // Create a mutable copy

        while (temp)
        {
            count++;
            temp = temp->nextSibling;
        }
        return count;
    }
    int ChildCount(std::shared_ptr<GenericTree<char>> node)
    {
        if (!node || !node->FirstChild)
            return 0;

        int count = 0;
        auto child = node->FirstChild;

        while (child)
        {
            count++;
            child = child->nextSibling;
        }

        return count;
    }
};
