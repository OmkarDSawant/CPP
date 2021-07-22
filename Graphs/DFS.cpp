#include<iostream>
#include<vector>

using namespace std;

void preorderDfs(int node, bool *vis, vector<int> *adj){
    vis[node] = true;
    cout<<node<<" ";

    vector<int> :: iterator it;
    for(it=adj[node].begin(); it!=adj[node].end(); it++){
        if(!vis[*it]){
            preorderDfs(*it, vis, adj);
        }
    }
}

void postorderDfs(int node, bool *vis, vector<int> *adj){
    vis[node] = true;

    vector<int> :: iterator it;
    for(it=adj[node].begin(); it!=adj[node].end(); it++){
        if(!vis[*it]){
            postorderDfs(*it, vis, adj);
        }
    }

    cout<<node<<" ";
}

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

    // cout<<"Pre order printing : ";
    // preorderDfs(1, vis, adj);
    // cout<<"\n";
    cout<<"Post order printing : ";
    postorderDfs(1, vis, adj);

    return 0;
}