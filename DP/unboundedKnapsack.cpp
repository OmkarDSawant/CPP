//Same as 01 knapsack but with infinite supply.

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

    int dp[cap+1] = {0};

    dp[0] = 0; //bag with 0 weight will have 0 value.

    for(int i=0; i<n; i++){ //Solving by combination.
        for(int j=weights[i]; j<cap+1; j++){
            if(dp[j]<dp[j-weights[i]]+vals[i]){
                dp[j] = dp[j-weights[i]] + vals[i];
            }
        }
    }

    cout<<dp[cap];
    return 0;
}