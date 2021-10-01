#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    int search[n];
    for(int i=0; i<n; i++){
        cin>>search[i];
    }

    int psa[n]; //IMP
    psa[0] =  search[0];
    for(int i=1; i<n; i++){
        psa[i] = search[i] + psa[i-1];
    }

    int dp[n][n];

    for(int g=0; g<n; g++){
        for(int i=0, j=g; j<n; i++, j++){
            if(g==0){
                dp[i][j] = search[i];
            }else if(g==1){
                dp[i][j] = min(search[i] + 2*search[j], search[j] + 2*search[i]);
            }else{
                int mini = INT_MAX;

                for(int k=i; k<=j; k++){
                    int val = psa[j] - (i==0? 0: psa[i-1]); //IMP
                    int lt = k==i? 0: dp[i][k-1];
                    int rt = k==j? 0: dp[k+1][j];

                    if(val+lt+rt<mini){
                        mini = val+lt+rt;
                    }
                }
                dp[i][j] = mini;
            }
        }
    }

    cout<<dp[0][n-1];

    return 0;
}