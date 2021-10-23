#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int dp[n];
    dp[0] = 0;
    dp[1] = 0;

    int sum = 0;

    for(int i=2; i<n; i++){
        if(arr[i-1]-arr[i] == arr[i-2]-arr[i-1]){
            dp[i] = dp[i-1]+1;
            sum += dp[i];
        }else{
            dp[i] = 0;
        }
    }

    cout<<sum;

    return 0;
}