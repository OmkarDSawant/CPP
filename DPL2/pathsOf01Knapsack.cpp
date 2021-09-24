#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct Node{
    int i;
    int j;
    string psf;

    Node(int row, int col, string path){
        i=row;
        j=col;
        psf=path;
    }
};

int main(){
    int n;
    cin>>n;

    int wt[n];
    int val[n];

    for(int i=0; i<n; i++){
        cin>>wt[i]>>val[i];
    }

    int cap;
    cin>>cap;

    vector<vector<int>> dp(n+1, vector<int>(cap+1,0));

    for(int i=1; i<n+1; i++){
        for(int j=1; j<cap+1; j++){
            dp[i][j] = dp[i-1][j];

            if(j>=wt[i-1]){
                if(dp[i-1][j-wt[i-1]] + val[i-1] > dp[i][j]){
                    dp[i][j] = dp[i-1][j-wt[i-1]] + val[i-1];
                }
            }
        }
    }

    cout<<dp[n][cap]<<"\n";
    
    queue<Node> q;
    q.push(Node(n,cap,""));

    while(!q.empty()){
        Node rem = q.front();
        q.pop();

        if(rem.i==0 || rem.j==0){
            cout<<rem.psf<<"\n";
        }else{
            int exc = dp[rem.i-1][rem.j];

            if(exc == dp[rem.i][rem.j]){
                q.push(Node(rem.i-1,rem.j,rem.psf));
            }

            if(rem.j>=wt[rem.i-1]){
                int inc = dp[rem.i-1][rem.j-wt[rem.i-1]];
                if( val[rem.i-1] + inc == dp[rem.i][rem.j]){
                    q.push(Node(rem.i-1, rem.j-wt[rem.i-1], to_string(val[rem.i-1]) +" "+ rem.psf));
                }
            }
        }
    }
    
    return 0;
}