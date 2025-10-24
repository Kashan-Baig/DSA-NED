// #include <iostream>
// #include <vector>

// using namespace std; 

// void modifiedbubblesort(vector<int>& arr) {
//  int n=arr.size(); 
//  for (int i = 0; i < n - 1; i++) {
//  bool swapped = false; 
// for (int j = 0; j < n - i - 1; j++) { 
// if (arr[j] > arr[j + 1]) {
//  swap(arr[j], arr[j + 1]); swapped = true; 
//     } 
// } 
// if (!swapped) break; 
// } 
// } 

// int main() { 

// vector <int> arr={5,1,4,2,8}; 
// cout << "Original Array: "; 
// for (int x: arr){
//       cout<<x<<" ";
//     } 
// modifiedbubblesort(arr); 
// cout<<endl<<"Sorted Array: "; 
// for (int x: arr) { cout<<x<<" "; } 

// return 0; 
// }


#include <iostream>
#include <algorithm>
using namespace std;

int toys(int arr[], int N, int K) {
    sort(arr, arr + N);
    int count = 0;
    int sum = 0;

    for (int i = 0; i < N; i++) {
        if (sum + arr[i] <= K) {
            sum += arr[i];
            count++;
        } else {
            break;
        }
    }
    return count;
}

int main() {
    int a[] = {1, 12, 5, 111, 200, 1000, 10};
    int N = sizeof(a) / sizeof(a[0]);
    int K = 50;

    cout << "No. of toys that can be bought = " << toys(a, N, K);
    return 0;
}

