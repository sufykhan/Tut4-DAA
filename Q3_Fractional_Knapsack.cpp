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
    int n;
    double capacity;
    cout<<"Enter the value of n (Total number of weights):\n";
    cin>>n;
    cout<<"Enter the capacity of the Knapsack:\n ";
    cin>>capacity;
    
    vector<double>weight(n);
    vector<double>value(n);
    
    cout<<"Enter the space separated weight array\n";

    for(int i=0;i<n;i++){
        cin>>weight[i];
    }

    cout<<"Enter the space separated value array for above weights in same sequence\n";

    for(int i=0;i<n;i++){
        cin>>value[i];
    }
    vector<pair<double,double>>arr(n);
    for(int i=0;i<n;i++){
        arr[i]={weight[i],value[i]};
        // double x=value[i]/weight[i];
        // cout<<x<<" ";
    }
    //cout<<"\n";
    sort(arr.begin(),arr.end(),[] (pair<double,double>a,pair<double,double>b){
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