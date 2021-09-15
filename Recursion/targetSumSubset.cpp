#include<bits/stdc++.h>

using namespace std;

int n;

void TSS(int *arr, int idx, int &target, string path, int sum){
    if(idx==n){
        if(sum==target){
            cout<<path + ".\n";
        }
        return;
    }
    
    TSS(arr,idx+1,target,path+to_string(arr[idx])+", ",sum+arr[idx]);
    TSS(arr,idx+1,target,path,sum);

}

int main(){
    
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int target;
    cin>>target;

    TSS(arr,0,target,"",0);

    return 0;
}