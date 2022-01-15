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

    //0 to j-1 : 0
    //j to i-1 : 1
    //i to e : Unknown 

    int i = 0;
    int j = 0;
    
    while(i<=n){

        if(arr[i]==0){
            swap(arr,j,i);
            i++;
            j++;
        }else{
            i++;
        }
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}