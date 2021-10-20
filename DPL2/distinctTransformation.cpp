#include<iostream>
#include<vector>

using namespace std;

int solution(string s1, string s2, int s, int t, vector<vector<int>> &dp){

    if(t==s2.length()){
        return 1;
    }
    if(s==s1.length() && t<s2.length()){
        return 0;
    }
    if(dp[s][t] != -1){
        return dp[s][t];
    }

    char src = s1[s];
    char tar = s2[t];

    int tw = 0;
    if(src != tar){
        tw = solution(s1,s2,s+1,t,dp);
    }else{
        tw = solution(s1,s2,s+1,t,dp) + solution(s1,s2,s+1,t+1,dp); 
    }
    dp[s][t] = tw;
    return tw;

}

int main(){

    string s1,s2;
    cin>>s1>>s2;

    vector<vector<int>> dp(s1.length(), vector<int>(s2.length(),-1));

    cout<<solution(s1,s2,0,0,dp);

    return 0;
}