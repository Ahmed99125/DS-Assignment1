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
class Stack{
public:
    int lenght = 0 ;
    Node<T> * head ;    
    Node<T> * tail;
    
    // ------ push element into the stack--------------
    void push(T element ){
        Node<T>*newNode = new Node<T> (element);
        if ( lenght == 0 ){
            head = tail = newNode;
            tail->next = nullptr;
        }
        else {
         tail->next = newNode;
         tail = newNode;
        }
        lenght ++;
    }

    // ------------ Helper Function ----------------
    Node<T> * get_nth_node( int n ){
        int cont = 0 ;
        for (Node<T> *curr = head ; curr ; curr = curr->next){
            cont ++;
            if ( cont == n){
                return curr;
            }
        }
    }

    // ---------- remove the last element ----------
    void pop(){
        assert(lenght);
        Node<T>* curr = get_nth_node ( lenght - 1 );
        delete tail ;
        lenght--;
        tail = curr;
        tail->next = nullptr;
        if ( lenght == 0 ){
            head = nullptr;
        }
    }   

    // ---------- Get the last element ----------
    T top (){
        return tail->data;
    }

    // -------- check if the stack is empty or not ---------------
    bool isEmpty(){
        if( lenght != 0 ){
            return false;
        }
        else return true;
    }

    //  ------------- stack size-----------------------
    int stackSize(){
        return lenght;
    }

    // ---------clear the stack ---------------------------
    void clear(){
        while ( head != nullptr ){
            Node<T> * next = head->next;
            delete head;
            head = next;
        }
        lenght = 0;
    }

    // ----------print fun------------------------
    void print(){
        for (Node<T> * curr = head;  curr ; curr = curr->next){
            cout << curr->data << " ";
        }
        cout << endl;
    }

};

int main (){
    cout << "Push some elements into the stackc and print them : ";
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    cout << "------------------------------------------------------------------------\n";

    cout << "Remove the last element from the prev ex : ";
    s.pop();
    s.print();
    cout << "------------------------------------------------------------------------\n";

    cout << "Get the last element from the prev ex : ";
    cout <<s.top(); 
    cout << endl;
    cout << "------------------------------------------------------------------------\n";

    cout << "check if the Stack is empty or not : ";
    if ( s.isEmpty()){
        cout << "Yes it is empty \n";
    }
    else cout << "No the stack is not empty \n";
    cout << "------------------------------------------------------------------------\n";

    cout << "cout the stack size : ";
    cout << s.stackSize() << endl;
    cout << "------------------------------------------------------------------------\n";

    s.clear();
    cout << "print the stack size after using clear function : ";
    cout << s.stackSize() << endl;
    cout << "------------------------------------------------------------------------\n";


}