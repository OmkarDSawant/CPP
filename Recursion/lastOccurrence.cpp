#include<iostream>

using namespace std;

int lastOccurrence(int arr[], int i, int &n, int &val){
    if(i==n){
        return -1;
    }

    int iisa = lastOccurrence(arr,i+1,n,val); //index in smaller array

    if(iisa!=-1){
        return iisa;
    }else{
        if(arr[i]==val){
            return i;
        }else{
            return -1;
        }
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

    cout<<lastOccurrence(arr,0,n,val);
}