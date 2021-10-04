#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int dp[n][n];

    for(int g=0; g<n; g++){
        for(int i=0, j=g; j<n; i++, j++){
            if(g==0 || g==1){
                dp[i][j] = 0;
            }else if(g==2){
                dp[i][j] = arr[i] * arr[i+1] * arr[j];
            }else{
                int mini = INT_MAX;
                for(int k=i+1; k<=j; k++){
                    int lt = dp[i][k];
                    int rt = dp[k][j];
                    int val = arr[i] * arr[k] * arr[j];

                    mini = min(lt+rt+val, mini);
                }
                dp[i][j] = mini;
            }
        }
    }

    cout<<dp[0][n-1];

    return 0;
}