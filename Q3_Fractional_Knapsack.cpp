#include <bits/stdc++.h>
using namespace std;

// INPUT_FORMAT
// n CAPACITY
// array of WEIGHTS size n
// array of corresponding VALUES size n

//3 50
//10 20 30
//60 100 120


int main(){
    int n,capacity;cin>>n>>capacity;
    
    vector<int>weight(n);
    vector<int>value(n);
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    vector<pair<int,int>>arr(n);
    for(int i=0;i<n;i++){
        arr[i]={weight[i],value[i]};
    }
    sort(arr.begin(),arr.end(),[] (pair<int,int>a,pair<int,int>b){
        double x=(double)a.second/double(a.first);
        double y=(double)b.second/double(b.first);
        return x>y;
    });
    double total_value=0;
    for(int i=0;i<n;i++){
        if(capacity-arr[i].first>=0){
            capacity=capacity-arr[i].first;
            total_value+=arr[i].second;
        }
        else{
            total_value+=(arr[i].second)*((double)capacity/double(arr[i].first));
            break;
        }
    }
    cout<<"Maximum Obtainable Value is -->"<<total_value<<"\n";
    
    
}