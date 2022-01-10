#include<iostream>

using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    for(int i = 0; i < n-1; i++){
        int mi = i;

        for(int j = i+1; j <= n-1; j++){
            if(arr[i]>arr[j]){
                mi = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[mi];
        arr[mi] = temp;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}