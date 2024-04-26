#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std ;

template<typename T>

class Stack {

private:
    int capacity;
    int top;
    int Stack_Size;
    vector<T>items;
public:

    Stack(){
    top=-1;
    Stack_Size = 0;
    }
    void push(T item){
         items.push_back(item);
    }
    T pop(){
     if (!isEmpty()){
         T top_item = items.back();
         items.pop_back();
         return top_item;
     }
     else{
         cout<<"\n Stack is already empty !\n";
     }
    }

    T Top(){
        if (!isEmpty()){
            return  items.back();
        }
        else{
            cout<<"\n Stack is already empty !\n";
        }

    }
    bool isEmpty(){
        return items.empty();
    }
    int StackSize(){
        return items.size();
    }
    void clear(){
        items.clear();
    }
    void print(){
        cout << "\nStack elements: \n [ ";
        for (auto it = items.rbegin(); it != items.rend(); ++it) {
            cout << *it << ",";
        }
        cout<<" ]\n";
    }
};

int main (){
    char choice;
    cout<<"what's the Data type of Stack \n ";
    cout<<"1 . int \n 2. Char \n 3. double\n 4. String\n";
    cout << "Enter your choice (1/2/3): ";
    cin >> choice;
    switch (choice) {
        case '1': {
            Stack<int> intStack;
            int s,x;
            cout<<" enter num of element : ";
            cin>>s;
            for (int i=0 ;i<s;i++) {
                cout<<"\n push the element into stack : ";
                cin>>x;
                intStack.push(x);
            }
            cout << "Stack size: " << intStack.StackSize() <<"\n";
            cout << "Top element: " << intStack.Top() <<"\n";
            cout << "pop element: " << intStack.pop() <<"\n";
            cout << "Stack size: " << intStack.StackSize() <<"\n";
            intStack.print();
            intStack.clear();
            cout<<"after clear";
            intStack.print();
            break;
        }
        case '2': {
            Stack<double> doubleStack;
            int s; double x;
            cout<<" enter num of element : ";
            cin>>s;

            for (int i=0 ;i<s;i++) {
                cout<<"\n\n push the element into stack : ";
                doubleStack.push(x);
                cin>>x;
            }
            cout << "Stack size: " << doubleStack.StackSize() <<"\n";
            cout << "Top element: " << doubleStack.Top() <<"\n";
            cout << "pop element: " << doubleStack.pop() <<"\n";
            cout << "Stack size: " << doubleStack.StackSize() <<"\n";
            doubleStack.print();
            doubleStack.clear();
            cout<<"after clear";
            doubleStack.print();
            break;
        }
        case '3': {
            Stack<char> CharStack;
            int s; char x;
            cout<<" enter num of element : ";
            cin>>s;

            for (int i=0 ;i<s;i++) {
                cout<<"\n\n push the element into stack : ";
                CharStack.push(x);
                cin>>x;
            }
            cout << "Stack size: " << CharStack.StackSize() <<"\n";
            cout << "Top element: " << CharStack.Top() <<"\n";
            cout << "pop element: " << CharStack.pop() <<"\n";
            cout << "Stack size: " << CharStack.StackSize() <<"\n";
            CharStack.print();
            CharStack.clear();
            cout<<"after clear";
            CharStack.print();
            break;
        }
        case '4':{
            Stack<string> StringStack;
            int s; string x;
            cout<<" enter num of element : ";
            cin>>s;
            for (int i=0 ;i<s;i++) {
                cout<<"\n\n push the element into stack : ";
                StringStack.push(x);
                cin>>x;
            }
            cout << "Stack size: " <<  StringStack.StackSize() <<"\n";
            cout << "Top element: " <<  StringStack.Top() <<"\n";
            cout << "pop element: " <<  StringStack.pop() <<"\n";
            cout << "Stack size: " <<  StringStack.StackSize() <<"\n";
            StringStack.print();
            StringStack.clear();
            cout<<"after clear";
            StringStack.print();
            break;
        }
        default:
            cout << "Invalid choice!" <<"\n";
    }

    return 0;
}

