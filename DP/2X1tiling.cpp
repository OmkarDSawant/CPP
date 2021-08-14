//Find the number of ways to arrange 2X1 tiles in 2XN floor

#include<iostream>

using namespace std;

int main(){
    int n; cin>>n;

    int dp[n+1];

    //Base cases
    dp[1] = 1; //if n = 1 then we have only one way
    dp[2] = 2; //if n = 2 then we have 2 ways. 

    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout<<dp[n];

    return 0;
}