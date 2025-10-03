#include <bits/stdc++.h>
using namespace std;


// Dynamic implementation
class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = nullptr;
    }
};
class Queue{
    public:
    node* front;
    node* rear;

    Queue(){
        front = rear = nullptr;
    }

    void enqueue(int val){
        node* newnode = new node(val);
        // newnode->next = nullptr;
        if(front==nullptr){
            front = rear = newnode;
        }
        else{
            rear->next = newnode;
            rear = newnode;
        }
    }
    void dequeue(){
        if(front==nullptr){
            cout<<"Queue is empty.\n";
        }
        else{
            node* temp = front->next;
            
            delete front;
            front = temp;
        }
    }

    int peek(){
        return front->data;
    }

    void display(){
        node* temp = front;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

// Static implementation

class statqueue{
    public:
    int* arr;
    int size;
    int front,rear;

    statqueue(int size){
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    void enqueue(int val) {
    if (rear == size - 1) {
        cout << "Queue is full\n";
        }
    else {
        if (front == -1) front = 0;  
        arr[++rear] = val;
        }
    }

    int dequeue(){
        if(front==-1){
            cout<<"Queue is empty\n";
            return -1;
        }
        int val = arr[front];
        if(front == rear){
            front = rear - 1;
        }
        else{
            front = (front + 1) % size; 
        }
        return val;
    }

    int peek(){
        int val = arr[front];
        return val;
    }


    void display(){
        if (front == -1) {
        cout << "Queue is empty.\n";
        return;
    }
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }



};

// Circular queue
class circular{
    public:
    int* arr;
    int capacity, size,front,rear;

    circular(int capacity){
        this->capacity = capacity;
        arr =  new int[capacity];
        front =0;rear=-1;size=0;
    }

    bool isempty(){
        return size==0;
    }

    void push(int val){
        if(rear==capacity-1){
            cout<<"Queue is full"<<endl;
        }
        else{
            rear = (rear+1)%capacity;
            arr[rear] = val;
            size++ ;
        }
    }

    void pop(){
        if(isempty())cout<<"Queue is empty"<<endl;
        else if(front == rear) front = rear - 1;
        else {
            front = (front+1)%capacity;
            size--;
        }
    }
    int peeek(){return arr[front];}
};


int main(){

    circular cq(3);
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.pop();
    cq.push(4);
    cout<<cq.peeek();


    // statqueue q(3);
    // q.enqueue(1);
    // q.enqueue(2);
    // q.enqueue(5);
    // q.display();
    // cout<<q.dequeue()<<endl;
    // q.display();
    // cout<<q.peek();


}