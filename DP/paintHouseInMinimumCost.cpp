#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n; cin>>n; //Number of houses.

    int arr[n][3]; //Houses and color. 0 - red. 1 - blue. 2 - green.

    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }

    int dp[n][3];

    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    dp[0][2] = arr[0][2];

    //Since future branching will be same and the present value decides the minimum thus only minimum value is taken
    //to restrict unnecessary branching.
    for(int i=1; i<n; i++){
        dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + arr[i][0];
        dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + arr[i][1];
        dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + arr[i][2];
    }

    cout<<min(dp[n-1][0], min(dp[n-1][1],dp[n-1][2]));

    return 0;
}