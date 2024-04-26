#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std ;

template<typename T>

class Queue {

private:
    int capacity;
    int top;
    int Queue_Size;
    vector<T>items;

public:

    Queue(){
        top=-1;
        Queue_Size = 0;
    }
    void enqueue(T item){
        items.push_back(item);
    }
    T dequeue(){
        if (!isEmpty()){
            T top_item = items.front();
            items.erase(items.begin());
            return top_item;
        }
        else{
            cout<<"\n Queue is already empty !\n";
        }
    }

    T first(){
        if (!isEmpty()){
            return items[0];
        }
        else{
            cout<<"\n Queue is already empty !\n";
        }

    }
    bool isEmpty(){
        return items.empty();
    }
    int queueSize(){
        return items.size();
    }
    void clear(){
        items.clear();
    }
    void print(){
        cout << "\nQueue elements: \n [ ";
        for (const auto& item : items) {
            cout <<item<< ",";
        }
        cout<<" ]\n";
    }
};

int main (){
    char choice;
    cout<<"what's the Data type of Queue \n ";
    cout<<"1 . int \n 2. double \n 3. Char\n 4. String\n";
    cout << "Enter your choice (1/2/3/4): ";
    cin >> choice;
    switch (choice) {
        case '1': {
            Queue<int> intQueue;
            int s,x;
            cout<<" enter num of element : ";
            cin>>s;
            for (int i=0 ;i<s;i++) {
                cout<<"\n enqueue the element into Queue : ";
                cin>>x;
                intQueue.enqueue(x);
            }
            cout << "Queue size: " << intQueue.queueSize()<<"\n";
            cout << "first element: " << intQueue.first() <<"\n";
            cout << "dequeue element: " << intQueue.dequeue() <<"\n";
            cout << "Queue size: " << intQueue.queueSize()<<"\n";
            intQueue.print();
            intQueue.clear();
            cout<<"after clear";
            intQueue.print();
            break;
        }
        case '2': {
            Queue<double> doubleQueue;
            int s; double x;
            cout<<" enter num of element : ";
            cin>>s;
            for (int i=0 ;i<s;i++) {
                cout<<"\n enqueue the element into Queue : ";
                cin>>x;
                doubleQueue.enqueue(x);
            }
            cout << "Queue size: " << doubleQueue.queueSize()<<"\n";
            cout << "first element: " << doubleQueue.first() <<"\n";
            cout << "dequeue element: " << doubleQueue.dequeue() <<"\n";
            cout << "Queue size: " << doubleQueue.queueSize()<<"\n";
            doubleQueue.print();
            doubleQueue.clear();
            cout<<"after clear";
            doubleQueue.print();
            break;

        }
        case '3': {
            Queue<char> charQueue;
            int s; char x;
            cout<<" enter num of element : ";
            cin>>s;
            for (int i=0 ;i<s;i++) {
                cout<<"\n enqueue the element into Queue : ";
                cin>>x;
                charQueue.enqueue(x);
            }
            cout << "Queue size: " << charQueue.queueSize()<<"\n";
            cout << "first element: " << charQueue.first() <<"\n";
            cout << "dequeue element: " << charQueue.dequeue() <<"\n";
            cout << "Queue size: " << charQueue.queueSize()<<"\n";
            charQueue.print();
            charQueue.clear();
            cout<<"after clear";
            charQueue.print();
            break;
        }
        case '4':{
            Queue<string> StringQueue;
            int s; string x;
            cout<<" enter num of element : ";
            cin>>s;
            for (int i=0 ;i<s;i++) {
                cout<<"\n enqueue the element into Queue : ";
                cin>>x;
                StringQueue.enqueue(x);
            }
            cout << "Queue size: " << StringQueue.queueSize()<<"\n";
            cout << "first element: " << StringQueue.first() <<"\n";
            cout << "dequeue element: " << StringQueue.dequeue() <<"\n";
            cout << "Queue size: " << StringQueue.queueSize()<<"\n";
            StringQueue.print();
            StringQueue.clear();
            cout<<"after clear";
            StringQueue.print();
            break;
        }
        default:
            cout << "Invalid choice!" <<"\n";
    }

    return 0;
}