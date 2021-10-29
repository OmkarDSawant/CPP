//This is not a dp sum

#include<iostream>
#include<vector>

using namespace std;

int main(){
    double k; //Water in liters
    cin>>k;

    int r,c;
    cin>>r>>c;

    int len = (int)k;

    vector<vector<double>> dp(len, vector<double>(len, 0.0));

    dp[0][0] = k;

    double spare;

    for(int i=0; i<len; i++){
        for(int j=0; j<=i; j++){
            if(dp[i][j]>1.0){
                spare = dp[i][j] - 1.0;
                dp[i][j] = 1.0;

                dp[i+1][j] += spare / 2.0;
                dp[i+1][j+1] += spare / 2.0;
            }
        }
    }

    cout<<dp[r][c];

    return 0;
}