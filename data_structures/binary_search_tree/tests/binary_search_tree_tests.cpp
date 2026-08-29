#include <gtest/gtest.h>
#include "binary_search_tree.hpp"

TEST(BinarySearchTreeTest, SuccessfullyAddToEmptyBinarySearchTree) {
    auto bst = ds::BinarySearchTree<int>();
    bst.insert(42);
    EXPECT_EQ(bst.contains(42), true);
}

TEST(BinarySearchTreeTest, SuccessfullyAddLowerValueToBinaryTree) {
    auto bst = ds::BinarySearchTree<int>();
    bst.insert(42);
    EXPECT_EQ(bst.contains(42), true);
    bst.insert(36);
    EXPECT_EQ(bst.contains(36), true);
    bst.insert(30);
    EXPECT_EQ(bst.contains(30), true);
}

TEST(BinarySearchTreeTest, SuccessfullyAddHigherValueToBinaryTree) {
    auto bst = ds::BinarySearchTree<int>();
    bst.insert(42);
    EXPECT_EQ(bst.contains(42), true);
    bst.insert(44);
    EXPECT_EQ(bst.contains(44), true);
    bst.insert(49);
    EXPECT_EQ(bst.contains(49), true);
}

TEST(BinarySearchTreeTest, ReturnFalseForDuplicates) {
    auto bst = ds::BinarySearchTree<int>();
    bst.insert(42);
    EXPECT_EQ(bst.contains(42), true);
    EXPECT_EQ(bst.insert(42), false);
    EXPECT_EQ(bst.size(), 1);
}

TEST(BinarySearchTreeTest, SuccessfullyAddValueToLeftChildOfRightSubtree) {
    auto bst = ds::BinarySearchTree<int>();

    bst.insert(42);
    bst.insert(50);
    bst.insert(45);
    EXPECT_EQ(bst.size(), 3);
    EXPECT_TRUE(bst.contains(45));
}

TEST(BinarySearchTreeTest, SuccessfullyAddValueToRightChildOfLeftSubtree) {
    auto bst = ds::BinarySearchTree<int>();

    bst.insert(42);
    bst.insert(30);
    bst.insert(35);

    EXPECT_EQ(bst.size(), 3);
    EXPECT_TRUE(bst.contains(35));
}

TEST(BinarySearchTreeTest, SuccessfullyCountBothSides) {
    auto bst = ds::BinarySearchTree<int>();
    bst.insert(42);
    bst.insert(45);
    bst.insert(36);
    bst.insert(35);
    bst.insert(38);
    bst.insert(50);
    bst.insert(45);
    EXPECT_EQ(bst.size(), 6);
}
