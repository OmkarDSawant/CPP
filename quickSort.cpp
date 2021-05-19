#include<iostream>

using namespace std;

void swap(int arr[], int i, int j){
    int temp= arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int arr[],int l,int r){

    int i=l-1;
    int pivot = arr[r]; //We can choose any element as pivot but it should be same through out. Here last element has been choosen.
    for(int j=l;j<r;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r); //here the pivot element is placed at its correct position.
    return (i+1);
}

void quickSort(int arr[], int l, int r){

    if(l<r){
        int pi = partition(arr,l,r);

        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
    }
}

int main(){
    int arr[]={5,4,3,2,1};
    quickSort(arr,0,4);

    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}