#include<bits/stdc++.h>

using namespace std;

int cp(int r1, int c1, int r2, vector<vector<int>> &arr, vector<vector<vector<int>>> &dp){

    int c2 = r1 + c1 - r2;

    if(r1>arr.size()-1 || r2>arr.size()-1 || c1>arr[0].size()-1 || c2>arr[0].size()-1 || arr[r1][c1] == -1 || arr[r2][c2] == -1){
        return INT_MIN;
    }

    if(r1 == arr.size()-1 && c1 == arr[0].size()-1){
        return arr[r1][c1];
    }

    if(dp[r1][c1][r2] != 0){
        return dp[r1][c1][r2];
    }

    int cherries = 0;
    if(r1==r2 && c1==c2){
        cherries = arr[r1][c1];
    }else{
        cherries = arr[r1][c1] + arr[r2][c2];
    }

    int f1 = cp(r1+1,c1,r2+1,arr,dp); //vv
    int f2 = cp(r1+1,c1,r2,arr,dp); //vh
    int f3 = cp(r1,c1+1,r2+1,arr,dp); //hv
    int f4 = cp(r1,c1+1,r2,arr,dp); //hh

    cherries+= max(max(f1,f2),max(f3,f4));
    dp[r1][c1][r2] = cherries; //Max cherries we can collect till this cell from the end.
    return cherries;
}

int main(){
    int n;
    cin>>n;

    vector<vector<int>> arr(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, 0)));

    cout<<cp(0,0,0,arr,dp);

    return 0;
}