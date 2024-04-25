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
        if(indx == length-1)
            insertAtTail(element);

        Node* temp = head;
        if(head == nullptr)
            throw out_of_range("out of boundary!");
        for (int i = 1; i < indx && temp != nullptr; ++i) {
            temp = temp->next;
        }
        Node* newNode = new Node(element);
        newNode->next = temp->next;
        temp->next = newNode;
        length++;
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
        if(head == nullptr)
            throw out_of_range("list is empty");
        Node* tmp = head;
        for (int i = 0; i < length; ++i) {
            cout << tmp->value << " ";
            tmp = tmp->next;
        }
        cout << '\n';
    }

};

int main(){

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

    cout <<"Clear the linked list , trying to print it after clear function : ";
    l2.clear();
    l2.print();
}
