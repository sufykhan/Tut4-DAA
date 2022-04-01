#include <bits/stdc++.h>
using namespace std;

//BY USING DP METHOD

//INPUT FORMAT
// n target
// array of size n 

// 4 11
// 8 3 4 2

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

    int dp[target+1];
    for(int i=0;i<=target;i++){
        dp[i]=INT_MAX;
    }
    dp[0]=0;
    for(int i=1;i<=target;i++){
        for(int j=0;j<n;j++){
            if(i-coins[j]>=0){
                if (dp[i-coins[j]] != INT_MAX && dp[i-coins[j]]+1 <dp[i])
                dp[i] = dp[i-coins[j]] + 1;
            }            
        }
    }
    for(int i=0;i<=target;i++){
        cout<<dp[i]<<" ";  
    }
    //cout<<"\n";
    cout<<"\n";
    if(dp[target]==INT_MAX){
        cout<<"NOT POSSIBLE\n";
    }
    else{
        cout<<"POSSIBLE\n";
        cout<<"Minimum no. of coins required: "<<dp[target]<<"\n";
    }
    
}