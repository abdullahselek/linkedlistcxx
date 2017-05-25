//
// Created by Selek, Abdullah on 22.05.17.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/linkedlistcxx.h"

class LinkedListIntegerTests : public ::testing::Test {

protected:
    virtual ~LinkedListIntegerTests() {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    virtual void SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).
        linkedList = new LinkedList<int>();
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
        delete  linkedList;
    }

public:
    LinkedListIntegerTests() {
        this->linkedList = new LinkedList<int>();
    }

    LinkedList<int> *linkedList;
};

TEST_F(LinkedListIntegerTests, Initiate) {
    EXPECT_TRUE(linkedList != NULL);
}

TEST_F(LinkedListIntegerTests, InitiateNode) {
    int intNext = 2;
    Node<int> *next = new Node<int>(intNext, nullptr);
    EXPECT_TRUE(next != nullptr);
    int intNode = 1;
    Node<int> *node = new Node<int>(intNode, next);
    EXPECT_TRUE(node != nullptr);
    EXPECT_EQ(node->next, next);
    delete next;
    delete node;
}

TEST_F(LinkedListIntegerTests, IsEmpty) {
    EXPECT_TRUE(linkedList->isEmpty());
}

TEST_F(LinkedListIntegerTests, AddFirst) {
    int intFirst = 1;
    Node<int> *first = new Node<int>(intFirst, nullptr);
    linkedList->addFirst(first);
    EXPECT_FALSE(linkedList->isEmpty());
    delete first;
}

TEST_F(LinkedListIntegerTests, GetFirst) {
    int empty = 0;
    EXPECT_TRUE(linkedList->getFirst() == empty);
    int intHead = 1;
    Node<int> *head = new Node<int>(intHead, nullptr);
    linkedList->addFirst(head);
    EXPECT_FALSE(linkedList->getFirst() == empty);
    delete head;
}

TEST_F(LinkedListIntegerTests, RemoveFirst) {
    int empty = 0;
    EXPECT_TRUE(linkedList->removeFirst() == empty);
    int intNext = 2;
    Node<int> *next = new Node<int>(intNext, nullptr);
    int intHead = 1;
    Node<int> *head = new Node<int>(intHead, next);
    linkedList->addFirst(head);
    EXPECT_FALSE(linkedList->getFirst() == empty);
    ASSERT_EQ(linkedList->removeFirst(), head->data);
    delete next;
    delete head;
}

TEST_F(LinkedListIntegerTests, AddLast_When_ThereIsNoHead) {
    int intLast = 1;
    Node<int> *last = new Node<int>(intLast, nullptr);
    linkedList->addLast(last);
    ASSERT_EQ(linkedList->getFirst(), last->data);
    delete last;
}

TEST_F(LinkedListIntegerTests, AddLast_When_ThereIsAlreadyHead) {
    int intLast = 2;
    Node<int> *last = new Node<int>(intLast, nullptr);
    int intHead = 1;
    Node<int> *head = new Node<int>(intHead, last);
    linkedList->addFirst(head);
    linkedList->addLast(last);
    ASSERT_EQ(linkedList->getLast(), last->data);
    delete last;
    delete head;
}

TEST_F(LinkedListIntegerTests, AddNode) {
    int last = 2;
    int head = 1;
    linkedList->add(nullptr, head);
    linkedList->add(linkedList->getHead(), last);
    ASSERT_EQ(linkedList->getFirst(), head);
    ASSERT_EQ(linkedList->getLast(), last);
}

TEST_F(LinkedListIntegerTests, Clear) {
    int last = 2;
    int head = 1;
    linkedList->add(nullptr, head);
    linkedList->add(linkedList->getHead(), last);
    linkedList->clear();
    ASSERT_EQ(linkedList->getFirst(), 0);
    ASSERT_EQ(linkedList->getLast(), 0);
}

TEST_F(LinkedListIntegerTests, SearchNode) {
    int last = 3;
    int head = 1;
    int mid = 2;
    linkedList->add(nullptr, head);
    linkedList->add(linkedList->getHead(), last);
    linkedList->add(linkedList->getHead(), mid);
    EXPECT_TRUE(linkedList->searchNode(mid) != nullptr);
    linkedList->clear();
    EXPECT_TRUE(linkedList->searchNode(mid) == nullptr);
}

TEST_F(LinkedListIntegerTests, DeleteNode) {
    int last = 3;
    int head = 1;
    int mid = 2;
    linkedList->add(nullptr, head);
    linkedList->add(linkedList->getHead(), last);
    linkedList->add(linkedList->getHead(), mid);
    Node<int> *node = linkedList->searchNode(mid);
    EXPECT_TRUE(linkedList->deleteNode(node));
}
