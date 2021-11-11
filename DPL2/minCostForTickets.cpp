#include<bits/stdc++.h>

using namespace std;

bool willITravelToday(int cday, int *days, int n){
    for(int i=0; i<n; i++){
        if(cday == days[i]){
            return true;
        }
    }

    return false;
}

int solution1(int cday, int *days, int *costs, int n, vector<int> &dp){

    if(cday>days[n-1]){
        return dp[cday] = 0;
    }

    if(dp[cday] != -1){
        return dp[cday];
    }
    
    int ans = INT_MAX;
    if(willITravelToday(cday, days, n)){

        ans = solution1(cday+1, days, costs, n, dp) + costs[0];

        ans = min(ans, solution1(cday+7, days, costs, n, dp) + costs[1]);

        ans = min(ans, solution1(cday+30, days, costs, n, dp) + costs[2]);
    }else{
        return dp[cday] = solution1(cday+1, days, costs, n, dp);
    }

    return dp[cday] = ans;
}

int solution2(int *days, int *costs, int n){
    int dpt[395];

    for(int i=395; i>=0; i--){

        if(i>days[n-1]){
            dpt[i] = 0;
            continue; //IMP
        }
    
        int ans = INT_MAX;

        if(willITravelToday(i, days, n)){
            ans = dpt[i+1] + costs[0];
            ans = min(ans, dpt[i+7] + costs[1]);
            ans = min(ans, dpt[i+30] + costs[2]);

            dpt[i] = ans;
        }else{
            dpt[i] = dpt[i+1]; //IMP
        }
    }

    return dpt[days[0]];
}

int main(){
    int n;
    cin>>n;

    int days[n];

    for(int i=0; i<n; i++){
        cin>>days[i];
    }

    int costs[3];
    for(int i=0; i<3; i++){
        cin>>costs[i];
    }

    vector<int> dp(395, -1);

    //Memoization
    cout<<solution1(days[0], days, costs, n, dp)<<"\n";

    //Tabulation
    cout<<solution2(days, costs, n);

    return 0;
}