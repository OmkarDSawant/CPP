#include<iostream>

using namespace std;

int main(){

    int n;
    cin>>n;
    
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int target; cin>>target;

    bool dp[n+1][target+1]; //As we have 0th row and col.

    for(int i=0; i<n+1; i++){
        for(int j=0; j<target+1; j++){
            if(i==0 && j==0){
                dp[i][j] = true;
            } else if(i==0){
                dp[i][j] = false;
            } else if(j==0){
                dp[i][j] = true;
            }else{
                if(dp[i-1][j] == true){
                    dp[i][j] = true;
                }else{
                    int val = arr[i-1]; //row number from dp = arr[row-1]
                    if(j>=val){
                        if(dp[i-1][j-val] == true){
                            dp[i][j] = true;
                        }else{
                            dp[i][j] = false;
                        }
                    }else{
                        dp[i][j] = false;
                    }
                }
            }
        }
    }

    cout<<dp[n][target];
    return 0;
}