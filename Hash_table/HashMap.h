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

        // �ؽ��ڵ� �����̳ʿ� Ű�� �ִٸ�
        if (cursor != nullptr) {
            // �����
            cursor->value = value;
        }
        // ���ٸ�
        else {
            // �����̳ʿ� ����߰�
            this->container[hashcode]->add(key, value);
        }
    }

    V get(T key) {
        V value;
        int hashcode = this->hash(key);

        Node<T, V>* cursor = this->container[hashcode]->head;
        cursor = this->_findNodeByKey(key, cursor);

        // �ؽ��ڵ� �����̳ʿ� Ű�� �ִٸ�
        if (cursor != nullptr) {
            // �� ����
            return cursor->value;
        }
        // ���ٸ�
        else {
            cout << "Ű�� ã�� �� �����ϴ�." << endl;
            return -1;
        }
    }

    void remove(T key) {
        int hashcode = this->hash(key);

        Node<T, V>* head = this->container[hashcode]->head;
        Node<T, V>* cursor = this->_findNodeByKey(key, head);

        if (cursor == nullptr) {
            cout << "Ű�� ã�� �� �����ϴ�." << endl;
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