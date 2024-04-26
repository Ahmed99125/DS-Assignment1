//
// Created by asus on 4/26/2024.
//

#ifndef LINKED_LIST_CIRCULARLINKEDLIST_H
#define LINKED_LIST_CIRCULARLINKEDLIST_H
#include <iostream>
#include "List.hpp"
using namespace std;

template <class T>
class CircularLinkedList : List<T>{
private:
    struct Node {
        T value;
        Node* next;
        Node(const T& val){
            this->value = val;
        }
    };
    Node* head, * tail;
    int length;
public:
    CircularLinkedList() : head(nullptr), tail(nullptr), length(0) {};
    void insertAtHead(T element) {
        Node* newNode = new Node(element);
        newNode->next = head;
        head = newNode;
        if(tail == nullptr) {   //that means that this is the first element inserted
            tail = head;
            newNode->next = head;    //circular LL, so the next of the last element will be the first element
        }

        length++;
    }

    void insertAtTail(T element) {
        Node* newNode = new Node(element);
        if(tail != nullptr)     //not the first element to be inserted
            tail->next = newNode;
        tail = newNode;
        if(head == nullptr){    //first element to be inserted
            head = tail;
            newNode->next = newNode;
        }
        else
            newNode->next = head;

        length++;
    }

    void InsertAt(T element, int indx) {
        if(indx == 0)
            insertAtHead(element);
        else {
            Node *temp = head;
            if (head == nullptr)
                throw out_of_range("out of boundary!");
            for (int i = 1; i < indx && temp != nullptr; ++i) {
                temp = temp->next;
            }
            Node *newNode = new Node(element);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
        }
    }

    void removeAtHead() {
        if(head != nullptr) {
            Node* tmp = head;
            head = tmp->next;
            delete tmp;
        } else
            throw out_of_range("list is empty!!\n");
        length--;
    }

    void removeAtTail() {
        if(head != nullptr){
            Node* tmp = head;
            while (tmp->next != tail) {
                tmp = tmp->next;
            }
            Node* target = tail;
            tail = tmp;
            tail->next = head;
            delete target;
        }
        else
            throw out_of_range("list is empty!!\n");
        length--;
    }

    void removeAt(int indx) {
        if (indx == 0)
            removeAtHead();
        if(indx == length - 1)
            removeAtTail();
        Node* tmp = head;
        for(int i=1; i<indx; ++i) {
            tmp = tmp->next;
        }
        Node* target = tmp->next;
        tmp->next = tmp->next->next;
        delete target;
        length--;
    }

    T retrieveAt(int indx) {
        Node* tmp = head;
        for (int i = 0; i < indx; ++i) {
            tmp = tmp->next;
        }
        return tmp->value;
    }

    void replaceAt(T element, int indx) {
        Node* tmp = head;
        for (int i = 0; i < indx; ++i) {
            tmp = tmp->next;
        }
        tmp->value = element;
    }

    bool isExist(T element) {
        Node* tmp = head;
        while (tmp != tail && tmp->value != element) {
            tmp = tmp->next;
        }
        if(tmp->value != element)
            return false;
        else
            return true;
    }

    bool isItemAtEqual(T element, int indx) {
        Node* tmp = head;
        for (int i = 0; i < indx; ++i) {
            tmp = tmp->next;
        }
        return tmp->value == element;
    }

    void swap(int indx1, int indx2) {
        Node* t1 = head, *beforeT1 = nullptr;
        for (int i = 0; i < indx1; ++i) {
            t1 = t1->next;
            if(beforeT1 == nullptr)
                beforeT1 = head;
            else
                beforeT1 = beforeT1->next;
        }

        Node* t2 = head, *beforeT2 = nullptr;
        for (int i = 0; i < indx2; ++i) {
            t2 = t2->next;
            if(beforeT2 == nullptr)
                beforeT2 = head;
            else
                beforeT2 = beforeT2->next;
        }
        if(t1 == beforeT2) {    //consecutive nodes
            t1->next = t2->next;
            t2->next = t1;
            if(beforeT1 == nullptr)     //head is being swapped
                head = t2;
            else
                beforeT1->next = t2;
        }
        else {
            Node *tmp = t1->next;
            t1->next = t2->next;
            t2->next = tmp;

            if (beforeT1 != nullptr)
                beforeT1->next = t2;
            if (beforeT2 != nullptr)
                beforeT2->next = t1;
        }
    }

    bool isEmpty() {
        return length == 0;
    }

    int linkedListSize() {
        return length;
    }

    void clear() {
        Node* tmp = head;
        while (tmp != tail){
            Node* tmp2 = tmp;
            tmp = tmp->next;
            delete tmp2;
        }
        head = nullptr, tail = nullptr;
        length = 0;
    }

    void print() {
        if(length == 0)
            throw out_of_range("list is empty");
        Node* tmp = head;
        for (int i = 0; i < length; ++i) {
            cout << tmp->value << " ";
            tmp = tmp->next;
        }
        cout << '\n';
    }

};

#endif //LINKED_LIST_CIRCULARLINKEDLIST_H
