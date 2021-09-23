#include<iostream>
#include<unordered_map>

using namespace std;

int main(){

    string str;
    cin>>str;

    unordered_map<char,int> mp;

    int dp[str.length()+1];
    dp[0] = 1;

    for(int i=1; i<str.length()+1; i++){
        char ch = str[i-1];
        dp[i] = 2*dp[i-1];

        if(mp.find(ch) != mp.end()){
            int j = mp[ch];
            dp[i] = dp[i] - dp[j-1];
        }

        mp[ch] = i;
    }

    cout<<dp[str.length()]-1; //-1 indicates empty subsequence is excluded.
    return 0;
}