#include<iostream>
#include<queue>

using namespace std;

struct Node{

    int r;
    int c;
    int v;
    string psf;

    Node(int row, int col, int val, string path){
        r = row;
        c = col;
        v = val;
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

    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            if(i==n-1 && j==m-1){
                dp[i][j] = arr[i][j];
            }else if(i==n-1){
                dp[i][j] = dp[i][j+1] + arr[i][j];
            }else if(j==m-1){
                dp[i][j] = dp[i+1][j] + arr[i][j];
            }else{
                dp[i][j] = arr[i][j] + min(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    cout<<dp[0][0]<<"\n";

    queue<Node> q;
    q.push(Node(0,0,dp[0][0],""));

    while(!q.empty()){

        Node rem = q.front();
        q.pop();

        if(rem.r == n-1 && rem.c == m-1){
            cout<<rem.psf<<"\n";
        }else if(rem.r == n-1){
            q.push(Node(rem.r,rem.c+1,dp[rem.r][rem.c+1],rem.psf + "H"));
        }else if(rem.c == m-1){
            q.push(Node(rem.r+1,rem.c,dp[rem.r+1][rem.c],rem.psf + "V"));
        }else{
            if(dp[rem.r][rem.c+1] < dp[rem.r+1][rem.c]){
                q.push(Node(rem.r,rem.c+1,dp[rem.r][rem.c+1],rem.psf + "H"));
            }else if(dp[rem.r+1][rem.c] < dp[rem.r][rem.c+1]){
                q.push(Node(rem.r+1,rem.c,dp[rem.r+1][rem.c],rem.psf + "V"));
            }else{
                q.push(Node(rem.r,rem.c+1,dp[rem.r][rem.c+1],rem.psf + "H"));
                q.push(Node(rem.r+1,rem.c,dp[rem.r+1][rem.c],rem.psf + "V"));
            }
        }
   
    }

    return 0;
}

        