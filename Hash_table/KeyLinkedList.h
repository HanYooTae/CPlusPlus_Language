// KeyLinkedList.h
// key값을 갖을 수 있는 연결 리스트 자료구조

#pragma once

#include <iostream>
using namespace std;

template <typename T, typename V>
class Node {
public:
    T key;
    V value;
    Node<T, V>* next;
    Node(T key, V value) : key(key), value(value) {}
};

template <typename T, typename V>
class KeyLinkedList {
private:
    int size = 0;
public:
    Node<T, V>* head;

    void add(T key, V value) {
        if (this->head) {
            Node<T, V>* cursor = this->head;
            while (cursor->next) {
                cursor = cursor->next;
            }
            cursor->next = new Node<T, V>(key, value);
        }
        else {
            this->head = new Node<T, V>(key, value);
        }
        this->size++;
    }

    V get(const T& index) {
        Node<T, V>* cursor = this->head;
        while (cursor->key != index) {
            cursor = cursor->next;
        }
        return cursor->value;
    }

    int length() {
        return this->size;
    }
};