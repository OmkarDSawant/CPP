#include<iostream>
#include<unordered_map>

using namespace std;

int main(){

    string str;
    cin>>str;

    unordered_map<char,int> mp;
    int prev[str.length()];

    for(int i=0; i<str.length(); i++){
        if(mp.find(str[i]) != mp.end()){
            prev[i] = mp[str[i]];
        }else{
            prev[i] = -1;
        }
        mp[str[i]] = i;
    }

    mp.clear();
    int next[str.length()];

    for(int i=str.length()-1; i>=0; i--){
        if(mp.find(str[i]) != mp.end()){
            next[i] = mp[str[i]];
        }else{
            next[i] = -1;
        }
        mp[str[i]] = i;
    }

    int dp[str.length()][str.length()];

    for(int g=0; g<str.length(); g++){
        for(int i=0, j=g; j<str.length(); i++, j++){
            if(g==0){
                dp[i][j] = 1;
            }else if(g==1){
                dp[i][j] = 2; //IMP
            }else{
                char c1 = str[i];
                char c2 = str[j];

                if(c1!=c2){
                    dp[i][j] = dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1];
                }else{
                    int n = next[i];
                    int p = prev[j];

                    if(n>p){
                        dp[i][j] = 2*dp[i+1][j-1] + 2;
                    }else if(n==p){
                        dp[i][j] = 2*dp[i+1][j-1] + 1;
                    }else{
                        dp[i][j] = 2*dp[i+1][j-1] - dp[n+1][p-1];
                    }
                }
            }
        }
    }

    cout<<dp[0][str.length()-1];

    return 0;
}