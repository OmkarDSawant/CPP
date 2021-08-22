#include<iostream>

using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int minB = arr[0];
    int dpl[n] = {0}; //Stores maximum profit till i.

    //Max profit uptil now if today was the selling day.
    for(int i=1; i<n; i++){
        if(arr[i] < minB){
            minB = arr[i];
        }

        if(dpl[i-1] > arr[i] - minB){
            dpl[i] = dpl[i-1];
        }else{
            dpl[i] = arr[i] - minB;  
        }
    }

    int maxR = arr[n-1];
    int dpr[n] = {0};

    //Max profit uptil now if today was the buying day.
    for(int i=n-2; i>=0; i--){
        if(arr[i] > maxR){
            maxR = arr[i];
        }

        if(dpr[i+1] > maxR - arr[i]){
            dpr[i] = dpr[i+1];
        }else{
            dpr[i] = maxR - arr[i]; 
        }
    }

    int op = 0; //Overall profit.

    for(int i=0; i<n; i++){
        if(op < dpl[i] + dpr[i]){
            op = dpl[i] + dpr[i];
        }
    }

    cout<<op;

    return 0;
}