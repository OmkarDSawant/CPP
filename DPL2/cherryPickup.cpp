#include<bits/stdc++.h>

using namespace std;

int maxVal = INT_MIN;

void helper(int row, int col, vector<vector<int>> &arr, int csf){

    if(row<0 || col<0 || arr[row][col] == -1){
        return;
    }

    if(row == 0 && col == 0){
        maxVal = max(csf,maxVal);
        return;
    }

    int cherries = arr[row][col];
    arr[row][col] = 0;
    helper(row-1,col,arr,csf+cherries);
    helper(row,col-1,arr,csf+cherries);
    arr[row][col] = cherries;

}

void cp(int row, int col, vector<vector<int>> &arr, int csf){

    if(row>arr.size()-1 || col>arr[0].size()-1 || arr[row][col] == -1){
        return;
    }

    if(row == arr.size()-1 && col == arr.size()-1){
        helper(row,col,arr,csf);
    }

    int cherries = arr[row][col];
    arr[row][col] = 0;
    cp(row+1,col,arr,csf+cherries);
    cp(row,col+1,arr,csf+cherries);
    arr[row][col] = cherries; //backtracking

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

    cp(0,0,arr,0);

    cout<<maxVal;

    return 0;
}