#include<iostream>

using namespace std;

int firstOccurrence(int arr[], int i, int &n, int &val){

    if(i==n){
        return -1;
    }
    if(arr[i]==val){
        return i;
    }else{
        return firstOccurrence(arr, i+1, n, val);
    }

}

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int val;
    cin>>val;

    cout<<firstOccurrence(arr, 0, n, val);

    return 0;
}