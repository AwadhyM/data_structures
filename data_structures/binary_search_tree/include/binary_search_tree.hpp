#pragma once

#include <cstdint>
#include <cstddef>
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

    BinarySearchTree(const BinarySearchTree &) = delete;
    BinarySearchTree &operator=(const BinarySearchTree &) = delete;
    BinarySearchTree(BinarySearchTree &&) = delete;
    BinarySearchTree &operator=(BinarySearchTree &&) = delete;

    bool insert(T val) { return insert(val, root); }

    bool empty() { return root == nullptr; }

    bool contains(const T &val) const { return contains(val, root); }

    std::size_t size() { return count(root); }

    std::vector<T> inOrder() { return inOrder(root); }
    std::vector<T> preOrder() { return preOrder(root); }
    std::vector<T> postOrder() { return postOrder(root); }

    void remove(T val) { remove(val, root); }

    ~BinarySearchTree() { destroy(root); }

  private:
    static void remove(const T &val, node *&tree) {
        if (tree == nullptr) {
            return;
        }

        if (val < tree->value) {
            remove(val, tree->leftChild);
            return;
        }

        if (tree->value < val) {
            remove(val, tree->rightChild);
            return;
        }

        if (tree->leftChild == nullptr) {
            node *replacement = tree->rightChild;
            delete tree;
            tree = replacement;
            return;
        }

        if (tree->rightChild == nullptr) {
            node *replacement = tree->leftChild;
            delete tree;
            tree = replacement;
            return;
        }

        node *successor = tree->rightChild;
        while (successor->leftChild != nullptr) {
            successor = successor->leftChild;
        }

        tree->value = successor->value;
        remove(successor->value, tree->rightChild);
    }

    static void destroy(node *tree) {
        if (tree == nullptr) {
            return;
        }
        destroy(tree->leftChild);
        destroy(tree->rightChild);
        delete tree;
    }

    static std::vector<T> inOrder(node *tree) {
        if (tree == nullptr) {
            return {};
        }

        auto values = inOrder(tree->leftChild);
        values.push_back(tree->value);

        auto right_values = inOrder(tree->rightChild);
        values.insert(values.end(), right_values.begin(), right_values.end());

        return values;
    }

    static std::vector<T> postOrder(node *tree) {
        if (tree == nullptr) {
            return {};
        }

        std::vector<T> values;

        auto left_values = postOrder(tree->leftChild);
        values.insert(values.end(), left_values.begin(), left_values.end());

        auto right_values = postOrder(tree->rightChild);
        values.insert(values.end(), right_values.begin(), right_values.end());

        values.push_back(tree->value);

        return values;
    }

    static std::vector<T> preOrder(node *tree) {
        if (tree == nullptr) {
            return {};
        }

        std::vector<T> values;

        values.push_back(tree->value);

        auto left_values = preOrder(tree->leftChild);
        values.insert(values.end(), left_values.begin(), left_values.end());

        auto right_values = preOrder(tree->rightChild);
        values.insert(values.end(), right_values.begin(), right_values.end());

        return values;
    }

    static std::size_t count(node *tree) {
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
