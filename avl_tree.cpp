#include <iostream>
#include <vector>

using namespace std;

class avlnode{
    public:
    int data;
    avlnode* left;
    avlnode* right;
    int height;

    avlnode(int val){
        data = val;
        left = right = nullptr;
        height = -1;
    }
};

int height(avlnode* root){
    if (root != nullptr) return root->height;
    else return 0;
}
int getbf(avlnode* root){
    if(root != nullptr) return height(root->left) - height(root->right);
    else return 0;
}
void updateheight(avlnode* root){
    root->height = 1+max(height(root->left), height(root->right));
}

avlnode* rightrotation(avlnode* y){
    avlnode* x = y->left;
    avlnode* T2 = x->right;

    x->right = y;
    y->left = T2; 

    updateheight(y);
    updateheight(x);

    return x;
}
avlnode* leftrotation(avlnode* x){
    avlnode* y = x->right;
    avlnode* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateheight(y);
    updateheight(x);

    return y;
}

void inorder(avlnode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

avlnode* minValueNode(avlnode* node) {
    while (node->left)
        node = node->left;
    return node;
}

avlnode* insertAVL(avlnode* root, int key){
    if(root==nullptr){
        return new avlnode(key);
    }

    if (key<root->data)
        root->left = insertAVL(root->left,key);
    else if (key > root->data)
        root->right = insertAVL(root->right, key);
    else
        return root;

    updateheight(root);

    int balance = getbf(root);

    // LL CASE
    if(balance>1 && key<root->left->data) {
        return rightrotation(root);}

    // RR CASE
    if(balance<-1 && key>root->right->data){
        return leftrotation(root);}

    // LR CASE
    if (balance > 1 && key > root->left->data) {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }

    // RL CASE
    if (balance < -1 && key < root->right->data) {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }

    return root;
}

avlnode* deletenode(avlnode* root,int key){
    if(root==nullptr){
        return root;
    }

    if(key<root->data){
        root->left = deletenode(root->left,key);
    }
    else if(key>root->data){
        root->right = deletenode(root->right,key);
    }
    else{
        if(root->left==nullptr || root->right==nullptr){
            avlnode* temp;
            if (root->left != nullptr) {
                temp = root->left;
            } else {
                temp = root->right;
            }
            if (temp == nullptr) {          // No child
                temp = root;
                root = nullptr;
            } 
            else {                           // One child
                *root = *temp;
            }
            delete temp;
        }
        else{
            avlnode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deletenode(root->right, temp->data);
        }
    }
    if (root == nullptr) return root;

    // Update height
    updateheight(root);
    int balance = getbf(root);

    if (balance > 1 && getbf(root->left) >= 0)
        return rightrotation(root);

    // LR
    if (balance > 1 && getbf(root->left) < 0) {
        root->left = leftrotation(root->left);
        return rightrotation(root);
    }

    // RR
    if (balance < -1 && getbf(root->right) <= 0)
        return leftrotation(root);

    // RL
    if (balance < -1 && getbf(root->right) > 0) {
        root->right = rightrotation(root->right);
        return leftrotation(root);
    }

    return root;
}

avlnode* buildBST(vector<int> arr){
    avlnode* root = nullptr;

    for(int val : arr){
        root = insertAVL(root,val);
    }
    return root;
}

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(NULL) {}
};
avlnode* sortedListToBST(ListNode* head) {
    vector<int> arr;

    // copy list to vector
    while (head) {
        arr.push_back(head->val);
        head = head->next;
    }
    return buildBST(arr);
}
int main(){

    ListNode* head = new ListNode(-10);
    head->next = new ListNode(-3);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(9);

    avlnode* root = sortedListToBST(head);

    cout << "Inorder of BST: ";
    inorder(root);

    // avlnode* root = nullptr;

    // vector<int> pre = {-10, -3, 0, 5, 9};
    // avlnode* root = buildBST(pre);

    // // root = insertAVL(root, 20);
    // // root = insertAVL(root, 4);
    // // root = insertAVL(root, 15);
    // // root = insertAVL(root, 70);
    // // root = insertAVL(root, 50);

    // cout << "Inorder after insertions: ";
    // inorder(root);

    // deletenode(root,0);

    // cout << "\nInorder after deletion: ";
    // inorder(root);
}