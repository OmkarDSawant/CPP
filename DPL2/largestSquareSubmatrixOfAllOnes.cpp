#include<iostream>

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

    int dp[n][m];

    int max = 1;

    for(int j=m-1; j>=0; j--){
        for(int i=n-1; i>=0; i--){
            if(i==n-1 && j==m-1){
                dp[i][j] = arr[i][j];
            }else if(j==m-1){
                dp[i][j] = arr[i][j];
            }else if(i==n-1){
                dp[i][j] = arr[i][j];
            }else{
                if(dp[i][j] == 0){
                    dp[i][j] = 0;
                }else{
                    if(i==0){
                        dp[i][j] = min(dp[i][j+1],dp[i+1][j+1]) + 1;
                    }else{
                        dp[i][j] = min(dp[i+1][j],min(dp[i][j+1],dp[i+1][j+1])) + 1;
                    }
                }
            }

            if(dp[i][j]>max){
                max = dp[i][j];
            }
        }
    }
    
    cout<<max;

    return 0;
}