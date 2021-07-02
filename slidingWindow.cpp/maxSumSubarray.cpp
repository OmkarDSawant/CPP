#include<iostream>

using namespace std;

int maxSum(int arr[], int n, int k, int x){
    int res = 0;

    for(int i=0; i<k; i++){
        res+=arr[i];
    }
    int sum = res;

    for(int j=k; j<n; j++){
        sum += arr[j] - arr[j-k];
        if(sum < x){
            res = max(sum,res);
        }
    }

    return res;
}

int main(){
    int arr[] = {7, 5, 4, 6, 8, 9};
    int k = 3;
    int x = 20;
    int n = 6;

    cout<<maxSum(arr, n, k, x);
    return 0;
}