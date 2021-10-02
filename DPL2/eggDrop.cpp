#include<bits/stdc++.h>

using namespace std;

int main(){
    int e,f; //eggs,floors
    cin>>e>>f;

    vector<vector<int>> dp(e+1, vector<int>(f+1,0));

    for(int i=1; i<=e; i++){
        for(int j=1; j<=f; j++){
            if(j==1){
                dp[i][j] = 1;
            }else if(i==1){
                dp[i][j] = j;
            }else{
                int minVal = INT_MAX;

                for(int mj=j-1, pj=0; mj>=0; mj--, pj++){
                    int val1 = dp[i][mj]; //egg survives
                    int val2 = dp[i-1][pj]; //egg breaks

                    int maxVal = max(val1,val2);

                    minVal = min(maxVal, minVal);

                    dp[i][j] = minVal + 1;
                }
            }
        }
    }

    
    cout<<dp[e][f];

    return 0;
}