//Concept of least and second least.

#include<bits/stdc++.h>

using namespace std;

int main(){

    int n; cin>>n; //Number of houses.
    int m; cin>>m; //Number of colors.

    int arr[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j]; //Cost to paint jth color on ith house. 
        }
    }

    //Reduces complexity from O(n^3) to O(n^2) 
    int least = INT_MAX;
    int sleast = INT_MAX;

    int dp[n][m];

    for(int i=0; i<m; i++){
        dp[0][i] = arr[0][i];

        if(arr[0][i] < least){
            sleast = least;
            least = arr[0][i];
        }else if(arr[0][i] < sleast){
            sleast = arr[0][i];
        }
    }


    int nleast,nsleast;
    for(int i=1; i<n; i++){
        nleast = INT_MAX;
        nsleast = INT_MAX;

        for(int j=0; j<m; j++){
            if(dp[i-1][j] == least){
                dp[i][j] = arr[i][j] + sleast;
            }else{
                dp[i][j] = arr[i][j] + least;
            }

            if(dp[i][j] < nleast){
                nsleast = nleast;
                nleast = dp[i][j];
            }else if(dp[i][j] < nsleast){
                nsleast = dp[i][j];
            }
        }

        least = nleast;
        sleast = nsleast;

    }

    cout<<least;

    return 0;
}