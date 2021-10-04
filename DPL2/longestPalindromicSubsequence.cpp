#include<bits/stdc++.h>

using namespace std;

int main(){
    string s1;
    cin>>s1;

    int dp[s1.length()][s1.length()];

    for(int g=0; g<s1.length(); g++){
        for(int i=0, j=g; i<s1.length(); i++, j++){
            if(g==0){
                dp[i][j] = 1;
            }else if(g==1){
                dp[i][j] = s1[i]==s1[j]?2:1;
            }else{
                if(s1[i]==s1[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }else{
                    dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
                }
            }
        }
    }

    cout<<dp[0][s1.length()-1];
    return 0;
}