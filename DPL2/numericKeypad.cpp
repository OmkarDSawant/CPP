#include<iostream>
#include<vector>

using namespace std;

int main(){

    vector<vector<int>> data = {
        {0,8},
        {1,2,4},
        {1,2,3,5},
        {2,3,6},
        {1,4,5,7},
        {2,4,5,6,8},
        {3,5,6,9},
        {4,7,8},
        {0,5,7,8,9},
        {6,8,9}
    };

    int n;
    cin>>n;

    vector<vector<int>> dp(n, vector<int>(10,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<10; j++){
            if(i==0){
                dp[i][j] = 1;
            }else{
                for(int prev : data[j]){
                    dp[i][j] += dp[i-1][prev];
                }
            }
        }
    }

    int sum = 0;

    for(int j=0; j<10; j++){
        sum+=dp[n-1][j];
    }

    cout<<sum;
    return 0;
}