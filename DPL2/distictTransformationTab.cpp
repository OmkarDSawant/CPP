#include<iostream>

using namespace std;

int main(){

    string src,tar; // source, target
    cin>>src>>tar;

    int dp[tar.length()+1][src.length()+1];

    for(int i=tar.length(); i>=0; i--){
        for(int j=src.length(); j>=0; j--){
            if(i==tar.length()){
                dp[i][j] = 1;
            }else if(j==src.length()){
                dp[i][j] = 0;
            }else{
                if(tar[i] != src[j]){
                    dp[i][j] = dp[i][j+1];
                }else{
                    dp[i][j] = dp[i+1][j+1] + dp[i][j+1];
                }
            }
        }
    }

    cout<<dp[0][0];

    return 0;
}