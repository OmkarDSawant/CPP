//Find the number of ways to arrange MX1 tiles in MXN floor

#include<iostream>

using namespace std;

int main(){  
    int n; cin>>n;
    int m; cin>>m;

    int dp[n+1];

    for(int i=1; i<=n; i++){
        if(i<m){
            dp[i] = 1;
        }else if(i == m){
            dp[i] = 2;
        }else{
            dp[i] = dp[i-1] + dp[i-m];
        }
    }

    cout<<dp[n];

    return 0;
}
