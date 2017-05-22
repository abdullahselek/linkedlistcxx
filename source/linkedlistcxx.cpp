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
