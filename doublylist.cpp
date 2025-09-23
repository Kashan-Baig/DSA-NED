#include <iostream>
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

class doubly_list{
    public:
    node* head;
    node* tail;

    doubly_list(){
        head = tail = nullptr;
    }

    void insert_front(int val){
        node* newnode = new node(val);

        if(head==nullptr){
            head = tail = newnode;
        }
        else{
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    void insert_back(int val){
        node* newnode = new node(val);

        if(head==nullptr){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }

    void pop_front(){

        if(head == nullptr){
        cout << "List is empty!" << endl;
        return;
        }

        node* temp = head;
        head = head->next;

        if(head != nullptr){
        head->prev = nullptr;  
        } 
        else{
        tail = nullptr;      
        }

        delete temp;
    }

    void pop_back(){

        if(head == nullptr){
        cout << "List is empty!" << endl;
        return;
        }

        if(head == tail){
        delete head;
        head = tail = nullptr;
        return;
        }

        node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;

        delete temp;
    }

    void display(){
        node* temp = head;

        cout<<"NULL<->";
        while(temp!=nullptr){
            cout<<temp->data<<"<->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
    
    doubly_list d1;
    d1.insert_front(2);
    d1.insert_front(5);
    d1.insert_back(1);
    d1.display();
    d1.pop_front();
    d1.pop_back();
    d1.display();

    return 0;
}