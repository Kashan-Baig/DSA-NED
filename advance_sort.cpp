#include <iostream>
using namespace std;

// void merge(int arr[],int l,int mid,int r){

//     int n1 = mid-l+1;
//     int n2 = r-mid;

//     int a[n1],b[n2];

//     for(int i=0;i<n1;i++){
//         a[i] = arr[l+i];
//     }
//     for(int i=0;i<n2;i++){
//         b[i] = arr[mid+i+1];
//     }
//     int i=0,j=0,k=l;
//     while(i<n1 && j<n2){
//         if(a[i]<b[j]){
//             arr[k] = a[i];
//             k++,i++;
//         }
//         else{
//             arr[k] = b[j];
//             k++,j++;
//         }
//     }
//     while(i<n1){
//         arr[k] = a[i];
//         k++,i++;
//     }
//     while(j<n2){
//         arr[k] = b[j];
//         k++,j++;
//     }

// }

// void mergesort(int arr[],int l,int r){

//     if(l<r){
//         int mid = (l+r)/2;
//         mergesort(arr,l,mid);
//         mergesort(arr,mid+1,r);

//         merge(arr,l,mid,r);
//     }
// }

class employeeNode{
    public:
    int id;
    string name , department;
    employeeNode* left;
    employeeNode* right;

    employeeNode(int empId, string empName, string empDept){
         id = empId;
        name = empName;
        department = empDept;
        left = right = nullptr;
    }

};

employeeNode* insert(employeeNode* root,int id,string name,string dept){
    if(root==nullptr){
        return new employeeNode(id,name,dept);
    }
    if(id<root->id){
        root->left = insert(root->left,id,name,dept);
    }
    else{
        root->right = insert(root->right,id,name,dept);

    }
    return root;
}

string search(employeeNode* root, int id){
    if(root->id == id){
        return root->name + "," + root->department;
    }
    if(id<root->id){
        return search(root->left,id);
    }
    else{
        return search(root->right,id);
    }
}

employeeNode* getios(employeeNode* root){

    while(root!=nullptr && root->left!=nullptr){
        root = root->left;
    }
    return root;
}

employeeNode* delemp(employeeNode* root, int id){
    
    if(root==nullptr) return root;

    if(id<root->id){
        root->left = delemp( root->left, id);
    }
    else if(id>root->id){
        root->right = delemp( root->right, id);
    }
    else{
        if(root->left==nullptr){
            employeeNode* temp = root->right;
            delete root;
            return temp;

        }
        else if(root->right==nullptr){
            employeeNode* temp = root->left;
            delete root;
            return temp;

        }
        else{
            employeeNode* ios = getios(root);
            root->id = ios->id;
            root->name = ios->name;
            root->department = ios->department;
            root->right = delemp(root->right,ios->id);
        }
    }
    return root;
}

void inorder(employeeNode* root){
    if(root==nullptr){
        return;
    }

    inorder(root->left);
    cout<<"ID: "<<root->id<<", NAME: "<<root->name<<", Dept: "<<root->department<<endl;
    inorder(root->right);

}

int getsum(employeeNode* root){
    if(root==nullptr){
        return 0;
    }
     int leftSum  = getsum(root->left);
    int rightSum = getsum(root->right);

    return root->id + leftSum + rightSum;

}

void findmin(employeeNode* root,int id){
    if(root==nullptr){
        return;
    }
    while(root->left!=nullptr){
        root = root->left;
    }
    cout<<"ID: "<<root->id<<", NAME: "<<root->name<<", Dept: "<<root->department<<endl;
}

void findmax(employeeNode* root,int id){
    if(root==nullptr){
        return;
    }
    while(root->right!=nullptr){
        root = root->right;
    }
    cout<<"ID: "<<root->id<<", NAME: "<<root->name<<", Dept: "<<root->department<<endl;
}

employeeNode* lca(employeeNode* root,int id1,int id2){
    if(root==nullptr){
        return nullptr;
    }
    if(id1<root->id && id2<root->id){
        return lca(root->left,id1,id2);
    }
    if(id1>root->id && id2>root->id){
        return lca(root->right,id1,id2);
    }
    return root;
}

class Solutions {
public:
    int minDiff = INT_MAX;
    int prev = -1;

    void inorder(employeeNode* root) {
        if (!root) return;

        inorder(root->left);

        if (prev != -1) {
            minDiff = min(minDiff, root->id - prev);
        }
        prev = root->id;

        inorder(root->right);
    }

    int getMinimumDifference(employeeNode* root) {
        inorder(root);
        return minDiff;
    }
};

int main(){

    employeeNode* root = nullptr;

    // INSERTING EMPLOYEES
    root = insert(root, 20, "Ali", "HR");
    root = insert(root, 10, "Sara", "IT");
    root = insert(root, 40, "Kashan", "Finance");
    root = insert(root, 30, "Hira", "Sales");
    root = insert(root, 50, "Ahmed", "Admin");
    
    cout << "Inorder Traversal (Sorted by ID):" << endl;
    inorder(root);
    cout << endl;

    // SEARCH EMPLOYEE
    cout << "Searching ID 30:" << endl;
    string s = search(root, 30);
    cout << s << endl << endl;

    // DELETE EMPLOYEE
    cout << "Deleting ID 40..." << endl;
    root = delemp(root, 40);

    cout << "Inorder After Deletion:" << endl;
    inorder(root);
    cout << endl;

    // FIND MINIMUM ID EMPLOYEE
    cout << "Employee with Minimum ID:" << endl;
    findmin(root, 0);

    // FIND MAXIMUM ID EMPLOYEE
    cout << "Employee with Maximum ID:" << endl;
    findmax(root, 0);

    // FIND SUM of ID
    cout << "Sum of ID:" << endl;
    cout<<getsum(root);

    // LCA
    cout<<"Least Common Ancestor:"<<endl;
    employeeNode* ans = lca(root, 10, 30);

    cout << "LCA ID = " << ans->id 
     << ", NAME = " << ans->name 
     << ", Dept = " << ans->department;

    Solutions sol;
    int result = sol.getMinimumDifference(root);
    cout << "Minimum difference in BST: " << result << endl;


    // int arr[] = {8,9,6,4,3,2,1,5};
    // mergesort(arr,0,7);
    // for(int v:arr){
    //     cout<<v;
    // }
}