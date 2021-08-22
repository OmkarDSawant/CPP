#include<iostream>

using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int obsp = -arr[0];
    int ossp = 0;
    int ocsp = 0;

    int nbsp,nssp,ncsp;

    for(int i=1; i<n; i++){
        if(obsp > ocsp - arr[i]){
            nbsp = obsp;
        }else{
            nbsp = ocsp - arr[i];
        }

        if(ossp > obsp + arr[i]){
            nssp = ossp;
        }else{
            nssp = obsp + arr[i];
        }

        if(ocsp > ossp){
            ncsp = ocsp; 
        }else{
            ncsp = ossp;
        }

        obsp = nbsp;
        ossp = nssp;
        ocsp = ncsp;
    }

    cout<<ossp;

    return 0;
}