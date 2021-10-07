#include<bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin>>str;

    int dp[str.length()+1][str.length()+1];
    for(int i=str.length(); i>=0; i--){
        for(int j=str.length(); j>=0; j--){
            if(i==str.length() || j==str.length()){
                dp[i][j] = 0;
            }else{
                char s1 = str[i];
                char s2 = str[j];

                if(s1 == s2 && i != j){
                    dp[i][j] = dp[i+1][j+1]+1;
                }else{
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
    }

    cout<<dp[0][0];
    return 0;
}