#include<iostream>
#include<vector>

using namespace std;

bool isCycle(int src, vector<bool> &vis, vector<vector<int>> &adj, int parent){
    vis[src] = true;
    for(auto it : adj[src]){
        if(it != parent){
            if(vis[it]){
                return true;
            }

            if(!vis[it] && isCycle(it,vis,adj,src)){
                return true;
            }
        }
    }
    return false;
}

int main(){

    int n,e;
    cin>>n>>e;

    vector<vector<int>> adj(n);
    vector<bool> visited(n,false);

    int u,v;
    for(int i=0; i<e; i++){
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool cycle = false;
    for(int i=0; i<n; i++){
        if(!visited[i] && isCycle(i,visited,adj,-1)){
            cycle = true;
            break;
        }
    }
    if(cycle){
        cout<<"Cycle is present.\n";
    }else{
        cout<<"Cycle is not present.";
    }
    return 0;
}