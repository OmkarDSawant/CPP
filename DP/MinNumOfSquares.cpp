#include<iostream>
#include<vector>

using namespace std;

const int MOD = 1e9;
/* Memoization
int MinSquare(int n, vector<int> &dp){
    if(n==0 || n==1 || n==2 || n==3) //For these values we never look the lookup table.
        return n;

    if(dp[n]!=MOD)
        return dp[n];

    for(int i=1; i*i<=n; i++){
        dp[n] = min(dp[n], 1+ MinSquare(n-i*i, dp)); // 1 here denotes that i number is considered
    }

    return dp[n];
}

int main(){
    int n; cin>>n;

    vector<int> dp(n+1,MOD);

    cout<<MinSquare(n,dp);
    return 0;
}
*/

int main(){

    int n; cin>>n;
    vector<int> dp(n+1, MOD);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;

    for(int i=1; i*i<=n; i++){
        for(int j=0; i*i+j<=n; j++){
            dp[i*i + j] = min(dp[i*i + j], 1+dp[j]);
        }
    }

    cout<<dp[n];

    return 0;
}