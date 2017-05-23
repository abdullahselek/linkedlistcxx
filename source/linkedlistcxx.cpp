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
