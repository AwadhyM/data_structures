#pragma once

#include <cstddef>
#include <functional>
#include <memory>
#include <vector>

namespace ds {

template <typename T> class BinarySearchTree {
  private:
    struct node {
        T value;
        node *leftChild = nullptr;
        node *rightChild = nullptr;
    };

    node *root = nullptr;

  public:
    BinarySearchTree() = default;

    bool insert(T val) { return insert(val, root); }

    bool empty() { return root == nullptr; }

    bool contains(const T &val) const { return contains(val, root); }

    uint32_t size() { return count(root); }

  private:
    static uint32_t count(node *tree) {
        if (tree == nullptr) {
            return 0;
        }

        return 1 + count(tree->leftChild) + count(tree->rightChild);
    }

    static bool insert(const T &val, node *&tree) {
        if (tree == nullptr) {
            tree = new node;
            tree->value = val;
            return true;
        }

        if (tree->value == val) {
            return false;
        }

        if (val < tree->value) {
            return insert(val, tree->leftChild);
        }

        return insert(val, tree->rightChild);
    }

    static bool contains(const T &val, const node *tree) {
        if (tree == nullptr) {
            return false;
        }

        if (tree->value == val) {
            return true;
        }

        if (val < tree->value) {
            return contains(val, tree->leftChild);
        }

        return contains(val, tree->rightChild);
    }
};

} // namespace ds
