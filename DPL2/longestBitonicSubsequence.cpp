#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int n; cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int lis[n];
    lis[0] = 1;

    for(int i=1; i<n; i++){

        int tempMax = 0;

        for(int j=0; j<i; j++){

            if(arr[j]<=arr[i]){
                tempMax = max(tempMax, lis[j]);
            }
        }
        lis[i] = tempMax + 1;
    }

    int lds[n];
    lds[n-1] = 1;

    for(int i=n-2; i>=0; i--){

        int tempMax = 0;

        for(int j=n-1; j>i; j--){

            if(arr[i]>=arr[j]){
                tempMax = max(tempMax, lds[j]);
            }
        }
        lds[i] = tempMax + 1;
    }

    int omax = 0;
    for(int i=0; i<n; i++){
        if(lis[i]+lds[i]-1>omax){
            omax = lis[i]+lds[i]-1;
        }
    }

    cout<<omax;

    return 0;
}