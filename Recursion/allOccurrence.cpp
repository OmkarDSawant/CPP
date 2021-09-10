#include<iostream>

using namespace std;

int gsize;

int* allOccurrence(int arr[], int i, int &n, int &val, int size){
    if(i==n){
        gsize = size;
        return new int[size];
    }

    if(arr[i]==val){
        int *iarr = allOccurrence(arr,i+1,n,val,size+1);
        iarr[size] = i;
        return iarr;
    }else{
        int *iarr = allOccurrence(arr,i+1,n,val,size);
        return iarr;
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

    int *occurrArray = allOccurrence(arr,0,n,val,0);

    for(int i=0; i<gsize; i++){
        cout<<occurrArray[i]<<" ";
    }

    return 0;
}