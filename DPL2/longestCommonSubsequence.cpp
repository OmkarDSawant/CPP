#include<bits/stdc++.h>

using namespace std;

int main(){

    string s1,s2;

    cin>>s1>>s2;

    int n = s1.length()+1;
    int m = s2.length()+1;

    vector<vector<int>> dp(n, vector<int>(m,0));

    for(int i=n-2; i>=0; i--){
        for(int j=m-2; j>=0; j--){
            if(s1[i]==s2[j]){
                dp[i][j] = dp[i+1][j+1] + 1;
            }else{
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    cout<<dp[0][0];

    return 0;
}