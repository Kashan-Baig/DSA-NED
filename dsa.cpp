#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data = val;
        next = prev = nullptr;
    }
};
class single_list{
    public:
        node* head;
        node* tail;

        single_list(){
            head = tail = nullptr;
        }
        node* reverse(node* start) {
    node* prev = nullptr;
    node* curr = start;
    node* next = nullptr;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev; // returns new head of reversed part
}
        void push_head(int val){
            node* newnode = new node(val);
            if(head==nullptr){
                head = tail = newnode;
                return;
            }
            newnode->next = head;
            head = newnode;
        }
        void push_tail(int val){
            node* newnode = new node(val);
            if(head==nullptr){
                head = tail = newnode;
                return;
            }
            tail->next = newnode;
            tail = newnode;
        }
        void pop_head(){
            if(head==nullptr){
                cout<<"List empty\n";
                return;
            }
            node* temp = head;
            head = head->next;
            delete temp;
        }
        void pop_tail(){
            if(head==nullptr){
                cout<<"List empty\n";
                return;
            }
            node* temp = head;
            while(temp->next->next!=nullptr){
                temp = temp->next;
            }
            delete tail;
            temp->next = nullptr;
            tail = temp;
        }
        bool pallindrome(){
            node* slow=head;
            node* fast = head;
            while(fast!=nullptr && fast->next != nullptr){
                slow = slow->next;
                fast=fast->next->next;
            }
            node* prev = nullptr;
            node* curr = slow;
            node* next = nullptr;
            while(curr!=nullptr){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            node* first = head;
            node* second = prev;

            while(second!=first){
                if(first->data!=second->data) return false;
                first = first->next;
                second = second->next;
            }
            return true;
        }
        int size(){
            int count=0;
            while(head!=nullptr){
                count++;
            }
            return count;
        }
        void sort(){
            bool swapped ;
            node*  ptr1;
            node* ptr2 = nullptr;
            do{
                swapped = false;
                ptr1 = head;
                while(ptr1->next!=ptr2){
                    if(ptr1->data>ptr1->next->data){
                    swap(ptr1->data, ptr1->next->data);
                    swapped = true;
                }
                    ptr1=ptr1->next;
                }ptr2 = ptr1;
            }while(swapped);
        } 
        node* merge(node* left,node* right){
            if(!right) return left;
            if(!left) return right;

            node* result = nullptr;

            if(left->data>right->data){
                result = left;
                result->next = merge(left->next, right);
            }
            else {
            result = right;
            result->next = merge(left, right->next);
            }
        return result;
        }
        void print(){
            if(head==nullptr){
                cout<<"List empty\n";
                return;
            }
            node* temp = head;
            while(temp!=nullptr){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};
class doubly_list{
    public:
        node* head;
        node* tail;

        doubly_list(){
            head = tail = nullptr;
        }
        void push_head(int val){
            node* newnode = new node(val);
            if(head==nullptr){
                head = tail = newnode;
            }
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        void push_tail(int val){
            node* newnode = new node(val);
            if(head==nullptr){
                head = tail = newnode;
            }
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        void pop_head(){
            if(head==nullptr){
                cout<<"List empty\n";
                return;
            }
            node* temp = head;
            head = head->next;
            head->prev = nullptr;
            delete temp;
        }
        void pop_tail(){
            if(head==nullptr){
                cout<<"List empty\n";
                return;
            }
            node* temp = head;
            while(temp->next->next!=nullptr){
                temp = temp->next;
            }
            temp->next = nullptr;
            temp->prev = tail->prev;
            delete tail;
            tail = temp;
        }
        void print_forward(){
            if(head==nullptr){
                cout<<"List empty\n";
                return;
            }
            node* temp = head;
            while(temp!=nullptr){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
        void print_back(){
            if(head==nullptr){
                cout<<"List empty\n";
                return;
            }
            node* temp = tail;
            while(temp!=nullptr){
                cout<<temp->data<<" ";
                temp = temp->prev;
            }
            cout<<endl;
        }
};
class circlular_list{
    public:
        node* head;
        node* tail;

        circlular_list(){
            head = tail = nullptr;
        }
        void push_head(int val){
            node* newnode = new node(val);
            if(head==nullptr){
                head = tail = newnode;
                tail->next = head;
            }
            newnode->next = head;
            head = newnode;
            tail->next = newnode;
        }
        void push_tail(int val){
            node* newnode = new node(val);
            if(head==nullptr){
                head = tail = newnode;
                tail->next = head;
            }else{
            tail->next = newnode;
            newnode->next = head;
            tail = newnode;}
        }
        void pop_head(){
            if(head==nullptr){
                cout<<"List empty\n";
                return;
            }
            node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
        void pop_tail(){
            if(head==nullptr){
                cout<<"List empty\n";
                return;
            }
            if (head == tail){
            delete head;
            head = tail = nullptr;
            return;
            }
            node* temp = head;
            while(temp->next!=tail){
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = head;
        }
        void print_forward(){
            if(head==nullptr){
                cout<<"List empty\n";
                return;
            }
            node* temp = head;
            while(temp!=tail){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout << temp->data << endl; 
        }
};
class Stack{
    public:
    int top;
    int* arr;
    int size;
    Stack(int s){
        size = s;
        top = -1;
        arr = new int[size];
    }
    void push(int val){
        if(top == size - 1){
            cout<<"Full"<<endl;
        }
        else{
            arr[++top] = val;
        }
    }
    void pop(){
        if(top == - 1){
            cout<<"Empty"<<endl;
        }
        else{
            top--;
        }
    }
    int peek(){
        return arr[top];
    }
    
};
class Queue{
    public:
    int rear,front,capacity;
    int* arr;
    Queue(int cap){
        capacity = cap;
        rear = -1;front=0;
        arr = new int[capacity];
    }
    void push(int val){
        if(rear == capacity -1){cout<<"full";return;}
        else{
            arr[++rear] = val;
        }
    }
    void pop(){
        if(rear == -1){cout<<"Empty";return;}
        else{
            front++;
        }
    }
    void display() {
        if (front > rear) {
            cout << "Empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
class C_Queue{
    public:
    int rear,front,capacity,size;
    int* arr;
    C_Queue(int cap){
        capacity = cap;
        rear = -1;front=-1;size=0;
        arr = new int[capacity];
    }
    bool isempty(){
        return size==0;
    }
    void push(int val){
        if(size==capacity){cout<<"full";return;}
        else if (isempty()) {
            front = rear = 0;
        }
        else{
            rear = (rear+1)%capacity;
        }
        arr[rear] = val;
        size++;
    }
    void pop(){
        if(isempty()){cout<<"Empty";return;}
        else if(front == rear) front = rear = - 1;
        else{
            front = (front+1)%capacity;
        }
        size--;
    }
    int peeek(){return arr[front];}
};
bool linearsearch(int arr[],int key,int size){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return true;
        }
    }
    return false;
}
bool binarysearch(int arr[],int key,int size){
    int start =0 , end = size-1;
    while(start<=end){
        int mid = (start+end)/2;
        if(arr[mid]==key){
            return true;
        }
        else if(arr[mid]<key){
            // pichla half end  
            start = mid+1;
        }
        else if(arr[mid]>key){
            // agla half end
            end = mid-1;
        }
    }
    return false;
}
void bubblesort(int* arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void insertionsort(int* arr,int n){
    for(int i=1;i<n;i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0 and arr[prev]>curr){
            arr[prev+1] = arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
}
void selectionsort(int* arr,int n){
    for(int i =0;i<n-1;i++){
        int small = i;
        for(int j =i+1;j<n;j++){
            if(arr[small]>arr[j]){
                small = j;
            }
        }
        swap(arr[i],arr[small]);
    }
}

int main(){

    // int array[5] = {4,2,3,1,0};

    // selectionsort(array,5);
    //  cout << "Sorted array: ";
    // for (int i = 0; i < 5; i++) {
    //     cout << array[i] << " ";
    // }

    single_list s,d;
    s.push_head(1);
    s.push_head(4);
    s.push_head(9);
    s.push_head(4);
    s.push_head(1);
    s.print();
    cout<<s.pallindrome()<<"it is";
    // s.sort();
    // d.push_head(5);
    // d.push_head(4);
    // d.push_tail(2);
    // d.push_head(0);
    // d.sort();

    // s.print_forward();
    // s.pop_head();
    // s.print_forward();
    // s.pop_tail();
    // s.print_forward();

    // C_Queue q(5);

    // q.push(10);
    // q.push(20);
    // q.push(30);
    // cout<<q.peeek()<<endl;

    // q.pop();
    // cout<<q.peeek()<<endl;

    // Stack s(3);
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);
    // cout<<s.peek()<<endl;
    // s.pop();
    // cout<<s.peek()<<endl;


    return 0;
}