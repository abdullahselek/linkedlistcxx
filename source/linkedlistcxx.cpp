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

Node * LinkedList::getHead() {
    return this->head;
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

void LinkedList::add(Node *head, std::string data) {
    Node *cur;
    Node *newNode = new Node(data, nullptr);
    if (this->head == nullptr) {
        this->head = newNode;
        return;
    }
    cur = head;
    while (cur) {
        if (cur->next == nullptr) {
            cur->next = newNode;
            return;
        }
        cur = cur->next;
    }
}

void LinkedList::clear() {
    Node *p, *q;
    if (this->head == nullptr) {
        return;
    }
    p = this->head;
    while (p) {
        q = p->next;
        delete p;
        if (q != this->head)  {
            this->head = nullptr;
            return;
        }
        p = q;
    }
}

Node * LinkedList::searchNode(std::string data) {
    Node *cur = this->head;
    while (cur) {
        if (cur->data == data) {
            return cur;
        }
        cur = cur->next;
    }
    std::cout << "No Node " << data << " in list" << std::endl;
    return nullptr;
}
