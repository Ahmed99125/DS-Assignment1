//
// Created by asus on 4/26/2024.
//

#ifndef LINKED_LIST_DOUBLELL_H
#define LINKED_LIST_DOUBLELL_H
#include <bits/stdc++.h>
#include "List.hpp"

using namespace std;

template<class T>

class doublell : List<T>{
private:
    struct Node {
        T data;
        Node* next{};
        Node* prev{};
        Node(){};
        Node(T elm): data(elm) , next(nullptr) , prev(nullptr){};
        void set(Node* next, Node* prev) {
            this->next = next;
            this->prev = prev;
        }
        ~Node (){};
    };
    Node* head, *tail;
    int length;

public:
    doublell(T ele): head(nullptr) , tail(nullptr){};
    doublell(){};
    doublell (const doublell&) = delete ; // Prevent copying of doublell objects
    doublell &operator=(const doublell &another) = delete;// Prevent copying of LinkedList objects and both of them give compailation error

    // ------- helper function to linke two nodes --------------------
    void link(Node * node1 , Node* node2){
        if ( node1)
            node1->next = node2;
        if ( node2)
            node2->prev = node1;
    }

    // ------- insert at the end ----------
    void insertAtTail( T element){
        Node* newNode = new Node(element);
        if( length == 0 ){
            head = tail =  newNode;
        }
        else {
            link(tail , newNode);
            tail = newNode;
            tail->next = nullptr;
        }
        length++;

    }

    // ----------- insert at the beginning -------------
    void insertAtHead( T element){
        Node* newNode = new Node(element);
        if( length == 0 ){
            head = tail =  newNode;
        }
        else {
            link(newNode , head);
            head = newNode;
            tail->prev = nullptr;
        }
        length++;

    }


    // ------ helper fun Get the nth Node --------
    Node* get_nth_Node(int n){
        int cont = 0 ;
        assert(n <= length && n>0);
        for ( Node *curr = head ; curr ; curr = curr->next){
            cont ++ ;
            if ( cont == n){
                return curr;
            }
        }

    }


    //------ Insert At specipic pos --------
    void InsertAt ( T element , int indx ){
        Node* newNode = new Node(element);
        if( indx == 1 ){
            insertAtHead(element);
        }
        else if (indx == length){
            insertAtTail(element);
        }
        else {
            Node* curr = get_nth_Node(indx);
            Node* before = curr->prev;
            before->next = newNode;
            newNode->next = curr;
            newNode->prev = before;
            curr->prev = newNode;
        }
        length++;
    }

    // ------ Remove At Tail ---------
    void removeAtTail(){
        assert(length);
        if ( length == 1 ){
            delete tail;
            head = tail = nullptr;
        }
        else {
            Node* before = tail->prev;
            delete tail;
            tail = before;
            if( tail)
                tail->next = nullptr;
        }
        length--;
    }

    // ----- Remove At Head -----------
    void removeAtHead(){
        assert(length);
        if ( length == 1 ){
            delete head;
            head = tail = nullptr;
        }
        else {
            Node* next = head->next;
            delete head;
            head = next;
        }
        length--;
    }


    // --------- Remove At specific position --------
    void removeAt(int indx){
        if ( indx == 1 ){
            removeAtHead();
        }
        else if ( indx == length){
            removeAtTail();
        }
        else {
            Node *curr = get_nth_Node(indx);
            Node* before = curr->prev;
            Node* after = curr->next;
            delete curr;
            before->next = after;
            after->prev = before;
        }
        length--;
    }


    // ------- Swap two nodes --------
    void swap(int indx1, int indx2) {
        if (indx1 == indx2) {
            return;
        }
        Node *node1 = head, *node2 = head;
        Node *prev1 = nullptr, *prev2 = nullptr;

        int index = 1;
        while (node1 != nullptr && index != indx1) {
            prev1 = node1;
            node1 = node1->next;
            index++;
        }

        index = 1;
        while (node2 != nullptr && index != indx2) {
            prev2 = node2;
            node2 = node2->next;
            index++;
        }

        if (node1 == nullptr || node2 == nullptr) {
            cout << "One or both nodes not found." << endl;
            return;
        }
        if (prev1 != nullptr) {
            prev1->next = node2;
        } else {
            head = node2;
        }
        if (prev2 != nullptr) {
            prev2->next = node1;
        } else {
            head = node1;
        }
        if (node1->next != nullptr) {
            node1->next->prev = node2;
        }
        if (node2->next != nullptr) {
            node2->next->prev = node1;
        }

        Node *temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;
        temp = node1->prev;
        node1->prev = node2->prev;
        node2->prev = temp;
    }



// -------- Retreive An element at spcific indx ---------
    T retrieveAt( int indx){
        assert(indx <= length && indx > 0 );
        Node* curr = get_nth_Node(indx);
        return curr->data;
    }


    // ------- Replacee elemnt --------
    void replaceAt ( T element , int indx){
        assert(indx >0 && indx<=length);
        Node *curr = get_nth_Node(indx);
        curr->data = element;
    }


    bool isExist(T element ){
        for ( Node *curr = head ; curr ; curr = curr->next){
            if ( curr->data == element){
                return true;
            }
        }
        return false;
    }


    // ------- is item at pos equal val -------
    bool isItemAtEqual(T element , int indx){
        assert( indx > 0 &&  indx <= length );
        Node* curr = get_nth_Node(indx);
        if ( curr->data == element){
            return true;
        }
        return false;
    }


    // ------ check if the list is empty or not -----------
    bool isEmpty(){
        if ( length == 0 )
            return true;
        else return false;
    }


    int linkedListSize(){
        return length;
    }


// ------ Clear the linkedList -----------
    void clear(){
        Node *curr = head;
        while ( curr != nullptr){
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
        length = 0;
        cout << length  << endl;
    }


    // ------------- print fun ------------
    void print(){
        assert(length);
        int cont = 0 ;
        for ( Node* curr = head ; curr ; curr = curr->next){
            cont ++ ;
            cout << curr->data << ' ';
            if (cont == length)
                break;
        }
        cout << endl;
    }
};

#endif //LINKED_LIST_DOUBLELL_H
