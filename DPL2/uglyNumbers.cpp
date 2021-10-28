#include<iostream>

using namespace std;

int main(){

    int n;
    cin>>n;

    int dp[n+1];
    dp[1] = 1;

    int p2 = 1;
    int p3 = 1;
    int p5 = 1;

    for(int i=2; i<=n; i++){
        dp[i] = min(2 * dp[p2], min(3 * dp[p3], 5 * dp[p5]));

        if(dp[i] == 2 * dp[p2]){
            p2++;
        }
        if(dp[i] == 3 * dp[p3]){
            p3++;
        }
        if(dp[i] == 5 * dp[p5]){
            p5++;
        }
    }

    for(int i=1; i<=n; i++){
        cout<<dp[i]<<" ";
    }

    return 0;
}