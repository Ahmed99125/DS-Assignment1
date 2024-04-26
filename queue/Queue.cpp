//
// Created by Nour-aldeen on 4/20/2024.
//

#include "Queue.h"
#include <iostream>
using namespace std;



template <class T>
void Queue<T>::enqueue(const T& element){
    Node* newNode =  new Node(element);
    if(head == nullptr){
        head = newNode;
        tail = head;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template <class T>
bool Queue<T>::isEmpty() {
    return size == 0;
}

template <class T>
const T Queue<T>::dequeue() {
    if(size == 0){
        throw out_of_range("Queue is Empty!\n");
    }
    else {
        T val = head->value;
        Node* tmp = head;
        head = head->next;
        delete tmp;
        size--;
        return val;
    }
}

template <class T>
const T Queue<T>::first() {
    if(Queue<T>::isEmpty()) {
        throw out_of_range("Queue is Empty!\n");
    }
    else {
        return head->value;
    }
}

template<class T>
int Queue<T>::queueSize() {
    return size;
}

template<class T>
void Queue<T>::clear() {
    size = 0;
    Node* tmp = head->next;
    while (tmp != nullptr && tmp != tail) {
        Node* target = tmp;
        tmp = tmp->next;
        delete target;
    }
    head = nullptr;
    tail = nullptr;
}

template<class T>
void Queue<T>::print() {
    Node* temp = head;
    while (temp != nullptr){
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << '\n';
}

int main() {
    Queue<int> q;
    q.enqueue(32);
    q.enqueue(22);
    cout << q.dequeue() << endl;
    cout << q.first() << endl;
    q.clear();
    q.enqueue(44);
    q.enqueue(55);
    q.print();
}


