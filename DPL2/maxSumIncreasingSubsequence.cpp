#include<iostream>
#include<algorithm>

using namespace std;

int main(){

    int n; cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int dp[n];
    int omax = arr[0];
    dp[0] = arr[0];

    for(int i=1; i<n; i++){

        int tempMax = 0;

        for(int j=0; j<i; j++){

            if(arr[j]<=arr[i]){
                tempMax = max(tempMax, dp[j]);
            }
        }
        dp[i] = tempMax + arr[i];
        omax = max(omax,dp[i]);
    }

    cout<<omax;

    return 0;
}