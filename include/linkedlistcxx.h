//
// Created by Selek, Abdullah on 22.05.17.
//

#ifndef LINKEDLISTCXX_LINKEDLISTCXX_H
#define LINKEDLISTCXX_LINKEDLISTCXX_H

#include <string>
#include <iostream>

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
    bool isEmpty();
    void addFirst(Node *node);
    Node *getHead();
    std::string getFirst();
    std::string removeFirst();
    void addLast(Node *node);
    std::string getLast();
    void add(Node *head, std::string data);
    void clear();
    Node *searchNode(std::string data);

private:
    Node *head;

};

#endif //LINKEDLISTCXX_LINKEDLISTCXX_H