#include<iostream>

using namespace std;

int main(){
    string str, pattern;
    cin>>str>>pattern;

    int plen = pattern.length()+1; //extra 1 for blank
    int slen = str.length()+1; //extra 1 for blank

    bool dp[plen][slen];

    for(int i=plen-1; i>=0; i--){
        for(int j=slen-1; j>=0; j--){
            if(i==plen-1 && j==slen-1){ //last cell
                dp[i][j] = true;
            }else if(i==plen-1){ //last row
                dp[i][j] = false;
            }else if(j==slen-1){ //last column
                char p = pattern[i];
                if(p == '*'){
                    dp[i][j] = dp[i+1][j];
                }else{
                    dp[i][j] = false;
                }
            }else{
                char p = pattern[i];
                char s = str[j];

                if(p=='*'){
                    dp[i][j] = dp[i][j+1] || dp[i+1][j];
                }else if(p=='?'){
                    dp[i][j] = dp[i+1][j+1];
                }else if(p==s){
                    dp[i][j] = dp[i+1][j+1];
                }else{
                    dp[i][j] = false;
                }
            }
        }
    }

    cout<<dp[0][0];
    
    return 0;
}