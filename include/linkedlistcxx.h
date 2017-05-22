//
// Created by Selek, Abdullah on 22.05.17.
//

#ifndef LINKEDLISTCXX_LINKEDLISTCXX_H
#define LINKEDLISTCXX_LINKEDLISTCXX_H

#include <string>

struct Node {
    std::string data;
    Node *next;

    Node(std::string data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

class LinkedList {

public:
    LinkedList();
    ~LinkedList();



};

#endif //LINKEDLISTCXX_LINKEDLISTCXX_H