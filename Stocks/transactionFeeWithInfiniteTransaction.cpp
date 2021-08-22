#include<iostream>

using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int fee; //Transaction fee on each sell.
    cin>>fee;

    int obsp = -arr[0]; //Old Buy State Profit
    int ossp = 0; //Old Sell State Profit

    int nbsp, nssp;

    for(int i=1; i<n; i++){
        if(obsp> ossp - arr[i]){
            nbsp = obsp;
        }else{
            nbsp = ossp - arr[i];
        }

        if(ossp > obsp + arr[i] - fee){
            nssp = ossp;
        }else{
            nssp = obsp + arr[i] - fee;
        }

        obsp = nbsp;
        ossp = nssp;
    }

    cout<<nssp;

    return 0;
}