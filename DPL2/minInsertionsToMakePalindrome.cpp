//Same goes for deletion
#include<iostream>

using namespace std;

int main(){

    string str;
    cin>>str;

    int dp[str.length()][str.length()];

    for(int g=0; g<str.length(); g++){
        for(int i=0, j=g; j<str.length(); i++, j++){
            if(g==0){
                dp[i][j] = 1;
            }else if(g==1){
                dp[i][j] = (str[i] == str[j]? 2 : 1);
            }else{
                if(str[i]==str[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }else{
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                }
            }
        }
    }

    cout<<str.length() - dp[0][str.length()-1];
    return 0;
}