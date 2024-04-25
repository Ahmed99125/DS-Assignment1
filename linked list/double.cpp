#include <bits/stdc++.h>

using namespace std;

template<class T>
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


template<class T>

class doublell{
public:
    Node<T>* head{};
    Node<T>* tail{};
    int length = 0;
    doublell(T ele): head(nullptr) , tail(nullptr){};
    doublell(){};
    doublell (const doublell&) = delete ; // Prevent copying of doublell objects
    doublell &operator=(const doublell &another) = delete;// Prevent copying of LinkedList objects and both of them give compailation error 

    // ------- helper function to linke two nodes --------------------
    void link(Node<T> * node1 , Node<T> * node2){
		if ( node1)
			node1->next = node2;	
		if ( node2)
			node2->prev = node1;
	}

    // ------- insert at the end ----------
    void insertAtTail( T element){
        Node<T>* newNode = new Node<T>(element);
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
        Node<T>* newNode = new Node<T>(element);
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
    

    //------ Insert At specipic pos --------
    void InsertAt ( T element , int indx ){
        Node<T>* newNode = new Node<T>(element);
        if( indx == 1 ){
            insertAtHead(element);
        }
        else if (indx == length){
            insertAtTail(element);
        }
        else {
            Node<T>* curr = get_nth_Node(indx);
            Node<T>* before = curr->prev;
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
            Node<T>* before = tail->prev;
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
            Node<T>* next = head->next;
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
            Node<T> *curr = get_nth_Node(indx);
            Node<T>*before = curr->prev;
            Node<T>*after = curr->next;
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
    Node<T> *node1 = head, *node2 = head;
    Node<T> *prev1 = nullptr, *prev2 = nullptr;

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

    Node<T> *temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;
    temp = node1->prev;
    node1->prev = node2->prev;
    node2->prev = temp;
}

    

// -------- Retreive An element at spcific indx ---------
    T retrieveAt( int indx){
        assert(indx <= length && indx > 0 );
        Node<T>* curr = get_nth_Node(indx);
        return curr->data;
    }


    // ------- Replacee elemnt --------
    void replaceAt ( T elemnt , int indx){
        assert(indx >0 && indx<=length);
        Node<T> *curr = get_nth_Node(indx);
        curr->data = elemnt;
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
        Node<T> *curr = head;
        while ( curr != nullptr){
            Node<T> *next = curr->next;
            delete curr;
            curr = next;
        }
        length = 0;
        cout << length  << endl;
    }


    // ------------- print fun ------------
    void print(){
        cout << "a7a\n";
        assert(length);
        int cont = 0 ;
        for ( Node<T>* curr = head ; curr ; curr = curr->next){
            cont ++ ;
            cout << curr->data << ' ';
            if (cont == length)
                break;
        }
        cout << endl;
    }
};



int main (){
    cout << "insert At the end of the list 1 2 3  : ";
    doublell<int> l2;
    l2.insertAtTail(1);
    l2.insertAtTail(2);
    l2.insertAtTail(3);
    l2.print();
    cout << "-----------------------------------------------------------------------------\n";

    cout << "insert At the beginning of the prev ex 4 5 : ";
    l2.insertAtHead(4);
    l2.insertAtHead(5);
    l2.print();
    cout << "-----------------------------------------------------------------------------\n";

    cout << "Insert at a spcific pos 3 insert 10 :  ";
    l2.InsertAt(10,3);
    l2.print();
    cout << "-----------------------------------------------------------------------------\n";


    cout <<"Delete the last element in the prev ex : ";
    l2.removeAtTail();
    l2.print();
    cout << "-----------------------------------------------------------------------------\n";

    cout <<"Delete the first element in the prev ex : ";
    l2.removeAtHead();
    l2.print();
    cout << "-----------------------------------------------------------------------------\n";

    cout <<"Delet the element at indx 3 int the prev ex: ";
    l2.removeAt(3);
    l2.print();
    cout << "-----------------------------------------------------------------------------\n";

    cout << "retrive the element at indx 3 from the prev ex : ";
    cout << l2.retrieveAt(3);
    cout << endl << "------------------------------------------------------------\n";


    cout << "Replace element at pos 2  with 100 : \n";
    l2.print();
    cout << endl;
    l2.replaceAt(100, 2 );
    l2.print();
    cout << endl << "------------------------------------------------------------\n";

    cout << "check if the element is already in the doublelinked list 100 : ";
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