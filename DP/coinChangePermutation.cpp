#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int coins[n];

    for(int i=0; i<n; i++){
        cin>>coins[i];
    }

    int amount;
    cin>>amount;

    int dp[amount+1] = {0};

    dp[0] = 1;

    for(int i=1; i<amount+1; i++){
        for(int j=0; j<n; j++){//Selecting all coins for each amount
            if(coins[j]<=i){
                dp[i] += dp[i-coins[j]];
            }
        }
    }

    cout<<dp[amount];
    return 0;
}