#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> topkfreq(vector<int> arr,int k){
    unordered_map<int,int> freq;

    for(int num:arr){
        freq[num]++;
    }
    priority_queue<pair<int,int>> maxheap;

    for(auto &p : freq) {
        maxheap.push({p.second, p.first});
    }

    // get top k
    vector<int> result;
    while(k--) {
        result.push_back(maxheap.top().second);
        maxheap.pop();
    }

    return result;
}

string sort(string s){

    unordered_map<int,int> freq;

    for(int num:s){
        freq[num]++;
    }

    priority_queue<pair<int,int>> maxheap;

    string sorted = "";
    for(auto& p: freq){
        maxheap.push({p.second,p.first});
    }

    while(!maxheap.empty()){
        auto top = maxheap.top();
        maxheap.pop();
        sorted.append(top.first,top.second);
    }

    return sorted;
}

int main(){
    string s="cccaaa";
    cout<<sort(s);
}