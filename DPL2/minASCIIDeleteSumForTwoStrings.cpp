#include<iostream>
#include<vector>

using namespace std;

int getSum(string str, int idx){
    int sum = 0;
    for(int i=0; i<idx; i++){
        sum+= (int)str[i];
    }
    return sum;
}

int rec(string s1, string s2, int n, int m, vector<vector<int>> &dp){
    if(m==0 && n==0){
        return dp[n][m] = 0;
    }else if(n==0){
        return dp[n][m] = getSum(s2,m);

    }else if(m==0){
        return dp[n][m] = getSum(s1,n);
    }

    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    if(s1[n-1] == s2[m-1]){
        return dp[n][m] = rec(s1, s2, n-1, m-1, dp);
    }else{
        int ans = (int)s1[n-1] + rec(s1, s2, n-1, m, dp);
        int ans2 = (int)s2[m-1] + rec(s1, s2, n, m-1, dp);

        return dp[n][m] = min(ans, ans2);
    }
}

int tab(string s1, string s2){
    int N = s1.length();
    int M = s2.length();
    vector<vector<int>> dp(N+1, vector<int>(M+1,-1));

    for(int n=0; n<=N; n++){
        for(int m=0; m<=M; m++){
            if(m==0 && n==0){
                dp[n][m] = 0;
            }else if(n==0){
                dp[n][m] = getSum(s2,m);
            }else if(m==0){
                dp[n][m] = getSum(s1,n);
            }else if(s1[n-1] == s2[m-1]){
                dp[n][m] = rec(s1, s2, n-1, m-1, dp);
            }else{
                int ans = (int)s1[n-1] + dp[n-1][m];
                int ans2 = (int)s2[m-1] + dp[n][m-1];

                dp[n][m] = min(ans, ans2);
            }
        }
    }

    return dp[N][M];
}

int main(){
    string s1,s2;
    cin>>s1>>s2;

    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

    cout<<rec(s1, s2, n, m, dp)<<"\n";

    cout<<tab(s1,s2);

    return 0;
}