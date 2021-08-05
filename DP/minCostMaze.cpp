#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int arr[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m));

    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            if(i==n-1 && j==m-1){ //last cell
                dp[i][j] = arr[i][j];
            }else if(i == n-1){ //last row
                dp[i][j] = dp[i][j+1] + arr[i][j];
            }else if(j == m-1){ //last col
                dp[i][j] = dp[i+1][j] + arr[i][j];
            }else{
                dp[i][j] = min(dp[i+1][j], dp[i][j+1]) + arr[i][j];
            }
        }
    }

    cout<<dp[0][0];
    return 0;
}