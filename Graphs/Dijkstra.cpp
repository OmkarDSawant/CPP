// Single source shortest path algo.
// Works on both directed and undirected graph (weights must be positive).
// Minimization in optimization problem thus solved using greedy.

#include<bits/stdc++.h>

using namespace std;

const int inf = 1e7;
int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<pair<int,int>>> adj(n+1);
    vector<int> dis(n+1,inf);
    vector<bool> selectedV(n+1,false); //greedy

    int u,v,w;
    for(int i=0; i<m; i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    int source;cin>>source;
    dis[source]=0;

    set<pair<int,int>> s;
    s.insert({0,source});
    //wt, vertex

    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        selectedV[x.second] = true;

        for(auto it : adj[x.second]){
            if(selectedV[it.first]){
                continue;
            }
            if(dis[it.first] > dis[x.second] + it.second){
                s.erase({dis[it.first],it.first});
                dis[it.first] = dis[x.second] + it.second;
                s.insert({dis[it.first], it.first});
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(dis[i]!=inf)
            cout<<dis[i]<<" ";
        else
            cout<<-1<<" ";
    }

    return 0;
}