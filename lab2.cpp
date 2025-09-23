#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int val){ data = val; next = nullptr; }
};
class List{
    public:
    Node* head;
    Node* tail;
    List(){
        head = tail = nullptr;
    }
    void push(int val){
        Node* newnode = new Node(val);
        if(head==nullptr){
            head = tail = newnode;
        }
        else{
            newnode->next = head;
            head = newnode;
        }
    }
     void display(Node* node){
        Node* temp = node;
        while (temp!=nullptr){
            cout << temp->data ;
            temp = temp->next;
            if(temp) cout << " -> ";
        }
        cout << " -> NULL" << endl;
    }

    Node* mergelsit(Node* list1,Node* list2){
        Node* dummy = new Node(0);
        tail = dummy;
        while(list1!=nullptr && list2!=nullptr){
            if(list1->data <= list2->data){
                tail->next = list1;
                list1 = list1->next;  
            } 
            else{
            tail->next = list2;   
            list2 = list2->next;
        } 
        tail = tail->next;
        }
        if (list1) tail->next = list1;
        if (list2) tail->next = list2;

        return dummy->next;
    }

    void deleteduplicate(Node* head){
        Node* temp = head;
        Node*current = head;

        while(current!=nullptr){
            if(current->data == temp->data){
                Node* dup = current->next;          
                current->next = current->next->next; 
                delete dup;  
            // delete data
            }
            else{
                temp = temp->next;
                continue;
            }
            current = current->next;
        }
    }

    Node* sortList(Node* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        Node* slow = head;
        Node* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* rightHalf = slow->next;
        slow->next = nullptr;
        Node* leftHalf = head;
        Node* leftSorted = sortList(leftHalf);
        Node* rightSorted = sortList(rightHalf);
        return mergelsit(leftSorted, rightSorted);
    }

    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        while (head != nullptr) {
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    bool isPalindrome(Node* head) {
        if (head == nullptr) return true;
        Node* slow = head;
        Node* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* secondHalfStart = reverseList(slow->next);
        Node* firstPointer = head;
        Node* secondPointer = secondHalfStart;
        bool result = true;
        while (secondPointer != nullptr) {
            if (firstPointer->data != secondPointer->data) {
                result = false;
                break;
            }
            firstPointer = firstPointer->next;
            secondPointer = secondPointer->next;
        }
        slow->next = reverseList(secondHalfStart);
        return result;
    }



};

int main(){

    List l1, l2, mergedList;
    l1.push(4);
    l1.push(2);
    l1.push(1);
    cout << "List 1: ";
    // Q1
    l2.push(4);
    l2.push(3);
    l2.push(1);
    l1.display(l1.head);
    cout << "List 2: ";
    l2.display(l2.head);
    Node* mergedHead = mergedList.mergelsit(l1.head, l2.head);
    cout << "Merged List: ";
    mergedList.display(mergedHead);
    // Q2   
    mergedList.deleteduplicate(mergedHead);
    cout << "Merged List without duplicates: ";
    mergedList.display(mergedHead);
    // Q3
    List l3;
    l3.push(1);
    l3.push(2);
    l3.push(3);
    cout << "List 3: ";
    l3.display(l3.head);
    Node* sortedHead = l3.sortList(l3.head);
    cout << "Sorted List: ";
    l3.display(sortedHead);

    // Q4
    List l4;
    l4.push(1);
    l4.push(2);
    l4.push(3);
    l4.push(2);
    l4.push(1);
    cout << "List 4: ";
    l3.display(l4.head);
    if(l4.isPalindrome(l4.head)){
        cout << "Pallindrome" << endl;}
    else{
        cout << "Not Pallindrome" << endl;
    }

    return 0;
}
