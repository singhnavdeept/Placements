#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>& arr, int n , int i){
    int largest = i;
    
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
}
}


int main(){

    vector<int>arr ={10,60,30,50,40,20,80};

    int n = (arr.size()/2)-1;
    int x =2;
    for(int i =n ;i>=0;i--){
        heapify(arr,arr.size(),i);
    }

    
    for(int i:arr){
        cout<<i<<" ";
    }
}