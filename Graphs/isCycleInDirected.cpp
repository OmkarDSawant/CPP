#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<bool> stack;

bool isCycle(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &stack){
    stack[src] = true;
    if(!visited[src]){
        visited[src] = true;
        for(int it : adj[src]){
            if(stack[it]){
                return true;
            }

            if(!visited[it] && isCycle(it, adj, visited, stack)){
                return true;
            }
        }
    }
    stack[src] = false;
    return false;
}

int main(){
    int n,m;
    cin>>n>>m;

    adj = vector<vector<int>> (n);
    visited = vector<bool> (n,false);
    stack = vector<bool> (n,false);

    int u,v;
    for(int i=0; i<m; i++){
        cin>>u>>v;

        adj[u].push_back(v);
    }

    bool cycle = false;
    for(int i=0; i<n; i++){
        if(!visited[i] && isCycle(i,adj,visited,stack)){
            cycle = true;
            break;
        }
    }
    if(cycle){
        cout<<"Cycle is present.\n";
    }else{
        cout<<"Cycle is not present.\n";
    }

    return 0;
}