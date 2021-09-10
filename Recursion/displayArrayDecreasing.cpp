#include<iostream>

using namespace std;

void printArrayD(int arr[], int i, int &n){
    if(i==n){
        return;
    }

    printArrayD(arr,i+1,n);
    cout<<arr[i]<<" ";
}

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    printArrayD(arr,0,n);

    return 0;
}