#include<iostream>
#include<vector>

using namespace std;

//Tabulation
int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> dp(n+1, 0);

    dp[n] = 1; // Possible way to reach last position from last position is 1. By not doing anything.
    for(int i=n-1; i>=0; i--){
        for(int j=1; j<=arr[i] && i+j < n+1; j++){
            dp[i] += dp[i+j];
        }
    }

    cout<<dp[0];

    return 0;
}