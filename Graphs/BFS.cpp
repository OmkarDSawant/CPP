#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){

    int n,e;
    cin>>n>>e;

    bool vis[n+1];
    vector<int> adj[n+1];

    for(int i=1; i<=n; i++){
        vis[i] = false;
    }

    int x,y;
    for(int i=0; i<e; i++){
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    q.push(1);
    vis[1] = true;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        cout<<node<<" ";

        vector<int> :: iterator it;

        for(it=adj[node].begin(); it!= adj[node].end(); it++){
            if(!vis[*it]){
                q.push(*it);
                vis[*it] = true;
            }
        }
    }

    return 0;
}