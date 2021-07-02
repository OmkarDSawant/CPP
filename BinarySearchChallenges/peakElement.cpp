#include<iostream>

using namespace std;

int findPeakElement(int arr[], int n, int low, int high){
    int mid = (low+high)/2;

    if( (mid==0 || arr[mid]>arr[mid-1]) && (mid==n-1 || arr[mid]>arr[mid+1]) ){
        return mid;
    }
    else if(mid>0 && arr[mid-1]>arr[mid]){
        return findPeakElement(arr, n, low, mid-1);
    }
    else{
        return findPeakElement(arr, n, mid+1, high);
    }

}

int main(){
    int arr[] = {1,2,3,4,7,5,6,8};
    int n = 8;
    cout<<"Index of peak element is: "<<findPeakElement(arr,n,0,n-1);
    return 0;
}