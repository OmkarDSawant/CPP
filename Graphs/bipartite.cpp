#include<iostream>
#include<vector>

using namespace std;

void colorNodes(int src, int cur, vector<int> &color, bool &isBi, vector<vector<int>> &adj, int parent){
    if(!isBi){
        return;
    }
    if(color[src]==-1){
        color[src] = cur;
    }else{
        if(color[src]!=cur){
            isBi = false;
            return;
        }else{
            return;
        }
    }

    for(auto it : adj[src]){
        if(it != parent){
            colorNodes(it,!cur,color,isBi,adj,src);
        }  
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    // vector<bool> visited(n,false); 
    vector<int> color(n,-1);

    int u,v;
    for(int i=0; i<m; i++){
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isBi = true;

    for(int i=0; i<n; i++){
        if(color[i]==-1 && isBi){ //Not colored == Not visited
            colorNodes(i,1,color,isBi,adj,-1);
        }
    }
    if(isBi){
        cout<<"The given graph is Bipartite.";
    }else{
        cout<<"The given graph is not Bipartite";
    }
    return 0;
}