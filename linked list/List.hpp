#ifndef LIST_H
#define LIST_H

#include<bits/stdc++.h>

using namespace std;

template<class T>
class List {

public:

    // ------- insert At Tail ----------
    virtual void insertAtHead( T element)

    // ------- insert At Tail ----------
    virtual void insertAtTail ( T element) = 0;

    //------ Insert At specipic pos --------
    virtual void InsertAt ( T element , int indx ) = 0 ;

    // ------ Remove At Head ----------
    virtual void removeAtHead() = 0

    // ------ Remove At Tail ---------
    virtual void removeAtTail() = 0;

    // ------- Remove At specific pos ---------
    virtual void removeAt ( int indx) = 0;

    // -------- Retreive An element at spcific indx ---------
    virtual T retrieveAt( int indx) = 0;

    // ------- Replacee elemnt ------------
    virtual void replaceAt ( T element , int indx) = 0; 

    //  ----------- isExist ------------------
    virtual bool isExist(T element ) = 0;

    // ------- is item at pos equal val -------
    virtual bool isItemnAtEqual(T element , int indx) = 0

    // ------- Swap two nodes --------
    virtual void swap(int indx1, int indx2) = 0;

    // ------ check if the list is empty or not -----------
    virtual bool isEmpty() = 0 
        
    // ----------  Get linkedlist size
    virtual int linkedListSize() = 0;

    // ------Clear the linkedList -----------
    virtual void clear()

    // ------- print fun -------
    virtual void print () = 0;
    
};



#endif
