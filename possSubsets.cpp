#include<iostream>

using namespace std;

void possSubset(int arr[],int a, int b){
    
    for(int i=0;i<(1<<a);i++){
        for(int j=0;j<b;j++){
            if(i&(1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<"\n";
    }
}

int main(){
    int a,b; //power,setlength;
    cin>>a>>b;
    int arr[]={1,2,3,4};
    possSubset(arr,a,b);
    return 0;
}