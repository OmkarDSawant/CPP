#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int amount;
    cin>>amount;

    int dp[amount+1] = {0};

    dp[0] = 1;

    for(int i=0; i<n; i++){ //Selecting Coin. 
        for(int j=arr[i]; j<amount+1; j++){
            dp[j] += dp[j-arr[i]];
        }
    }

    cout<<dp[amount];
    return 0;
}