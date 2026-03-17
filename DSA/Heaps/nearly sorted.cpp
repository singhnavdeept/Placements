#include<queue>
#include<vector>
#include<iostream>
using namespace std;
void solve(vector<int>& arr, int k){
    priority_queue<int, vector<int>, greater<int>>pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    int j ;
    for(j =k ;j<arr.size();j++){
        pq.push(arr[j]);
        arr[j-k]=pq.top();
        pq.pop();

    }
    while(!pq.empty()){
        arr[j-k]=pq.top();pq.pop();j++;
    }
}
int main(){
    vector<int>v ={2, 3, 1, 4};
    solve(v,2);
    for(int i:v){
        cout<<i<<" ";
    }
    return 0;
}