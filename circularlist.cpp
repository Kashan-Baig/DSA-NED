#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = nullptr;
    }
};

class circularlist{
    public:
    node* head;
    node* tail;

    circularlist(){
        head = tail =nullptr;
    }

    void push_front(int val){
        node* newnode = new node(val);
        if(head==nullptr){
            head = tail = newnode;
            newnode->next = head;       
        }
        else{
            newnode->next = head;
            tail->next = newnode;
            head = newnode;
        }
    }
    void push_back(int val){
         node* newnode = new node(val);
        if(tail==nullptr){
            head = tail = newnode;
            tail->next = head;       
        }
        else{
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }
    }
    void pop_front(){
        if(head == nullptr){
            return;
        }
        else{
            node* temp = head;
            temp = temp->next;
            delete head;
            head = temp;
            tail->next = head;
        }
    }
    void pop_back(){
        if(head == nullptr){
            return;
        }
        else if (head == tail){ 
            delete head;
            head = tail = nullptr;
        }
        else{
            node* temp = head;
            while(temp->next->next!=head){
                temp = temp->next;
            }
            temp->next = head;
            delete tail;
            tail = temp;        
        }
    }
    void display(){
        node* temp = head;

        cout << "HEAD -> ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);   

        cout << "(HEAD)" << endl;
        }
};

int binarysearch(int arr[], int n, int key){
    int s=0;
    int e=n-1;

    
    while(s<=e){
        int mid = (s+e)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid]>key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }
    return -1;
}

int main(){

    // circularlist c;
    // c.push_front(2);
    // c.push_front(5);
    // c.display();
    // c.push_back(4);
    // c.display();
    // c.pop_back();
    // c.display();

   int arr[5] = {1, 3, 5, 7, 9};
    cout << binarysearch(arr, 5, 7);

    return 0;
}