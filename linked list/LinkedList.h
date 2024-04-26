//
// Created by asus on 4/26/2024.
//

#ifndef LINKED_LIST_LINKEDLIST_H
#define LINKED_LIST_LINKEDLIST_H
#include "List.hpp"
#include <bits/stdc++.h>

using namespace std;


template<class T>
class Linkedlist : List<T>  {
private:
    struct Node
    {
        T data;
        Node* next;
        Node(T el ): data(el) , next(nullptr) {};
        Node(){};
        ~Node(){
            // cout << "Destroy Value : " << data << " at address : " << this << endl;
        }
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    int length = 0 ;
public:


    Linkedlist(){};
    Linkedlist (const Linkedlist&) = delete ; // Prevent copying of Linkedlist objects
    Linkedlist &operator=(const Linkedlist &another) = delete;// Prevent copying of LinkedList objects and both of them give compailation error
    // ------ insert At head -----
    void insertAtHead( T element){
        Node* newNode = new Node ( element);
        if (!head && !tail){
            head = tail = newNode;
            tail->next = nullptr;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    // ------- insert At Tail ----------
    void insertAtTail ( T element){
        Node* newNode = new Node (element);
        if ( !head && !tail){
            head = tail = newNode;
            tail->next = nullptr;
        }
        else {
            tail->next = newNode;
            tail = newNode;
            tail->next = nullptr;
        }
        length++;
    }


    //------ Insert At specipic pos --------
    void InsertAt ( T element , int indx ){
        Node* newNode = new Node (element);
        if(indx == 1 ){
            insertAtHead(element);
        }
        else if ( indx == length){
            insertAtTail(element);
        }
        else {
            length++;
            Node* prev;
            int position = 0;
            for (Node *curr = head ;  curr ; curr = curr->next  ){
                position ++;
                if ( position == 1 ){
                    prev = curr;
                    continue;
                }
                if ( position == indx ){
                    prev->next = newNode;
                    newNode->next = curr;
                    return;
                }
                prev = curr;
            }

        }

    }


    // ------ Remove At Head ----------
    void removeAtHead(){
        assert(length);
        length--;
        Node* next_node;
        next_node = head->next;
        if ( !next_node){ // if next node == null it means that there is no elemnts left
            tail = nullptr;
        }
        delete head;
        head = next_node;
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


    // ------ Remove At Tail ---------
    void removeAtTail(){
        assert(length);
        Node* before_tail = get_nth_Node(length-1);
        delete tail;
        tail = before_tail;
        tail->next = nullptr;
        length--;
    }


    // ------- Remove At specific pos ---------
    void removeAt ( int indx){
        assert(indx > 0 && indx <= length);
        if ( indx == 1 ){
            removeAtHead();
        }
        else if ( indx == length){
            removeAtTail();
        }
        else {
            Node* before_node = get_nth_Node(indx-1);
            Node* toBeDeleted = before_node->next;
            Node* after_node = before_node->next->next;
            delete toBeDeleted;
            length--;
            before_node->next = after_node; // we can say = before->next->next before deleting the node
        }
    }


    // -------- Retreive An element at spcific indx ---------
    T retrieveAt( int indx){
        assert(indx <= length && indx > 0 );
        int cont = 0 ;
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


    // ------- Swap two nodes --------
    void swap(int indx1, int indx2) {
        if (indx1 == indx2) {
            return;
        }

        Node *prev1 = nullptr, *node1 = head;
        Node *prev2 = nullptr, *node2 = head;

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
        Node *temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;
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


// ------Clear the linkedList -----------
    void clear(){
        Node *curr = head;
        while ( curr != nullptr){
            Node *next = curr->next;
            delete curr;
            curr = next;
        }
        length = 0;
    }

    // ------- print fun -------
    void print (){
//        assert(length);
        if(length == 0)
            throw out_of_range("list is empty");
        Node *cur = head;
        for (; cur ; cur = cur->next){
            cout << cur->data << ' ';
        }
    }

};


#endif //LINKED_LIST_LINKEDLIST_H
