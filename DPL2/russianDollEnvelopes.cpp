#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<vector<int>> env;

    int width,height;
    for(int i=0; i<n; i++){
        cin>>width>>height;
        env.push_back({width,height});
    }

    sort(env.begin(), env.end(), [&](vector<int> &a, vector<int> &b){
        return a[0]<b[0];
    });

    int dp[n];
    int omax = 1;
    dp[0] = 1;

    for(int i=1; i<n; i++){
        int maxi = 0;
        for(int j=0; j<i; j++){
            if(env[j][1]<env[i][1] && env[j][0]<env[i][0]){ //IMP - both must be strictly less
                maxi = max(maxi, dp[j]);
            }
        }
        dp[i] = maxi + 1;
        omax = max(omax,dp[i]);
    }

    cout<<omax;

    return 0;
}