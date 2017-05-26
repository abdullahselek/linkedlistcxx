//
// Created by Selek, Abdullah on 22.05.17.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/linkedlistcxx.h"

class LinkedListCharTests : public ::testing::Test {

protected:
    virtual ~LinkedListCharTests() {
        // You can do clean-up work that doesn't throw exceptions here.
    }

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    virtual void SetUp() {
        // Code here will be called immediately after the constructor (right
        // before each test).
        linkedList = new LinkedList<char>();
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
        delete linkedList;
    }

public:
    LinkedListCharTests() {
        this->linkedList = new LinkedList<char>();
    }

    LinkedList<char> *linkedList;
};

TEST_F(LinkedListCharTests, Initiate) {
    EXPECT_TRUE(linkedList != NULL);
}

TEST_F(LinkedListCharTests, InitiateNode) {
    char charNext = 'n';
    Node<char> *next = new Node<char>(charNext, nullptr);
    EXPECT_TRUE(next != nullptr);
    char charNode = 'n';
    Node<char> *node = new Node<char>(charNode, next);
    EXPECT_TRUE(node != nullptr);
    EXPECT_EQ(node->next, next);
    delete next;
    delete node;
}

TEST_F(LinkedListCharTests, IsEmpty) {
    EXPECT_TRUE(linkedList->isEmpty());
}

TEST_F(LinkedListCharTests, AddFirst) {
    char charFirst = 'f';
    Node<char> *first = new Node<char>(charFirst, nullptr);
    linkedList->addFirst(first);
    EXPECT_FALSE(linkedList->isEmpty());
    delete first;
}

TEST_F(LinkedListCharTests, GetFirst) {
    char empty = (char) 0;
    EXPECT_TRUE(linkedList->getFirst() == empty);
    char charHead = 'h';
    Node<char> *head = new Node<char>(charHead, nullptr);
    linkedList->addFirst(head);
    EXPECT_FALSE(linkedList->getFirst() == empty);
    delete head;
}

TEST_F(LinkedListCharTests, RemoveFirst) {
    char empty = (char) 0;
    EXPECT_TRUE(linkedList->removeFirst() == empty);
    char charNext = 'n';
    Node<char> *next = new Node<char>(charNext, nullptr);
    char charHead = 'h';
    Node<char> *head = new Node<char>(charHead, next);
    linkedList->addFirst(head);
    EXPECT_FALSE(linkedList->getFirst() == empty);
    ASSERT_EQ(linkedList->removeFirst(), head->data);
    delete next;
    delete head;
}

TEST_F(LinkedListCharTests, AddLast_When_ThereIsNoHead) {
    char charLast = 'l';
    Node<char> *last = new Node<char>(charLast, nullptr);
    linkedList->addLast(last);
    ASSERT_EQ(linkedList->getFirst(), last->data);
    delete last;
}

TEST_F(LinkedListCharTests, AddLast_When_ThereIsAlreadyHead) {
    char charLast = 'l';
    Node<char> *last = new Node<char>(charLast, nullptr);
    char charHead = 'h';
    Node<char> *head = new Node<char>(charHead, last);
    linkedList->addFirst(head);
    linkedList->addLast(last);
    ASSERT_EQ(linkedList->getLast(), last->data);
    delete last;
    delete head;
}

TEST_F(LinkedListCharTests, AddNode) {
    char last = 'l';
    char head = 'h';
    linkedList->add(nullptr, head);
    linkedList->add(linkedList->getHead(), last);
    ASSERT_EQ(linkedList->getFirst(), head);
    ASSERT_EQ(linkedList->getLast(), last);
}

TEST_F(LinkedListCharTests, Clear) {
    char last = 'l';
    char head = 'h';
    linkedList->add(nullptr, head);
    linkedList->add(linkedList->getHead(), last);
    linkedList->clear();
    ASSERT_EQ(linkedList->getFirst(), 0);
    ASSERT_EQ(linkedList->getLast(), 0);
}

TEST_F(LinkedListCharTests, SearchNode) {
    char last = 'l';
    char head = 'h';
    char mid = 'm';
    linkedList->add(nullptr, head);
    linkedList->add(linkedList->getHead(), last);
    linkedList->add(linkedList->getHead(), mid);
    EXPECT_TRUE(linkedList->searchNode(mid) != nullptr);
    linkedList->clear();
    EXPECT_TRUE(linkedList->searchNode(mid) == nullptr);
}

TEST_F(LinkedListCharTests, DeleteNode) {
    char last = 'l';
    char head = 'h';
    char mid = 'm';
    linkedList->add(nullptr, head);
    linkedList->add(linkedList->getHead(), last);
    linkedList->add(linkedList->getHead(), mid);
    Node<char> *node = linkedList->searchNode(mid);
    EXPECT_TRUE(linkedList->deleteNode(node));
}
