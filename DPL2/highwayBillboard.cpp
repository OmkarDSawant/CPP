#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

int main(){

    int miles;
    cin>>miles;

    int boards;
    cin>>boards;

    int pos[boards];
    for(int i=0; i<boards; i++){
        cin>>pos[i];
    }

    int rev[boards];
    for(int i=0; i<boards; i++){
        cin>>rev[i];
    }

    int minDist;
    cin>>minDist;

    //O(boards^2)
    // int dp[boards];
    // int ans;

    // dp[0] = rev[0];
    // ans = rev[0];

    // for(int i=1; i<boards; i++){
    //     int maxi = 0;

    //     for(int j=0; j<i; j++){
    //         int dist = pos[i] - pos[j];
    //         if(dist>minDist){
    //             maxi = max(maxi,dp[j]);  
    //         }
    //     }

    //     dp[i] = maxi + rev[i];
    //     ans = max(ans,dp[i]);
    // }

    // cout<<ans;

    //O(miles)
    int dp[miles+1];
    unordered_map<int,int> mp;

    for(int i=0; i<boards; i++){
        mp[pos[i]] = rev[i];
    }

    dp[0] = 0;
    for(int i=1; i<miles+1; i++){
        if(mp[i]){
            int boardNotInstalled = dp[i-1];
            int boardInstalled = mp[i];

            if(i>=minDist+1){
                boardInstalled += dp[i-minDist-1];
            }

            dp[i] = max(boardInstalled, boardNotInstalled);
        }else{
            dp[i] = dp[i-1];
        }
    }

    cout<<dp[miles];

    return 0;
}