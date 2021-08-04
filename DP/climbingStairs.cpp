#include<iostream>
#include<vector>

using namespace std;

/*Memoization
int countPath(int n, vector<int> &dp){
    if(n==0){ //Valid path found
        return 1;
    }else if(n<0){ //Invalid path
        return 0;
    }

    if(dp[n]>0){
        return dp[n];
    }

    return dp[n] = countPath(n-1,dp) + countPath(n-2,dp) + countPath(n-3,dp);
}

int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1, 0);

    cout<<countPath(n,dp);

    return 0;
}
*/

// Tabulation

int main(){
    int n;
    cin>>n;

    vector<int> dp(n+1, 0);

    dp[0] = 1;
    
    for(int i=1; i<=n; i++){
        if(i-1 == 0){
            dp[i] = dp[i-1];
        }else if(i-2 == 0){
            dp[i] = dp[i-1] + dp[i-2];
        }else{
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
    }

    cout<<dp[n];
    return 0;
}