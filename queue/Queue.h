//
// Created by Nour-aldeen on 4/20/2024.
//

#ifndef DATA_STRUCUTRES_QUEUE_H
#define DATA_STRUCUTRES_QUEUE_H

template <class T>
class Queue {
private:
    struct Node {
        T value;
        Node* next;

        Node(const T& val) {
            value = val;
            next = nullptr;
        }
    };
    Node* head, *tail;
    int size;
public:
    Queue() : head(nullptr), tail(nullptr), size(0) {};
    void enqueue(const T& element);
    const T dequeue();    //returns the first element and removes it
    const T first();      //returns the first element
    bool isEmpty();
    int queueSize();
    void clear();
    void print();
};


#endif //DATA_STRUCUTRES_QUEUE_H
