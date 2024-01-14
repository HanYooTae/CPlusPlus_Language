// HashMap.h

#pragma once
#include "KeyLinkedList.h"
#include <string>
#include <stdexcept>

using namespace std;

template <typename T, typename V>
class HashMap {
private:
    KeyLinkedList<T, V>* container[3];

    int hash(T key) {
        int hashValue = -1;
        int tmp = 0;

        for (char c : key) {
            tmp += (int)c;
        }
        hashValue = tmp % 3;

        return hashValue;
    }

    Node<T, V>* _findNodeByKey(T key, Node<T, V>* nowCursor) {
        Node<T, V>* cursor = nowCursor;
        while (cursor != nullptr) {
            if (cursor->key == key) {
                break;
            }
            cursor = cursor->next;
        }
        return cursor;
    }

public:
    HashMap() {
        for (int i = 0; i < 3; i++) {
            container[i] = new KeyLinkedList<T, V>();
        }
    }

    void put(T key, V value) {
        int hashcode = this->hash(key);

        Node<T, V>* cursor = this->container[hashcode]->head;
        cursor = this->_findNodeByKey(key, cursor);

        // 해쉬코드 컨테이너에 키가 있다면
        if (cursor != nullptr) {
            // 덮어쓰기
            cursor->value = value;
        }
        // 없다면
        else {
            // 컨테이너에 노드추가
            this->container[hashcode]->add(key, value);
        }
    }

    V get(T key) {
        V value;
        int hashcode = this->hash(key);

        Node<T, V>* cursor = this->container[hashcode]->head;
        cursor = this->_findNodeByKey(key, cursor);

        // 해쉬코드 컨테이너에 키가 있다면
        if (cursor != nullptr) {
            // 값 리턴
            return cursor->value;
        }
        // 없다면
        else {
            cout << "키를 찾을 수 없습니다." << endl;
            return -1;
        }
    }

    void remove(T key) {
        int hashcode = this->hash(key);

        Node<T, V>* head = this->container[hashcode]->head;
        Node<T, V>* cursor = this->_findNodeByKey(key, head);

        if (cursor == nullptr) {
            cout << "키를 찾을 수 없습니다." << endl;
            return;
        }
        else if (head == cursor) {
            head = head->next;
            this->container[hashcode]->head = head;
        }
        else {
            while (head->next != cursor) {
                head = head->next;
            }

            cout << head->key << endl;

            if (head->next->next == nullptr) {
                head->next = nullptr;
            }
            else {
                head->next->next = head->next;
            }

            delete cursor;
        }
    }

    ~HashMap() {
        delete[] this->container;
    }
};