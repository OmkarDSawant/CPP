//Climbing stairs with variable paths.
#include<bits/stdc++.h>

using namespace std;

const int NULLL = 1e5+3; //Denotes that it is NULL;
//Tabulation
int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> dp(n+1, NULLL);

    dp[n] = 0; //Note: Number moves from last pos to itself is 0. Number of paths is 1.

    for(int i=n-1; i>=0; i--){
        int mini;
        if(arr[i]>0){
            mini = INT_MAX;
            for(int j=1; j<=arr[i] && i+j < n+1; j++){
                if(dp[i+j] != NULLL)
                    mini = min(mini,dp[i+j]);
            }
        }    

        if(mini != INT_MAX){
            dp[i] = mini + 1; //1 denotes its own move.
        }
    }

    cout<<dp[0];
    return 0;
}