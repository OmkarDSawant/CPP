#include<iostream>
#include<vector>

using namespace std;


void countS(int *arr, int mini, int maxi, int n, int exp){

    int range = maxi-mini+1;
    vector<int> farr(range,0);

    for(int i=0; i<n; i++){
        farr[ (arr[i]/exp)%10 ]++;
    }

    //Prefix sum array
    for(int i=1; i<range; i++){
        farr[i] += farr[i-1];
    }


    int res[n];

    //Step to ensure stable sorting
    for(int i=n-1; i>=0; i--){
        int val = arr[i];
        int idx = farr[(arr[i]/exp)%10];
        res[idx-1] = val;
        farr[(arr[i]/exp)%10]--;
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

    int maxi = INT_MIN;

    //Maximum value
    for(int i=0; i<n; i++){
        if(maxi<arr[i]){
            maxi = arr[i];
        }
    }

    int exp = 1;
    while(exp<=maxi){
        countS(arr, 0, 9, n, exp);
        exp *= 10; 
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}