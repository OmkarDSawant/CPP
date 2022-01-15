#include<iostream>

using namespace std;

void swap(int *arr, int j, int i){
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int i=0;
    int j=0;
    int k=n-1;

    while(i<=k){
        if(arr[i]==0){
            swap(arr,j,i);
            i++;
            j++;
        }else if(arr[i]==1){
            i++;
        }else{
            swap(arr,i,k);
            k--;
        }
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}