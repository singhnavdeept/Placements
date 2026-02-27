#include<bits/stdc++.h>
using namespace std;

int recPAR(vector<int>&ulpar,int node){

}











int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(m,vector<int>(3,0));
    for(int i=0;i<m;i++){
        cin>>edges[i][1]>>edges[i][2]>>edges[i][0];
    }
    //sorting according to the cost 
    sort(edges.begin(),edges.end());
    vector<int> ulpar(n+1); //ultimate parent
    vector<int> size(n+1,1); //at starting the size of every tree is 1;
    for(int i=1;i<=n;i++){ulpar[i]=i;}
    int cnt =0;//count of edeges connected;
    int cost=0;//cost of edges connected;
    for(int i=0;i<m;i++){
        int ulpar1=recPAR(ulpar,edges[i][1]);
        int ulpar2= recPAR(ulpar,edges[i][2]);
        if(ulpar1==ulpar2)continue;
        if(size[ulpar1]<size[ulpar2]){
            size[ulpar2]+=size[ulpar1];
            ulpar[ulpar1]=ulpar2;
        }
        else{
            size[ulpar1] +=size[ulpar2];
            ulpar[ulpar2]=ulpar1;
        }
        cnt+=1;
        cost
    }
}