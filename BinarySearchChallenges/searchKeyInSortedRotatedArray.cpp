//Search key in sorted rotated array using time less than linear search.

#include<iostream>

using namespace std;

//returns index
int searchInRotatedArray(int arr[], int key, int left, int right){
    if(left>right){
        return -1;
    }

    int mid = (left+right)/2;
    if(key == arr[mid]){
        return mid;
    }

    if(arr[left] <= arr[mid]){ // if true - this indicates elements to the left of mid are smaller.
        if(key >= arr[left] && key<= arr[mid]){
            return searchInRotatedArray(arr,key,left,mid-1);
        }
        return searchInRotatedArray(arr,key,mid+1,right);
    }

    // elements to the right of mid are greater. 
    if(key >= arr[mid] && key <= arr[right]){
        return searchInRotatedArray(arr, key, mid+1, right);
    }
    return searchInRotatedArray(arr, key, mid-1, left);
}

int main(){
    int arr[]={5,6,7,8,9,10,1,2,3};
    int key = 10;
    int n = 9;
    cout<<searchInRotatedArray(arr,key,0,n-1);
    return 0;
}