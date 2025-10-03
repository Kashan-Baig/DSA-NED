#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int* arr;
    int capacity;
    int top;

    Stack(int capacity){
        this->capacity = capacity;
        top = -1;
        arr = new int[capacity];
    }
    ~Stack(){
        delete []arr;
    }

    void push(int val){
        if(top == capacity -1){
            cout<<"Unable to push";
            return;
        }
        arr[++top] = val;
    }

    int pop(){
        if(top==-1){
            cout<<"stack empty";
            return -1;
        }
       return arr[top--];
    }

    int peek(){
        if(top==-1){
            cout<<"stack empty";
            return -1;
        }
        return arr[top];
    }
};

class dynamicstack{
    public:
    vector <int> arr;
    int top;

    void push(int val){arr.push_back(val);}
    void pop(){
        if(!arr.empty()){
            arr.pop_back();
        }
    }
    bool isempty(){
        if(!arr.empty()){return false;}
        return true;
    }
    int peek(){
       return  arr.back();
    }
};


int main(){

    // Stack s(4);
    // s.push(1);
    // s.push(2);
    // s.push(4);
    // cout<<s.pop()<<endl;
    // cout<<s.peek();

    dynamicstack d;
    d.push(1);
    d.push(2);
    d.push(4);
    cout<<d.peek()<<endl;
    d.pop();
    d.pop();
    d.pop();
    cout<<d.isempty();


}