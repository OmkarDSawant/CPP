#include<iostream>

using namespace std;

void printArray(int arr[], int i, int &n){
    if(i==n){
        return;
    }

    cout<<arr[i]<<" ";
    printArray(arr,i+1,n);
}

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    printArray(arr,0,n);

    return 0;
}