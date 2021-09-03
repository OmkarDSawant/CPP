//Either the entire item will be inlcluded else not.

#include<iostream>

using namespace std;

int main(){

    int n; cin>>n;

    int vals[n];

    for(int i=0; i<n; i++){
        cin>>vals[i];
    }

    int weights[n];

    for(int i=0; i<n; i++){
        cin>>weights[i];
    }

    int cap;
    cin>>cap;
    int dp[n+1][cap+1] = {0};

    for(int i=1; i<n+1; i++){
        for(int j=1; j<cap+1; j++){
            if(weights[i-1]<=j){
                if(dp[i-1][j] < dp[i-1][j-weights[i-1]] + vals[i-1]){
                    dp[i][j] = dp[i-1][j-weights[i-1]] + vals[i-1]; //If the current item is not included then max val is previous val.
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout<<dp[n][cap];

    return 0;
}