#include<iostream>
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

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int target;
    cin>>target;

    bool dp[n+1][target+1];

    for(int i=0; i<n+1; i++){
        for(int j=0; j<target+1; j++){
            if(j==0){
                dp[i][j] = true;
            }else if(i==0){
                dp[i][j] = false;
            }else{
                dp[i][j] = dp[i-1][j];
                if(j>=arr[i-1] && dp[i-1][j-arr[i-1]]){
                    dp[i][j] = true;
                }
            }
        }
    }

    cout<<dp[n][target]<<"\n";

    queue<Node> q;
    q.push(Node(n,target,""));

    while(!q.empty()){
        Node rem = q.front();
        q.pop();

        if(rem.i==0 || rem.j==0){
            cout<<rem.psf<<"\n";
        }else{
            bool exc = dp[rem.i-1][rem.j];
            if(exc){
                q.push(Node(rem.i-1,rem.j,rem.psf));
            }

            if(rem.j>=arr[rem.i-1]){
                bool inc = dp[rem.i-1][rem.j-arr[rem.i-1]];

                if(inc){
                    q.push(Node(rem.i-1, rem.j-arr[rem.i-1], to_string(rem.i-1)+" "+rem.psf));
                }
            }
        }
        
    }

    return 0;
}