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
        for(int i=0, j=g; j<n; i++,j++){
            if(g==0){
                dp[i][j] = arr[i];
            }else if(g==1){
                dp[i][j] = max(arr[i],arr[j]);
            }else{
                int val1 = arr[i] + min(dp[i+2][j],dp[i+1][j-1]);
                int val2 = arr[j] + min(dp[i][j-2],dp[i+1][j-1]);

                int maxVal = max(val1,val2);
                dp[i][j] = maxVal;
            }
        }
    }

    cout<<dp[0][n-1];

    return 0;
}