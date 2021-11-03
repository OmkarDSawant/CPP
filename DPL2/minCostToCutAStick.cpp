#include<iostream>
#include<vector>

using namespace std;

int len;

int solution(int n, int si, int ei, vector<int> &cuts, vector<vector<int>> &dp){

    if(si>=ei){
        return 0;
    }

    if(dp[si][ei]!=-1){
        return dp[si][ei];
    }

    int ans = 1e8;

    for(int cut=si; cut<ei; cut++){

        int le = si==0?0:cuts[si-1];
        int re = ei==cuts.size()?len:cuts[ei];

        int cost = re - le;

        int left = solution(le, si, cut, cuts, dp);
        int right = solution(re, cut+1, ei, cuts, dp);

        int myAns = left + cost + right;
        ans = min(ans, myAns);
    }

    return dp[si][ei] = ans;
}

int main(){

    int n; //Length of stick. 0->n
    cin>>n;

    len=n;

    int k;
    cin>>k;

    vector<int> cuts(k);

    for(int i=0; i<k; i++){
        cin>>cuts[i];
    }

    vector<vector<int>> dp(k+1, vector<int>(k+1, -1));
    cout<<solution(n, 0, cuts.size(), cuts, dp);

    return 0;
}