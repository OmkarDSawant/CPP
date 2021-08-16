//Number of ways in which N players can be arranged in K teams. Only combinations.

#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n; cin>>n; //Number of players
    int k; cin>>k; //Number of teams
    
    if(n<k || k==0 || n==0){
        cout<<0;
        return 0;
    }

    vector<vector<int>> dp(k+1, vector<int>(n+1,0)); //row - teams and col - players

    for(int i=1; i<=k; i++){ //teams
        for(int j=1; j<=n; j++){ //players
            if(j<i){
                dp[i][j] = 0;
            }else if(j == i){
                dp[i][j] = 1;
            }else{
                dp[i][j] = dp[i][j-1] * i + dp[i-1][j-1];
            }
        }
    }

    cout<<dp[k][n];
    return 0;
}