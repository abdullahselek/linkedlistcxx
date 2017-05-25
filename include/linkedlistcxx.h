//
// Created by Selek, Abdullah on 22.05.17.
//

#ifndef LINKEDLISTCXX_LINKEDLISTCXX_H
#define LINKEDLISTCXX_LINKEDLISTCXX_H

#include <string>
#include <iostream>

template <typename T>
struct Node {
    T data;
    Node *next;

    Node<T>(T data, Node *next) {
        this->data = data;
        this->next = next;
    }
};

template <typename T>
class LinkedList {

public:
    LinkedList();
    ~LinkedList();
    bool isEmpty();
    void addFirst(Node<T> *node);
    Node<T> *getHead();
    T getFirst();
    T removeFirst();
    void addLast(Node<T> *node);
    T getLast();
    void add(Node<T> *head, T data);
    void clear();
    Node<T> *searchNode(T data);
    bool deleteNode(Node<T> *node);

private:
    Node<T> *head;

};

template <typename T>
LinkedList<T>::LinkedList() {
    this->head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList() {

}

template <typename T>
bool LinkedList<T>::isEmpty() {
    return this->head == nullptr;
}

template <typename T>
void LinkedList<T>::addFirst(Node<T> *node) {
    this->head = node;
}

template <typename T>
Node<T> * LinkedList<T>::getHead() {
    return this->head;
}

template <typename T>
T LinkedList<T>::getFirst() {
    if (this->head == nullptr) {
        return T{};
    }
    return this->head->data;
}

template <typename T>
T LinkedList<T>::removeFirst() {
    T tmp = getFirst();
    if (tmp == T{}) {
        return T{};
    }
    this->head = head->next;
    return tmp;
}

template <typename T>
void LinkedList<T>::addLast(Node<T> *node) {
    if (this->head == nullptr) {
        addFirst(node);
    } else {
        Node<T> *tmp = head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        tmp->next = new Node<T>(node->data, nullptr);
    }
}

template <typename T>
T LinkedList<T>::getLast() {
    if (this->head == nullptr) {
        return T{};
    }
    Node<T> *tmp = this->head;
    while (tmp->next != nullptr) {
        tmp = tmp->next;
    }
    return tmp->data;
}

template <typename T>
void LinkedList<T>::add(Node<T> *head, T data) {
    Node<T> *cur;
    Node<T> *newNode = new Node<T>(data, nullptr);
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

template <typename T>
void LinkedList<T>::clear() {
    Node<T> *p, *q;
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

template <typename T>
Node<T> * LinkedList<T>::searchNode(T data) {
    Node<T> *cur = this->head;
    while (cur) {
        if (cur->data == data) {
            return cur;
        }
        cur = cur->next;
    }
    std::cout << "No Node<T> " << data << " in list" << std::endl;
    return nullptr;
}

template <typename T>
bool LinkedList<T>::deleteNode(Node<T> *node) {
    Node<T> *cur = this->head;
    if (node == this->head) {
        this->head = cur->next;
        delete node;
        return true;
    }

    while(cur) {
        if(cur->next == node) {
            cur->next = node->next;
            delete node;
            return true;
        }
        cur = cur->next;
    }
    return false;
}

#endif //LINKEDLISTCXX_LINKEDLISTCXX_H