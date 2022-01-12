#include<iostream>

using namespace std;

int partitionAnArray(int *arr, int lo, int hi){

    int pivot = arr[hi];

    int i=0;
    int j=0;

    while(i<=hi){
        if(arr[i]>pivot){
            i++;
        }else{
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
            j++; 
        }
    }

    return j-1;

}

int quickSelect(int *arr, int lo, int hi, int k){

    int pi = partitionAnArray(arr, lo, hi);

    if(k>pi){
        return quickSelect(arr, pi+1, hi, k);
    }else if(k<pi){
        return quickSelect(arr, lo, pi-1, k);
    }else{
        return arr[pi];
    }

}

int main(){
    int n;
    cin>>n;

    int k;
    cin>>k;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<quickSelect(arr, 0, n-1, k-1);

    return 0;
}