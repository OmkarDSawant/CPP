#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    int dp[n+1];

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<n+1; i++){
        int mini = INT_MAX;
        for(int j=1; j*j<=i; j++){
            mini = min(mini, dp[i-j*j]);
        }

        dp[i] = mini + 1;
    }

    cout<<dp[n];
    
    return 0;
}