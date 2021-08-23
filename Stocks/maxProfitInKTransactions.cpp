#include<bits/stdc++.h>

using namespace std;

int main(){

    int n; //Number of share prices
    cin>>n;

    int prices[n];

    for(int i=0; i<n; i++){
        cin>>prices[i];
    }

    int k; //Number of Non overlapping transactions
    cin>>k;

    vector<vector<int>> dp(k+1, vector<int>(n,0));

    for(int t=1; t<k+1; t++){

        int maxi = INT_MIN; //This reduces time complexity by order of n. Making it O(n^2).

        for(int d=1; d<n; d++){
            maxi = max(dp[t-1][d-1] - prices[d-1], maxi);

            if(maxi + prices[d] > dp[t][d-1]){
                dp[t][d] = maxi + prices[d];
            }else{
                dp[t][d] = dp[t][d-1];
            }
        }
    }
    
    cout<<dp[k][n-1];

    return 0;
}