#include<iostream>

using namespace std;

int main(){
    string str, pattern;
    cin>>str>>pattern;

    bool dp[pattern.length()+1][str.length()+1];

    for(int i=0; i<=pattern.length(); i++){
        for(int j=0; j<=str.length(); j++){
            if(i==0 && j==0){
                dp[i][j] = true;
            }else if(i==0){
                dp[i][j] = false;
            }else if(j==0){
                char ch = pattern[i-1];
                if(ch == '*'){
                    dp[i][j] = dp[i-2][j];
                }else{
                    dp[i][j] = false;
                }
            }else{
                char ch = pattern[i-1];
                char ch2 = pattern[i-2];
                char s = str[j-1];

                if(ch == '*'){
                    dp[i][j] = dp[i-2][j];
                    if(ch2 == s || ch2 == '.'){ //IMP
                        dp[i][j] = dp[i][j] | dp[i][j-1];
                    }
                }else if(ch == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }else if(ch == s){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = false;
                }
            }
        }
    }

    cout<<dp[pattern.length()][str.length()];

    return 0;
}