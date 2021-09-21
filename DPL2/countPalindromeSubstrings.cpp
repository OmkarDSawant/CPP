#include<iostream>

using namespace std;

int main(){

    string str;
    cin>>str;

    bool dp[str.length()][str.length()];
    int count = 0;
    for(int g=0; g<str.length(); g++){

        for(int i=0,j=g; j<str.length(); j++,i++){
            if(g==0){
                dp[i][j] = true;
            }else if(g==1){
                dp[i][j] = str[i]==str[j]; //IMP
            }else{
                dp[i][j] = (str[i] == str[j] && dp[i+1][j-1]);
            }

            if(dp[i][j]){
                count++;
            }
        }

    }

    cout<<count;

    return 0;
}