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

void quickSort(int *arr, int lo, int hi){

    if(lo>=hi){
        return;
    }

    int pivot = arr[hi];

    int pi = partitionAnArray(arr, lo, hi);

    quickSort(arr, lo, pi-1);
    quickSort(arr, pi+1, hi);

}

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}