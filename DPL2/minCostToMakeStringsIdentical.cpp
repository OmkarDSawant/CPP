#include<bits/stdc++.h>

using namespace std;

int main(){

    string s1,s2;
    cin>>s1>>s2;

    int c1,c2;
    cin>>c1>>c2;

    int dp[s1.length()+1][s2.length()+1];

    for(int i=s1.length(); i>=0; i--){
        for(int j=s2.length(); j>=0; j--){
            if( i==s1.length() || j==s2.length() ){
                dp[i][j] = 0;
            }else{
                if(s1[i]==s2[j]){
                    dp[i][j] = dp[i+1][j+1] + 1;
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
    }

    cout<<((s1.length() - dp[0][0]) * c1) + ((s2.length() - dp[0][0]) * c2); 
    
}