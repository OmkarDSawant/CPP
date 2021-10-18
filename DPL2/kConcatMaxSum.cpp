#include<iostream>

using namespace std;

int kadanes(int *arr, int n){
    int csum = arr[0];
    int osum = arr[0];

    for(int i=1; i<n; i++){
        if(csum>0){
            csum += arr[i];
        }else{
            csum = arr[i];
        }

        if(csum>osum){
            osum = csum;
        }
    }

    return osum;
}

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int k;
    cin>>k;

    int sum;
    cin>>sum;

    
    if(k==1){
        cout<<kadanes(arr, n);
    }else{
        int arr2[n * 2];

        for(int i=0; i<n; i++){
            arr2[i] = arr[i];
        }

        for(int i=0; i<n; i++){
            arr2[i+n] = arr[i];
        }
        if(sum>0){
            cout<<kadanes(arr2,n*2) + (k-2) * sum;
        }else{
            cout<<kadanes(arr2,n*2);
        }
    }

    return 0;
}