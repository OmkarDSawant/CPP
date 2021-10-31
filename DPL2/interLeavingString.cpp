#include<iostream>
#include<vector>

using namespace std;

bool solution1(string s1, string s2, string s3, int i, int j, vector<vector<int>> &dp){

    if(i == s1.length() && j == s2.length()){
        return true;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(s1[i] == s3[i+j]){
        int f1 = solution1(s1, s2, s3, i+1, j, dp);
        dp[i][j] = f1;
        if(f1){
            return true;
        }
    }

    if(s2[j] == s3[i+j]){
        int f2 = solution1(s1, s2, s3, i, j+1, dp);
        dp[i][j] = f2;
        if(f2){
            return true;
        }
    }

    dp[i][j] = false;
    return false;

}

bool solution2(string s1, string s2, string s3){

    vector<vector<bool>> dp1(s1.length()+1, vector<bool>(s2.length()+1));

    for(int i=0; i<=s1.length(); i++){
        for(int j=0; j<=s2.length(); j++){
            if(i==0 && j==0){
                dp1[i][j] = true;
            }else if(i==0){
                dp1[i][j] = s2[j-1] == s3[i+j-1] ? dp1[i][j-1] : false;
            }else if(j==0){
                dp1[i][j] = s1[i-1] == s3[i+j-1] ? dp1[i-1][j] : false;
            }else{
                dp1[i][j] = false;

                if(s1[i-1] == s3[i+j-1]){
                    dp1[i][j] = dp1[i-1][j];
                }

                if( dp1[i][j]!=true && s2[j-1] == s3[i+j-1]){
                    dp1[i][j] = dp1[i][j-1];
                }
            }
        }
    }

    return dp1[s1.length()][s2.length()];
}

int main(){

    string s1, s2, s3;
    cin>>s1>>s2>>s3;

    if(s1.length() + s2.length() != s3.length()){
        cout<<"false";
        return 0;
    }

    //Memoization
    // vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, -1)); //+1 is imp
    // cout<<solution1(s1, s2, s3, 0, 0, dp);

    //Tabulation
    cout<<solution2(s1, s2, s3);

    return 0;
}