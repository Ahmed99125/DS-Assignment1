
#include "List.hpp"
#include <bits/stdc++.h>

using namespace std;

template<class T>
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

template<class T>
class Linkedlist : list<T>  {

public:

    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int length = 0 ;
    
    Linkedlist(){};
    Linkedlist (const Linkedlist&) = delete ; // Prevent copying of Linkedlist objects
    Linkedlist &operator=(const Linkedlist &another) = delete;// Prevent copying of LinkedList objects and both of them give compailation error 
    // ------ insert At head -----
    void insertAtHead( T element){
        Node<T>* newNode = new Node<T> ( element);
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
        Node<T>* newNode = new Node<T> (element);
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
        Node<T>* newNode = new Node<T> (element);
        if(indx == 1 ){
            insertAtHead(element);
        }
        else if ( indx == length){
            insertAtTail(element);
        }
        else {
            length++;
            Node<T>* prev;
            int position = 0;
            for (Node<T> *curr = head ;  curr ; curr = curr->next  ){
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
        Node<T>* next_node;
        next_node = head->next;
        if ( !next_node){ // if next node == null it means that there is no elemnts left
            tail = nullptr;
        }
        delete head;
        head = next_node;
    }


    // ------ helper fun Get the nth Node --------
    Node<T>* get_nth_Node(int n){
        int cont = 0 ; 
        assert(n <= length && n>0);
        for ( Node<T> *curr = head ; curr ; curr = curr->next){
            cont ++ ; 
            if ( cont == n){
                return curr;
            }
        }

    }
    

    // ------ Remove At Tail ---------
    void removeAtTail(){
        assert(length);
        Node<T>* before_tail = get_nth_Node(length-1);
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
            Node<T>*before_node = get_nth_Node(indx-1);
            Node<T>* toBeDeleted = before_node->next;
            Node<T>* after_node = before_node->next->next;
            delete toBeDeleted;
            length--;
            before_node->next = after_node; // we can say = before->next->next before deleting the node
        }
    }


    // -------- Retreive An element at spcific indx ---------
    T retrieveAt( int indx){
        assert(indx <= length && indx > 0 );
        int cont = 0 ;
        Node<T>* curr = get_nth_Node(indx);
        return curr->data;
    }


    // ------- Replacee elemnt --------
    void replaceAt ( T element , int indx){
        assert(indx >0 && indx<=length);
        Node<T> *curr = get_nth_Node(indx);
        curr->data = element;
    }


    bool isExist(T element ){
        for ( Node<T> *curr = head ; curr ; curr = curr->next){
            if ( curr->data == element){
                return true;
            }
        }
        return false;
    }


    // ------- is item at pos equal val -------
    bool isItemnAtEqual(T element , int indx){
        assert( indx > 0 &&  indx <= length );
        Node<T>* curr = get_nth_Node(indx);
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
        
        Node<T> *prev1 = nullptr, *node1 = head;
        Node<T> *prev2 = nullptr, *node2 = head;
        
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
        Node<T> *temp = node1->next;
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
        Node<T> *curr = head;
        while ( curr != nullptr){
            Node<T> *next = curr->next;
            delete curr;
            curr = next;
        }
        length = 0;
    }

    // ------- print fun -------
    void print (){        
        assert(length);
        Node<T> *cur = head;
        for (; cur ; cur = cur->next){
            cout << cur->data << ' ';
        }
    }

};






int main(){

    Linkedlist<int> l1;
    cout << "Insert At Head  : ";
    l1.insertAtHead(1);
    l1.insertAtHead(2);
    l1.insertAtHead(3);
    l1.print();
    cout << endl << "------------------------------------------------------------\n";
    

    Linkedlist<int>l2;
    cout << "Insert At Tail  : ";
    l2.insertAtTail(1);
    l2.insertAtTail(2);
    l2.insertAtTail(3);
    l2.print();
    cout << endl << "------------------------------------------------------------\n";


    cout << "Insert At specific position 2 put 5 in the prev ex  :  ";
    l2.InsertAt(5,2);
    l2.print();
    cout << endl << "------------------------------------------------------------\n";


    cout << "deleting  the head from the prev ex  :  ";
    l2.removeAtHead();
    l2.print();
    cout << endl << "------------------------------------------------------------\n";


    cout << "deleting the tail from the prev ex  :  ";
    l2.removeAtTail();
    l2.print();
    cout << endl << "------------------------------------------------------------\n";


    l2.insertAtHead(1);
    l2.insertAtHead(2);
    l2.insertAtHead(10);
    cout << "deleting an elemnt at indx 3 : \n";
    l2.print();
    cout << endl;
    l2.removeAt(3);
    l2.print();
    cout << endl << "------------------------------------------------------------\n";


    cout << "retrive the element at indx 3 from the prev ex : ";
    cout << l2.retrieveAt(3);
    cout << endl << "------------------------------------------------------------\n";


    cout << "Replace element at pos 2  with 100 : \n";
    l2.print();
    cout << endl;
    l2.replaceAt(100, 2 );
    l2.print();
    cout << endl << "------------------------------------------------------------\n";

    cout << "check if the element is already in the linked list 100 : ";
    if ( l2.isExist(100)){
        cout << "yes\n";
    }
    else {
        cout << "NO \n";
    }
    cout << endl << "------------------------------------------------------------\n";

    cout << "check if the element at specific indx equal a spcific value  100 at 2  : ";
    if ( l2.isItemnAtEqual(100, 2 ))
        cout << "YES\n";
    else cout << "NO\n";
    cout << endl << "------------------------------------------------------------\n";

    cout << "swap two nodes with each other at indx 1 and 2 : \n";
    l2.print();
    cout << endl;
    l2.swap(1,2);
    l2.print();
    cout << endl << "------------------------------------------------------------\n";
    
    cout << "check if the list is empty or not : ";
    if ( l2.isEmpty()){
        cout << "the linkedList is empty \n";
    }
    else {
        cout << "The linkedList NOt empty\n";
    }
    cout << endl << "------------------------------------------------------------\n";

    cout <<"The size of the linked list :";
    cout << l2.linkedListSize()<<endl;
    cout << endl << "------------------------------------------------------------\n";

    cout <<"Clear the linked list , trying to print it after clear function : ";
    l2.clear();
    l2.print();    
}
