//Finite supply
#include<iostream>
#include<vector>

using namespace std;

void coinChange(int cs, int target, int idx, vector<int> &arr,string asf){
    if(idx == arr.size()){
        if(cs == target){
            cout<<asf<<"\n";
        }

        return;
    }
    coinChange(cs + arr[idx], target, idx+1, arr, asf + to_string(arr[idx]) + "-");
    coinChange(cs, target, idx+1, arr, asf);
}

int main(){

    int target;
    cin>>target;

    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    coinChange(0, target, 0, arr,"");

    return 0;
}