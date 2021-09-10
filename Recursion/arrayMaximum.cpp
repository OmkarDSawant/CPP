#include<iostream>

using namespace std;

int maxArray(int arr[], int i, int &n){
    if(i==n-1){
        return arr[i];
    }

    int missa = maxArray(arr,i+1,n);
    return arr[i] > missa ? arr[i] : missa;

}

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<maxArray(arr,0,n);

    return 0;
}