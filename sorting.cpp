#include <bits/stdc++.h>
using namespace std;


void bubblesort(int arr[],int n){
    for(int i = 0; i<n-1; i++){
        for(int j = 0 ; j<n-i-1;j++ ){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int smallel = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[smallel]){
                smallel = j;
            }
            swap(arr[i],arr[smallel]);
        }
    }
}

void insertionsort(int arr[],int n){
    for(int i=1;i<n;i++){
        int curr = arr[i];
        int prev = i-1;

        while (prev>=0 && arr[prev]>curr)
        {
           arr[prev+1] = arr[prev];
           prev--;
        }
        arr[prev+1] = curr;
        
    }
}


int main(){

        int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    // bubblesort(arr, n);
    // selectionsort(arr,n);
    insertionsort(arr,n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}