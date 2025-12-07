#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = right = nullptr;
    }

};
void stackpre(node* root){

    if(root==nullptr){
        return;
    }
    stack<node*> st;
    st.push(root);
    while(!st.empty()){
        node* curr = st.top();
        cout<<curr->data<<" ";
        st.pop();
        if(curr->left) st.push(curr->left);
        if(curr->right) st.push(curr->right);
    }
}





int main(){

    
    
}