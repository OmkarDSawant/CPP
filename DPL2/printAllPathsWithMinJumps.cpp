#include<bits/stdc++.h>

using namespace std;

struct Node{
    int idx;
    int jumps;
    int len;
    string psf;

    Node(int i, int j, int l, string path){
        idx = i;
        jumps = j;
        len = l;
        psf = path;
    }
};

int main(){

    int n;
    cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> dp(n,-1); //IMP 
    dp[n-1]=0;

    for(int i=n-2; i>=0; i--){
        int jumps = arr[i];
        int min = INT_MAX;
        for(int j=1; j<=jumps && i+j<n; j++){
           if(dp[i+j] < min && dp[i+j] != -1){
               min = dp[i+j];
           } 
        }

        if(min != INT_MAX){ //IMP
            dp[i] = min+1;
        }
    }

    cout<<dp[0]<<"\n";

    queue<Node> q;
    q.push(Node(0,arr[0],dp[0],to_string(arr[0])));

    while(!q.empty()){
        Node rem = q.front();
        q.pop();

        if(rem.idx == n-1){
            cout<<rem.psf<<"\n";
        }

        for(int i=rem.idx+1; i<=rem.jumps+rem.idx && i<n; i++){
            if(dp[i]==rem.len-1){
                q.push(Node(i,arr[i],dp[i],rem.psf + "->" + to_string(arr[i])));
            }
        }
    }

    return 0;
}