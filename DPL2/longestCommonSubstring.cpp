#include<bits/stdc++.h>

using namespace std;

int main(){

    string str1, str2;
    cin>>str1>>str2;

    int dp[str1.length()+1][str2.length()+1];

    int maxi = INT_MIN;

    for(int i=0; i<=str1.length(); i++){
        for(int j=0; j<=str2.length(); j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }else{
                char s1 = str1[i-1];
                char s2 = str2[j-1];

                if(s1 == s2){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = 0;
                }
            }

            if(dp[i][j]>maxi){
                maxi = dp[i][j];
            }
        }
    }

     cout<<maxi;

    return 0;
}