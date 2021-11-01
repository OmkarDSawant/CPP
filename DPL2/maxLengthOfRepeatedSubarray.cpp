#include<bits/stdc++.h>

using namespace std;

int main(){
    string s1, s2;
    cin>>s1>>s2;

    vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, 0));

    int maxVal = 0;

    for(int i=1; i<=s1.length(); i++){
        for(int j=1; j<=s2.length(); j++){

            if(s1[i]==s2[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
                maxVal = max(maxVal, dp[i][j]);
            }else{
                dp[i][j] = 0;
            }

        }
    }

    cout<<maxVal;
    return 0;
}