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
            int maxi = INT_MIN;
            for(int k=i; k<=j; k++){

                int left = k==i?0:dp[i][k-1];
                int right = k==j?0:dp[k+1][j];
                int val = (i == 0? 1: arr[i-1]) * arr[k] * (j == n-1? 1: arr[j+1]);

                if(left+right+val>maxi){
                    maxi = left+right+val;
                }
            }
            dp[i][j] = maxi;
        }
    }

    cout<<dp[0][n-1];

    return 0;
}