#include <iostream>
#include <vector>
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

node* insert(node* root,int val){
    if(root==nullptr){
       return new node(val);
    }
    if(val < root->data){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }
    return root;
}

node* buildBST(vector<int> arr){
    node* root = nullptr;

    for(int val : arr){
        root = insert(root,val);
    }
    return root;
}

void inorder(node* root){
    if(root==nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


bool search(node* root,int key){
    if(root==nullptr){
        return false;
    }
    if(root->data == key){
        return true;
    }
    else if(key<root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
    return false;
}

node* getinorder(node* root){
    while (root!=nullptr && root->left!=nullptr){
        root = root->left;
    }
    return root;
}

node* deletenode(node* root,int val){
    if(root==nullptr){
        return root;
    }
    if(val<root->data){
        root->left = deletenode(root->left,val);
    }
    else if(val>root->data){
        root->right = deletenode(root->right,val);
    }
    else{
        if(root->left == nullptr){
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == nullptr){
            node* temp = root->left;
            delete root;
            return temp;
        }
        else{
            node* is = getinorder(root->right);
            root->data = is->data;
            root->right = deletenode(root->right,is->data);
        }
    }
    return root;

}

int main(){
    
    vector<int> arr = {45, 20, 60, 10, 30, 50, 70, 65};

    node* root = buildBST(arr);
    inorder(root);
    cout<<endl;
    cout<<search(root,46);
    deletenode(root,50);
    cout<<endl;
    inorder(root);

}