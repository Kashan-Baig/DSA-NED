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
class linklist{
    public:
    node* head;
    node* tail;

    linklist(){
        head = tail = nullptr;
    }

    void pushfront(int val){
        node* newnode = new node(val);
        if(head==nullptr){
            head = tail = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
    }

   void pushback(int val) {
        node* newnode = new node(val);

        if(head == nullptr){         
            head = tail = newnode;
        }
        else{
            tail->next = newnode;       
            tail = newnode;             
        }
    }
    void push_choice(int val,int pos){
        node* newnode = new node(val);
        node* temp = head;
        if(head == nullptr){         
            head = tail = newnode;
        }
        else if (temp == nullptr) {  // position out of range
        cout << "Position out of range!" << endl;
        delete newnode;
        return;
    }
        else{
            for(int i=0;i<pos;i++){
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    void popfront(){
        node* temp = head;
        head = head->next;
        delete temp;
    }
    void popback(){
        if (head == nullptr) {     
            return;
        }
        else{
            node* temp = head;
            while(temp->next->next!=nullptr){
                temp=temp->next;
            }
            temp->next = nullptr;
            delete tail;
            tail = temp;
        }
    }

    void search(int val){
        node* temp = head;
        bool found = false;

        while(temp!=nullptr){
            if(temp->data == val){
                cout<<"Data found";
                break;
            }
            else{
                temp=temp->next;
            }
        }
        if (!found) {
        cout << "Data not found" << endl;
        }
    }

    void display(){
        node* temp = head;
        while(temp!=nullptr){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL";
    }

    void reverse(){
        node* curr = head;
        node* prev = nullptr;
        node* next = nullptr;

        tail = head;

        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void middlenode(){
        node* temp = head;
        int count = 0;
        while(temp!=nullptr){
            count++;
            temp = temp->next;
        }
        count/=2;
        
        temp = head;
        for(int i=0;i<count;i++){
            temp = temp->next;
        }
        cout<<temp->data;
    }

};


int main() {

    linklist l1;
    l1.pushfront(1);
    l1.pushfront(2);
    l1.pushfront(3);
    l1.pushback(4);
    l1.push_choice(5,2);
    l1.display();
    cout<<endl;
    // l1.reverse();
    // l1.display();
    l1.middlenode();
    

    return 0;
}