//
// Created by Selek, Abdullah on 22.05.17.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../linkedlistcxx.h"

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

TEST_F(LinkedListTests, Initate) {
    EXPECT_TRUE(linkedList != NULL);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
