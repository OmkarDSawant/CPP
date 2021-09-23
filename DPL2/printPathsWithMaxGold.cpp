#include<bits/stdc++.h>

using namespace std;

struct Node{
    int r;
    int c;
    string psf;

    Node(int row, int col, string path){
        r = row;
        c = col;
        psf = path; 
    }
};

int main(){

    int n,m;
    cin>>n>>m;

    int arr[n][m];

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    int dp[n][m];

    for(int j=m-1; j>=0; j--){
        for(int i=n-1; i>=0; i--){
            if(j==m-1){ //Last column
                dp[i][j] = arr[i][j];
            }else if(i==n-1){ //Last row
                dp[i][j] = arr[i][j] + max(dp[i][j+1],dp[i-1][j+1]);
            }else if(i==0){ //First row
                dp[i][j] = arr[i][j] + max(dp[i][j+1],dp[i+1][j+1]);
            }else{
                dp[i][j] = arr[i][j] + max(dp[i][j+1], max(dp[i+1][j+1],dp[i-1][j+1]));
            }
        }
    }

    int maxVal = INT_MIN;
    for(int i=0; i<n; i++){
        if(dp[i][0]>maxVal){
            maxVal = dp[i][0];
        }
    }

    cout<<maxVal<<"\n";

    queue<Node> q;
    for(int i=0; i<n; i++){
       if(dp[i][0]==maxVal){
           q.push(Node(i,0,to_string(i)+" "));
       }
    }

    while(!q.empty()){
        Node rem = q.front();
        q.pop();

        if(rem.c==m-1){
            cout<<rem.psf<<"\n";
        }else if(rem.r==0){

            int maxi = max(dp[rem.r][rem.c+1], dp[rem.r+1][rem.c+1]);

            if(dp[rem.r][rem.c+1] == maxi){
                q.push(Node(rem.r, rem.c+1, rem.psf + "d2 "));  
            }

            if(dp[rem.r+1][rem.c+1] == maxi){
                q.push(Node(rem.r+1, rem.c+1, rem.psf + "d3 "));  
            }
            
        }else if(rem.r==n-1){

            int maxi = max(dp[rem.r][rem.c+1], dp[rem.r-1][rem.c+1]);

            if(dp[rem.r-1][rem.c+1] == maxi){
                q.push(Node(rem.r-1, rem.c+1, rem.psf + "d1 "));
            }

            if(dp[rem.r][rem.c+1] == maxi){
                q.push(Node(rem.r, rem.c+1, rem.psf + "d2 "));  
            }

        }else{
            int maxi = max(dp[rem.r][rem.c+1], max(dp[rem.r+1][rem.c+1],dp[rem.r-1][rem.c+1]));

                if(dp[rem.r-1][rem.c+1] == maxi){
                    q.push(Node(rem.r-1, rem.c+1, rem.psf + "d1 "));
                }

                if(dp[rem.r][rem.c+1] == maxi){
                    q.push(Node(rem.r, rem.c+1, rem.psf + "d2 "));  
                }

                if(dp[rem.r+1][rem.c+1] == maxi){
                    q.push(Node(rem.r+1, rem.c+1, rem.psf + "d3 "));                    
                }
        }
    }
    return 0;
}