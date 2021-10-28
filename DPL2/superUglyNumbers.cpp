#include<bits/stdc++.h>

using namespace std;

int main(){

    int k;
    cin>>k;

    int primes[k];
    for(int i=0; i<k; i++){
        cin>>primes[i];
    }

    vector<int> pointers(k,1);

    int n;
    cin>>n;

    int dp[n+1];
    dp[1] = 1; //1st ugly number

    int mini;
    for(int i=2; i<=n; i++){
        mini = INT_MAX;
        for(int j=0; j<k; j++){
            mini = min(mini, primes[j] * dp[pointers[j]]);
        }

        dp[i] = mini;

        for(int j=0; j<k; j++){
            if(mini == primes[j] * dp[pointers[j]]){
                pointers[j]++;
            }
        }

    }

    for(int i=1; i<=n; i++){
        cout<<dp[i]<<" ";
    }

    return 0;
}