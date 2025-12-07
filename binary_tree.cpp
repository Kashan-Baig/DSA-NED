#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class node{
    public:
    int data;
    node* right;
    node* left;

    node(int val){
        data = val;
        left = right = nullptr;
    }
};
void stackpre(node* root){
    if(root==nullptr){
        return;
    }
    stack <node*> st;
    st.push(root);

    while(!st.empty()){
        node* curr = st.top();
        st.pop();

        cout<<curr->data;

        if(curr->left) st.push(curr->left);
        if(curr->right) st.push(curr->right);
    }
}
void stackpost(node* root){
    if(root==nullptr) return;
    stack <node*> st1,st2;
    st1.push(root);

    while(!st1.empty()){
        node* curr = st1.top();
        st1.pop();
        st2.push(curr);

        if(curr->left) st1.push(curr->left);
        if(curr->right) st1.push(curr->right);
    }
        
    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}



static int idx = -1 ;
node* buildtree(vector<int> preorder){
    idx++;

    if(idx >= preorder.size() || preorder[idx] == -1){
        return nullptr;
    }

    node* root = new node(preorder[idx]);
    root->left = buildtree(preorder);
    root->right = buildtree(preorder);

    return root;

}
// root - left - right
void preorder(node* root){
    if(root == nullptr){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
// left - root - righ
void inorder(node* root){
    if(root == nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right); 
}
// left - right - root
void postorder(node* root){
    if(root == nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
}

void levelorder(node* root){
    queue <node*> q;
    q.push(root);
    int count = 0;

    while(q.size()>0){
        node* curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        count++;
        if(curr->left!=nullptr){
            q.push(curr->left);
        }
        if(curr->right!=nullptr){
            q.push(curr->right);
        }
    }
    cout<<endl;
    cout<<"Total nodes: "<<count;
}


int main(){

    vector<int> pre = {5, 3, 8, 2, 4, 6, 9, 1};

    node* root = buildtree(pre);
    stackpost(root);
    cout<<endl;
    // preorder(root);
    // cout<<endl;
    postorder(root);
    cout<<endl;
    // levelorder(root);

}