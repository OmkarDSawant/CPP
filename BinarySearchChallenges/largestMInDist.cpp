#include<iostream>
#include<algorithm>

using namespace std;

bool isFeasible(int mid, int arr[], int n, int k){
    int pos = arr[0];
    int element = 1; 

    for(int i=0; i<n; i++){
        if(arr[i]-pos>=mid){
            pos = arr[i];
            element++;

            if(element == k){
                return true;
            }
        }
    }
    return false;
}

int largestMinDist(int arr[], int n, int k){
    sort(arr,arr+n);

    int left = arr[0];
    int right = arr[n-1];
    int result = -1;

    while(left < right){
        int mid = (left+right)/2;

        if(isFeasible(mid, arr, n, k)){
            result = max(result,mid);
            left = mid+1;
        }else{
            right = mid;
        }
    }

    return result;
}

int main(){

    int arr[] = {1,2,8,4,9};
    int n = 5;
    int k = 3;

    cout<<largestMinDist(arr,n,k);
    return 0;
}