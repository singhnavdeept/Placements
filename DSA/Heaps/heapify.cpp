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

void deletenode( vector<int>& arr, int val){
    int n =arr.size();
    int idx=0;
    for(int i=0;i<n;i++){
        if(val==arr[i]){
            idx=i;
            break;
        }
    }
    swap(arr[idx],arr[n-1]);
    arr.pop_back();
    n =arr.size();
    for(int i=(n/2)-1;i>=0;i--){
        heapify(arr,n,i);
    }
}
void insertheap(vector<int>&arr, int m , int val){

}
void build(vector<int>&arr, int n ){
    
     for(int i =n ;i>=0;i--){
        heapify(arr,arr.size(),i);
    }
}
int main(){

    vector<int>arr ={10,60,30,50,40,20,80};

    int n = (arr.size()/2)-1;
    
   

    
    for(int i:arr){
        cout<<i<<" ";
    }

 cout<<"\n";
    deletenode(arr,50);
     for(int i:arr){
        cout<<i<<" ";
    }
    return 0;

}