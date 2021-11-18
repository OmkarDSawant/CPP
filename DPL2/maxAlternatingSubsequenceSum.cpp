#include<iostream>
#include<vector>

using namespace std;

int memo(int idx, int *arr, int p, vector<vector<int>> &dp, int n){

    if(idx>=n) return 0;

    if(dp[idx][p] != -1){
        return dp[idx][p];
    }

    int ans;

    //choose element
    if(p==0){
        ans = memo(idx+1, arr, 1, dp, n) + arr[idx];
    }else{
        ans = memo(idx+1, arr, 0, dp, n) - arr[idx];
    }

    return dp[idx][p] = max(ans, memo(idx+1, arr, p, dp, n));

}

int tab(int *arr, int n){
    int endEven = arr[0];
    int endOdd = 0;

    for(int i=1; i<n; i++){
        endEven = max(endEven, endOdd + arr[i]);
        endOdd = max(endOdd, endEven - arr[i]);
    }

    return endEven;
}

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<tab(arr, n)<<"\n";

    vector<vector<int>> dp(n, vector<int>(2,-1));
    cout<<memo(0, arr, 0, dp, n);

    return 0;
}