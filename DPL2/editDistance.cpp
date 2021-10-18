#include<bits/stdc++.h>

using namespace std;

int main(){

    string s1,s2;

    cin>>s1>>s2;

    int dp[s1.length()+1][s2.length()+1];

    for(int i=0; i<=s1.length(); i++){
        for(int j=0; j<=s2.length(); j++){
            if(i==0 && j==0){
                dp[i][j] = 0;
            }else if(i==0){
                dp[i][j] = j;
            }else if(j==0){
                dp[i][j] = i;
            }else{
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
                }
            }
        }
    }

    cout<<dp[s1.length()][s2.length()];

    return 0;
}