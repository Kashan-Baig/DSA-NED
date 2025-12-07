#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> max_heap(vector<int> arr){

    priority_queue<int,vector<int>> maxheap;
    for(int val:arr){
        maxheap.push(val);
    }
    return maxheap;
}
priority_queue<int,vector<int>,greater<int>> min_heap(vector<int> arr){

    priority_queue<int,vector<int>,greater<int>> minheap;
    for(int val:arr){
        minheap.push(val);
    }
    return minheap;
}
void heapify(vector<int>& arr,int n,int i){
    int maxidx = i;
    int l = 2*i+1;
    int r = 2*i+2;

    if(l<n && arr[l]>arr[maxidx]) maxidx = l;
    if(r<n && arr[r]>arr[maxidx]) maxidx = r;
    if(maxidx!=i){
        swap(arr[i],arr[maxidx]);
        heapify(arr,n,maxidx);
    }

}
void heapsort(vector<int>& arr){
 int n = arr.size();

 for(int i = n/2-1;i>=0;i--){
    heapify(arr,n,i);
 }
 for(int i = n-1;i>0;i--){
    swap(arr[0],arr[i]);
    heapify(arr,n,0);
 }
}
void printArray(vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

int main(){
    vector<int> arr = {2, 11, 13, 5, 6, 7};

    cout << "Original array: ";
    printArray(arr);

    heapsort(arr);

    cout << "Sorted array using Heap Sort: ";
    printArray(arr);

}