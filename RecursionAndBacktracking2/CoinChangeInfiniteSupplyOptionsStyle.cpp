//Combination style

#include<iostream>
#include<vector>

using namespace std;

void coinChange(int ci, int cs, int target, string asf, vector<int> &arr){

    if(cs>target){
        return;
    }else if(cs == target){
        cout<<asf<<".\n";
        return;
    }

    for(int i = ci; i<arr.size(); i++){
        coinChange(i, cs+arr[i], target, asf + to_string(arr[i]) + "-", arr);
    }
}

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int target;
    cin>>target;

    coinChange(0, 0, target, "", arr);

    return 0;
}