#include<iostream>
#include<vector>

using namespace std;

int rec(int *stones, int *psa, int i, int j, vector<vector<int>> &memo){

    if(i>=j) return memo[i][j] = 0;

    if(i+1 == j){
        return memo[i][j] =  max(stones[i], stones[j]);
    }

    if(memo[i][j] != -1) return memo[i][j];

    int scoreI = psa[j] - psa[i] - rec(stones, psa, i+1, j, memo);
    int scoreJ = psa[j-1] - (i==0 ? 0 : psa[i-1]) - rec(stones, psa, i, j-1, memo);

    return memo[i][j] = max(scoreI, scoreJ);
}

int tab(int *stones, int * psa, int n){

    int dp[n][n];

    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            if(i>=j){
                dp[i][j] = 0;
            }else if(i+1 == j){
                dp[i][j] = max(stones[i], stones[j]);
            }else{
                int scoreI = psa[j] - psa[i] - dp[i+1][j];
                int scoreJ = psa[j-1] - (i==0 ? 0 : psa[i-1]) - dp[i][j-1];

                dp[i][j] = max(scoreI, scoreJ);
            }     
        }
    }

    return dp[0][n-1];
}

int main(){
    int n;
    cin>>n;

    int stones[n];

    for(int i=0; i<n; i++){
        cin>>stones[i];
    }

    int psa[n];

    psa[0] = stones[0];

    for(int i=1; i<n; i++){
        psa[i] = psa[i-1] + stones[i];
    }

    vector<vector<int>> memo(n, vector<int>(n,-1));
    cout<<rec(stones, psa, 0, n-1, memo)<<"\n";

    cout<<tab(stones, psa, n);

    return 0;
}