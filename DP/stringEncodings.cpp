//Possible number of valid string encodings for a given string. First character will not be 0.

#include<iostream>
#include<string>

using namespace std;

int main(){
    string str;
    cin>>str;

    int dp[str.length()];

    dp[0] = 1;

    for(int i=1; i<str.length(); i++){
        if(str[i-1]=='0' && str[i]=='0'){ //Both are zero

            dp[i] = 0; //Invalid encoding

        }else if(str[i-1]=='0'  && str[i]!='0'){ // zero and Non zero
            
            dp[i] = dp[i-1];

        }else if((str[i-1]=='1' || str[i-1]=='2') && str[i]=='0'){ //Non zero and zero

            dp[i] = i>=2 ? dp[i-2] : 1;

        }else{ //Non zero and non zero
            if( stoi(str.substr(i-1,2)) <= 26 ){
                dp[i] = dp[i-1] + (i>=2 ? dp[i-2] : 1); 
            }
        }
    }

    cout<<dp[str.length()-1];
    return 0;
}