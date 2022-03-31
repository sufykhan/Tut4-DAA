#include <bits/stdc++.h>
using namespace std;

//INPUT FORMAT
// n target
// array of size n 

// 4 11
// 8 3 4 2

int main(){
    int n,target;cin>>n>>target;
    vector<int>coins(n);
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
   
    if(dp[target]==INT_MAX){
        cout<<"NOT POSSIBLE\n";
    }
    else{
        cout<<"POSSIBLE\n";
        cout<<"Minimum no. of coins required: "<<dp[target]<<"\n";
    }
    
}