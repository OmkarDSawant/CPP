#include<iostream>
#include<vector>

using namespace std;

void countS(int *arr, int range, int n, int div, int mod){

    vector<int> farr(range,0);

    for(int i=0; i<n; i++){
        farr[ (arr[i]/div)%mod ]++;
    }

    //Prefix sum array
    for(int i=1; i<range; i++){
        farr[i] += farr[i-1];
    }


    int res[n];

    //Step to ensure stable sorting
    for(int i=n-1; i>=0; i--){
        int val = arr[i];
        int idx = farr[(arr[i]/div)%mod];
        res[idx-1] = val;
        farr[(arr[i]/div)%mod]--;
    }

    for(int i=0; i<n; i++){
        arr[i] = res[i];
    }
}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    countS(arr,32,n,1000000,1); //days
    countS(arr,13,n,10000,100); //months
    countS(arr,2501,n,1,10000); //years

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}