#include<iostream>
#include<vector>

using namespace std;

void coinChange(int cs, int idx, int target, vector<int> &arr, string asf){

    if( idx == arr.size() ){
        if(cs == target){
            cout<<asf<<"\n";
        }
        return;
    }
 
    for(int i= target/arr[idx]; i>=1; i--){
        string part = "";
        for(int j=0; j<i; j++){
            part+= to_string(arr[idx]) + "-";
        }

        coinChange(cs + (arr[idx]*i), idx + 1, target, arr, asf+part);
    }

    coinChange(cs, idx + 1, target, arr, asf);
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

    coinChange(0, 0, target, arr, "");

    return 0;
}