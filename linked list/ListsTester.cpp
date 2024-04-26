//
// Created by Nour-aldeen on 4/26/2024.
//
#include "CircularLinkedList.h"
#include "doublell.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Testing Circular Linked List:\n\n";
    CircularLinkedList<int> l1;
    cout << "Insert At Head  : ";
    l1.insertAtHead(1);
    l1.insertAtHead(2);
    l1.insertAtHead(3);
    l1.print();
    cout << endl << "------------------------------------------------------------\n";


    CircularLinkedList<int>l2;
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
    if ( l2.isItemAtEqual(100, 2 ))
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

//    cout <<"Clear the linked list , trying to print it after clear function : ";
//    l2.clear();
//    l2.print();

    cout << endl << "------------------------------------------------------------\n";

    cout << endl << "Testing Double linked list: \n\n";

    cout << "insert At the end of the list 1 2 3  : ";
    doublell<int> l3;
    l3.insertAtTail(1);
    l3.insertAtTail(2);
    l3.insertAtTail(3);
    l3.print();
    cout << "-----------------------------------------------------------------------------\n";

    cout << "insert At the beginning of the prev ex 4 5 : ";
    l3.insertAtHead(4);
    l3.insertAtHead(5);
    l3.print();
    cout << "-----------------------------------------------------------------------------\n";

    cout << "Insert at a spcific pos 3 insert 10 :  ";
    l3.InsertAt(10,3);
    l3.print();
    cout << "-----------------------------------------------------------------------------\n";


    cout <<"Delete the last element in the prev ex : ";
    l3.removeAtTail();
    l3.print();
    cout << "-----------------------------------------------------------------------------\n";

    cout <<"Delete the first element in the prev ex : ";
    l3.removeAtHead();
    l3.print();
    cout << "-----------------------------------------------------------------------------\n";

    cout <<"Delet the element at indx 3 int the prev ex: ";
    l3.removeAt(3);
    l3.print();
    cout << "-----------------------------------------------------------------------------\n";

    cout << "retrive the element at indx 3 from the prev ex : ";
    cout << l3.retrieveAt(3);
    cout << endl << "------------------------------------------------------------\n";


    cout << "Replace element at pos 2  with 100 : \n";
    l3.print();
    cout << endl;
    l3.replaceAt(100, 2 );
    l3.print();
    cout << endl << "------------------------------------------------------------\n";

    cout << "check if the element is already in the doublelinked list 100 : ";
    if ( l3.isExist(100)){
        cout << "yes\n";
    }
    else {
        cout << "NO \n";
    }
    cout << endl << "------------------------------------------------------------\n";

    cout << "check if the element at specific indx equal a spcific value  100 at 2  : ";
    if ( l3.isItemAtEqual(100, 2 ))
        cout << "YES\n";
    else cout << "NO\n";
    cout << endl << "------------------------------------------------------------\n";

    cout << "swap two nodes with each other at indx 1 and 2 : \n";
    l3.print();
    cout << endl;
    l3.swap(1,2);
    l3.print();
    cout << endl << "------------------------------------------------------------\n";

    cout << "check if the list is empty or not : ";
    if ( l3.isEmpty()){
        cout << "the linkedList is empty \n";
    }
    else {
        cout << "The linkedList NOt empty\n";
    }
    cout << endl << "------------------------------------------------------------\n";

    cout <<"The size of the linked list :";
    cout << l3.linkedListSize()<<endl;
    cout << endl << "------------------------------------------------------------\n";

//    cout <<"Clear the linked list , trying to print it after clear function : ";
//    l3.clear();
//    l3.print();
    cout << endl << "------------------------------------------------------------\n";

    cout << "Testing Single Linked List: \n\n";

    Linkedlist<int> l4;
    cout << "Insert At Head  : ";
    l4.insertAtHead(1);
    l4.insertAtHead(2);
    l4.insertAtHead(3);
    l4.print();
    cout << endl << "------------------------------------------------------------\n";


    Linkedlist<int>l5;
    cout << "Insert At Tail  : ";
    l5.insertAtTail(1);
    l5.insertAtTail(2);
    l5.insertAtTail(3);
    l5.print();
    cout << endl << "------------------------------------------------------------\n";


    cout << "Insert At specific position 2 put 5 in the prev ex  :  ";
    l5.InsertAt(5,2);
    l5.print();
    cout << endl << "------------------------------------------------------------\n";


    cout << "deleting  the head from the prev ex  :  ";
    l5.removeAtHead();
    l5.print();
    cout << endl << "------------------------------------------------------------\n";


    cout << "deleting the tail from the prev ex  :  ";
    l5.removeAtTail();
    l5.print();
    cout << endl << "------------------------------------------------------------\n";


    l5.insertAtHead(1);
    l5.insertAtHead(2);
    l5.insertAtHead(10);
    cout << "deleting an elemnt at indx 3 : \n";
    l5.print();
    cout << endl;
    l5.removeAt(3);
    l5.print();
    cout << endl << "------------------------------------------------------------\n";


    cout << "retrive the element at indx 3 from the prev ex : ";
    cout << l5.retrieveAt(3);
    cout << endl << "------------------------------------------------------------\n";


    cout << "Replace element at pos 2  with 100 : \n";
    l5.print();
    cout << endl;
    l5.replaceAt(100, 2 );
    l5.print();
    cout << endl << "------------------------------------------------------------\n";

    cout << "check if the element is already in the linked list 100 : ";
    if ( l5.isExist(100)){
        cout << "yes\n";
    }
    else {
        cout << "NO \n";
    }
    cout << endl << "------------------------------------------------------------\n";

    cout << "check if the element at specific indx equal a spcific value  100 at 2  : ";
    if ( l5.isItemAtEqual(100, 2 ))
        cout << "YES\n";
    else cout << "NO\n";
    cout << endl << "------------------------------------------------------------\n";

    cout << "swap two nodes with each other at indx 1 and 2 : \n";
    l5.print();
    cout << endl;
    l5.swap(1,2);
    l5.print();
    cout << endl << "------------------------------------------------------------\n";

    cout << "check if the list is empty or not : ";
    if ( l5.isEmpty()){
        cout << "the linkedList is empty \n";
    }
    else {
        cout << "The linkedList NOt empty\n";
    }
    cout << endl << "------------------------------------------------------------\n";

    cout <<"The size of the linked list :";
    cout << l5.linkedListSize()<<endl;
    cout << endl << "------------------------------------------------------------\n";

//    cout <<"Clear the linked list , trying to print it after clear function : ";
//    l5.clear();
//    l5.print();


}