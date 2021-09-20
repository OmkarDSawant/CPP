#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<vector<int>> cords;

    int north,south;
    for(int i=0; i<n; i++){
        cin>>north>>south;
        cords.push_back({north,south});
    }

    sort(cords.begin(), cords.end(), [&](vector<int> &a, vector<int> &b){
        if(a[0]!=b[0]){
            return a[0]<b[0];
        }else{
            return a[1]<b[1];
        }
    });

    int dp[n];
    int omax = 1;
    dp[0] = 1;

    for(int i=1; i<n; i++){
        int maxi = 0;
        for(int j=0; j<i; j++){
            if(cords[j][1]<=cords[i][1]){
                maxi = max(maxi, dp[j]);
            }
        }
        dp[i] = maxi + 1;
        omax = max(maxi,omax);
    }

    cout<<omax;

    return 0;
}