#include<iostream>

using namespace std;

int firstoccur(int arr[], int size, int key, int index){
    if(index==size)
        return -1;

    if(arr[index]==key){
        return index;
    }

    return firstoccur(arr,size,key,index+1);
}
int lastoccur(int arr[], int size, int key, int index){
    if(index==size)
        return -1;

    int restArray = lastoccur(arr,size,key,index+1);
    if(restArray!=-1){
        return restArray;
    }

    if(arr[index]==key){
        return index;
    }
    return -1;
}

int main(){
    int arr[]={1,2,4,2,5,6,2,7,9};
    cout<<firstoccur(arr,8,2,0);//array,size,key,index
    cout<<endl;
    cout<<lastoccur(arr,8,2,0);
    return 0;
}