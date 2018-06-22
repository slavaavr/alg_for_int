//
// Created by slava on 19-Jun-18.
//

#include <c++/iostream>

template<typename T>
class DoubleCyclicLinkedList {

private:
    struct Node {
        T data;
        Node *next;
        Node *prev;
    };

    Node *head;
    int length;

public:
    DoubleCyclicLinkedList() {
        head = nullptr;
        length = 0;
    }

    ~DoubleCyclicLinkedList() {
        Node *temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;
        }
    }

    DoubleCyclicLinkedList *add(T data) {
        Node *tail;
        if (head == nullptr) {
            head = new Node;
            head->data = data;
            head->next = head;
            head->prev = head;
        } else {
            tail = new Node;
            tail->data = data;
            tail->next = head;
            tail->prev = head->prev;
            head->prev->next = tail;
            head->prev = tail;
        }
        length++;
        return this;
    }

    void remove(T data) {
        if (head != nullptr) {
            Node *temp = head->next;
            while (temp != head) {
                if (temp->data == data) {
                    length--;
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    auto t = temp->next;
                    delete temp;
                    temp = t;
                } else {
                    temp = temp->next;
                }
            }
        }
    }

    T getByIndex(int index) {
        if (head == nullptr) {
            throw std::runtime_error("There are no items in the list");
        } else if (index < 0 || index > length - 1) {
            throw std::runtime_error("Index out of bound");
        } else {
            Node *temp = head;
            while (index > 0) {
                temp = temp->next;
                index--;
            }
            return temp->data;
        }
    }

    T getHead() {
        if (head != nullptr) {
            return head->data;
        } else {
            throw std::runtime_error("There are no items in the list");
        }
    }

    T getTail() {
        if (head != nullptr) {
            return head->prev->data;
        } else {
            throw std::runtime_error("There are no items in the list");
        }
    }

    int getLength() {
        return length;
    }

    void print() {
        if (head != nullptr) {
            Node *temp = head;
            do {
                std::cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
            std::cout << std::endl;
        }
    }
};