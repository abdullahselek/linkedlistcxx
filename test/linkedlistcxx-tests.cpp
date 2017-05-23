//
// Created by Selek, Abdullah on 22.05.17.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/linkedlistcxx.h"

class LinkedListTests : public ::testing::Test {

protected:
    virtual ~LinkedListTests() {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    virtual void SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).
        linkedList = new LinkedList();
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
        delete  linkedList;
    }

public:
    LinkedListTests() {
        this->linkedList = new LinkedList();
    }

    LinkedList *linkedList;
};

TEST_F(LinkedListTests, Initiate) {
    EXPECT_TRUE(linkedList != NULL);
}

TEST_F(LinkedListTests, InitiateNode) {
    Node *next = new Node("next", nullptr);
    EXPECT_TRUE(next != nullptr);
    Node *node = new Node("node", next);
    EXPECT_TRUE(node != nullptr);
    EXPECT_EQ(node->next, next);
    delete next;
    delete node;
}

TEST_F(LinkedListTests, IsEmpty) {
    EXPECT_TRUE(linkedList->isEmpty());
}

TEST_F(LinkedListTests, AddFirst) {
    Node *first = new Node("first", nullptr);
    linkedList->addFirst(first);
    EXPECT_FALSE(linkedList->isEmpty());
    delete first;
}

TEST_F(LinkedListTests, GetFirst) {
    EXPECT_TRUE(linkedList->getFirst().empty());
    Node *head = new Node("head", nullptr);
    linkedList->addFirst(head);
    EXPECT_FALSE(linkedList->getFirst().empty());
    delete head;
}

TEST_F(LinkedListTests, RemoveFirst) {
    EXPECT_TRUE(linkedList->removeFirst().empty());
    Node *next = new Node("next", nullptr);
    Node *head = new Node("head", next);
    linkedList->addFirst(head);
    EXPECT_FALSE(linkedList->getFirst().empty());
    ASSERT_EQ(linkedList->removeFirst(), head->data);
    delete next;
    delete head;
}

TEST_F(LinkedListTests, AddLast_When_ThereIsNoHead) {
    Node *last = new Node("last", nullptr);
    linkedList->addLast(last);
    ASSERT_EQ(linkedList->getFirst(), last->data);
    delete last;
}

TEST_F(LinkedListTests, AddLast_When_ThereIsAlreadyHead) {
    Node *last = new Node("last", nullptr);
    Node *head = new Node("head", last);
    linkedList->addFirst(head);
    linkedList->addLast(last);
    ASSERT_EQ(linkedList->getLast(), last->data);
    delete last;
    delete head;
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
