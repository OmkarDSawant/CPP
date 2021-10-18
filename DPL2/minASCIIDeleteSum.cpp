#include<bits/stdc++.h>

using namespace std;

int main(){

    string s1,s2;

    cin>>s1>>s2;

    int dp[s1.length()+1][s2.length()+1];

    for(int i = s1.length(); i>=0; i--){
        for(int j = s2.length(); j>=0; j--){
            if(i == s1.length() && j==s2.length()){
                dp[i][j] = 0;
            }else if(i==s1.length()){
                dp[i][j] = dp[i][j+1] + (int)s2[j];
            }else if(j==s2.length()){
                dp[i][j] = dp[i+1][j] + (int)s1[i];
            }else{
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }else{
                    dp[i][j] = min( dp[i][j+1] + (int)s2[j], dp[i+1][j] + (int)s1[i] );
                }
            }
        }
    }

    cout<<dp[0][0];

    return 0;
}