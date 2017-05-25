//
// Created by Selek, Abdullah on 22.05.17.
//

#include <string>
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
        linkedList = new LinkedList<std::string>();
    }

    virtual void TearDown() {
        // Code here will be called immediately after each test (right
        // before the destructor).
        delete  linkedList;
    }

public:
    LinkedListTests() {
        this->linkedList = new LinkedList<std::string>();
    }

    LinkedList<std::string> *linkedList;
};

TEST_F(LinkedListTests, Initiate) {
    EXPECT_TRUE(linkedList != NULL);
}

TEST_F(LinkedListTests, InitiateNode) {
    std::string strNext("next");
    Node<std::string> *next = new Node<std::string>(strNext, nullptr);
    EXPECT_TRUE(next != nullptr);
    std::string strNode("node");
    Node<std::string> *node = new Node<std::string>(strNode, next);
    EXPECT_TRUE(node != nullptr);
    EXPECT_EQ(node->next, next);
    delete next;
    delete node;
}

TEST_F(LinkedListTests, IsEmpty) {
    EXPECT_TRUE(linkedList->isEmpty());
}

TEST_F(LinkedListTests, AddFirst) {
    std::string strFirst("first");
    Node<std::string> *first = new Node<std::string>(strFirst, nullptr);
    linkedList->addFirst(first);
    EXPECT_FALSE(linkedList->isEmpty());
    delete first;
}

TEST_F(LinkedListTests, GetFirst) {
    std::string empty("");
    EXPECT_TRUE(linkedList->getFirst() == empty);
    std::string strHead("head");
    Node<std::string> *head = new Node<std::string>(strHead, nullptr);
    linkedList->addFirst(head);
    EXPECT_FALSE(linkedList->getFirst() == empty);
    delete head;
}

TEST_F(LinkedListTests, RemoveFirst) {
    std::string empty("");
    EXPECT_TRUE(linkedList->removeFirst() == empty);
    std::string strNext("next");
    Node<std::string> *next = new Node<std::string>(strNext, nullptr);
    std::string strHead("head");
    Node<std::string> *head = new Node<std::string>(strHead, next);
    linkedList->addFirst(head);
    EXPECT_FALSE(linkedList->getFirst() == empty);
    ASSERT_EQ(linkedList->removeFirst(), head->data);
    delete next;
    delete head;
}

TEST_F(LinkedListTests, AddLast_When_ThereIsNoHead) {
    std::string strLast("last");
    Node<std::string> *last = new Node<std::string>(strLast, nullptr);
    linkedList->addLast(last);
    ASSERT_EQ(linkedList->getFirst(), last->data);
    delete last;
}

TEST_F(LinkedListTests, AddLast_When_ThereIsAlreadyHead) {
    std::string strLast("last");
    Node<std::string> *last = new Node<std::string>(strLast, nullptr);
    std::string strHead("head");
    Node<std::string> *head = new Node<std::string>(strHead, last);
    linkedList->addFirst(head);
    linkedList->addLast(last);
    ASSERT_EQ(linkedList->getLast(), last->data);
    delete last;
    delete head;
}

TEST_F(LinkedListTests, AddNode) {
    std::string last("last");
    std::string head("head");
    linkedList->add(nullptr, head);
    linkedList->add(linkedList->getHead(), last);
    ASSERT_EQ(linkedList->getFirst(), head);
    ASSERT_EQ(linkedList->getLast(), last);
}

TEST_F(LinkedListTests, Clear) {
    std::string last("last");
    std::string head("head");
    linkedList->add(nullptr, head);
    linkedList->add(linkedList->getHead(), last);
    linkedList->clear();
    ASSERT_EQ(linkedList->getFirst(), "");
    ASSERT_EQ(linkedList->getLast(), "");
}

TEST_F(LinkedListTests, SearchNode) {
    std::string last("last");
    std::string head("head");
    std::string mid("mid");
    linkedList->add(nullptr, head);
    linkedList->add(linkedList->getHead(), last);
    linkedList->add(linkedList->getHead(), mid);
    EXPECT_TRUE(linkedList->searchNode(mid) != nullptr);
    linkedList->clear();
    EXPECT_TRUE(linkedList->searchNode(mid) == nullptr);
}

TEST_F(LinkedListTests, DeleteNode) {
    std::string last("last");
    std::string head("head");
    std::string mid("mid");
    linkedList->add(nullptr, head);
    linkedList->add(linkedList->getHead(), last);
    linkedList->add(linkedList->getHead(), mid);
    Node<std::string> *node = linkedList->searchNode(mid);
    EXPECT_TRUE(linkedList->deleteNode(node));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
