#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,target;cin>>n>>target;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    sort(coins.begin(),coins.end(),greater<int>());
    int x=0;
    int cnt=0;
    while(x<n){
        if(target-coins[x]>=0){
            target=target-coins[x];
            cnt++;
        }
        else{
            x++;
        }
    }
   
    if(target!=0){
        cout<<"NOT POSSIBLE\n";
    }
    else{
        cout<<"POSSIBLE\n";
        cout<<"Minimum no. of coins required: "<<cnt<<"\n";
    }
    
}