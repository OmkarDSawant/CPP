#include<bits/stdc++.h>

using namespace std;

struct Node{
    int idx;
    int val;
    int len;
    string psf;

    Node(int i, int v, int l, string path){
        idx = i;
        val = v;
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

    int dp[n];
    dp[0] = 1;
    int omax = 1;

    for(int i=1; i<n; i++){

        int max = 0;
        for(int j=0; j<i; j++){
            if(arr[i]>=arr[j] && dp[j]>max){
                max = dp[j];
            }
        }

        dp[i] = max+1;

        if(dp[i]>omax){
            omax = dp[i];
        }
    }

    cout<<omax<<"\n";

    queue<Node> q;
    for(int i=0; i<n; i++){
        if(dp[i]==omax){
            q.push(Node(i,arr[i],dp[i],to_string(arr[i])));
        }
    }

    while(!q.empty()){
        Node rem = q.front();
        q.pop();

        if(rem.len == 1){
            cout<<rem.psf<<"\n";
        }

        for(int i=rem.idx-1; i>=0; i--){
            if(arr[i] <= rem.val && dp[i] == rem.len-1){
                q.push(Node(i,arr[i],dp[i],to_string(arr[i]) +"->"+rem.psf));
            }
        }
    }

    return 0;
}