#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n+1];

    arr[0] = 0;

    for(int i=1; i<n+1; i++){
        cin>>arr[i];
    }

    int dp[n+1];

    dp[0] = 0;
    dp[1] = arr[1];

    //LR method
    for(int i=2; i<n+1; i++){
        dp[i] = arr[i];

        for(int j=1; j<=i/2; j++){ // IMP - Loop only till i/2
            if(dp[j]+dp[i-j]>dp[i]){
                dp[i] = dp[j] + dp[i-j];
            }
        }
    }

    cout<<dp[n];

    return 0;
}