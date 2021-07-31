// Single source shortest path algo.
// Works on both directed and undirected graph (weights can be postive or negative).
// Uses DP

#include<bits/stdc++.h>

using namespace std;

const int INF = 1e7;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> edges; //List of edges

    int u,v,w;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }

    vector<int> dis(n,INF);
    int source;
    cin>>source;

    dis[source] = 0;

    for(int i=0; i<n-1; i++){

        for(auto e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            dis[v] = min(dis[v], dis[u] + w);
        }
    }

    for(int i=1; i<n; i++){
        if(dis[i]!=INF)
            cout<<dis[i]<<" ";
        else
            cout<<dis[i]<<" ";
    }
    return 0;
}