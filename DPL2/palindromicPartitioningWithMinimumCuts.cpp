#include<bits/stdc++.h>

using namespace std;

int main(){

    string str;
    cin>>str;

    bool dp[str.length()][str.length()];

    for(int g=0; g<str.length(); g++){
        for(int i=0, j = g; j<str.length(); i++, j++){
            if(g==0){
                dp[i][j] = true;
            }else if(g==1){
                dp[i][j] = str[i]==str[j];
            }else{
                dp[i][j] = (str[i] == str[j]) && dp[i+1][j-1];
            }
        }
    }

    int strg[str.length()];

    strg[0] = 0;
    
    for(int j=1; j<str.length(); j++){
        if(dp[0][j]){ //IMP
            strg[j]=0;
        }else{
            int min = INT_MAX;
            for(int i=j; i>=1; i--){
                if(dp[i][j]){
                    if(strg[i-1]<min){
                        min = strg[i-1];
                    }
                }
            }
            strg[j] = min + 1;
        }
    }

    cout<<strg[str.length()-1];

    return 0;
}