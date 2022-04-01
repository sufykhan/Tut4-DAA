#include <bits/stdc++.h>
using namespace std;

//BY USING GREEDY METHOD

//SAMPLE TESTCASE

//4 23
//10 6 5 1

int main(){

    cout<<"Provide Total number of Coins : \n";
    int n,target;cin>>n;
    cout<<"Provide Target Value : \n";
    cin>>target;
    vector<int>coins(n);

    cout<<"Provide Space separated Coins VALUE : \n";
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
        cout<<"NOT POSSIBLE TO GET THE CHANGE\n";
    }
    else{
        cout<<"POSSIBLE TO GET THE CHANGE\n";
        cout<<"Minimum no. of coins required:--> "<<cnt<<"\n";
    }
    
}