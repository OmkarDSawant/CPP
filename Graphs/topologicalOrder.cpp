// The graph must be Directed Acyclic Graph.

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){

    int n,e;
    cin>>n>>e;

    vector<vector<int>> adj(n);
    vector<int> indeg(n,0);

    int u,v;
    for(int i=0; i<e; i++){
        cin>>u>>v;
        //u --> v
        adj[u].push_back(v);
        indeg[v]++;
    }

    queue<int> q;

    for(int i=0; i<n; i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int x = q.front();
        q.pop();

        cout<<x<<" ";

        for(auto it : adj[x]){
            indeg[it]--;
            if(indeg[it]==0)
                q.push(it);
        }
    }

    return 0;
}