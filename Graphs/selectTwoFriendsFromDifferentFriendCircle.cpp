//Find the number ways in which you can select two friends each from a different friend circle.
//Given three friend circle with sizes 2,3,4.

#include<iostream>
#include<vector>

using namespace std;

int getSize(int idx, vector<vector<int>> &adj, vector<bool> &visited){
    // if(visited[idx]){ //Not for first call but for inner calls
    //     return 0;
    // }  
    visited[idx] = true;
    int ans = 1;
    for(auto it : adj[idx]){
        if(!visited[it]){
            ans += getSize(it,adj,visited);
        }
    }
    return ans;
}
int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> adj(n);
    vector<bool> visited(n,false);
    vector<int> components;

    int u,v;
    for(int i=0; i<m; i++){
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            components.push_back(getSize(i,adj,visited));
        }
    }

    int ways = 0;
    for(auto element : components){
        ways += element * (n-element); 
    }

    cout<<"Number of ways: "<<(ways/2);

    return 0;
}