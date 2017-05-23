//
// Created by Selek, Abdullah on 22.05.17.
//

#include "../include/linkedlistcxx.h"

LinkedList::LinkedList() {
    this->head = nullptr;
}

LinkedList::~LinkedList() {

}

bool LinkedList::isEmpty() {
    return this->head == nullptr;
}

void LinkedList::addFirst(Node *node) {
    this->head = node;
}

std::string LinkedList::getFirst() {
    if (this->head == nullptr) {
        return "";
    }
    return this->head->data;
}

std::string LinkedList::removeFirst() {
    std::string tmp = getFirst();
    if (tmp.empty()) {
        return "";
    }
    this->head = head->next;
    return tmp;
}

void LinkedList::addLast(Node *node) {
    if (this->head == nullptr) {
        addFirst(node);
    } else {
        Node *tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new Node(node->data, nullptr);
    }
}

std::string LinkedList::getLast() {
    if (this->head == nullptr) {
        return "";
    }
    Node *tmp = this->head;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    return tmp->data;
}
