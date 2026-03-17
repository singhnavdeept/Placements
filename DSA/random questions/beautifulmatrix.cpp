#include<iostream>
using namespace std;
int main(){
    int i;int j;
    bool f=false;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            int c;
            cin>>c;
            if(c==1){f=true;break;}
        }
        if(f)break;
    }
  
    int distance = abs(i-2) + abs(j-2);
    cout<<distance;
    return 0;

}