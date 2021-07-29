//Greedy approach
#include<iostream>
#include<vector>
#include<set>

using namespace std;

const int INF = 1e9;
const int N = 1e5+3;

vector<vector<int>> adj[N]; //Multiple neighbours pair for any vertex;

void primsMST(int source, int n){
    int cost = 0;
    vector<int> distance(n);
    vector<int> parent(n);
    vector<bool> visited(n,false);

    for(int i=0; i<n; i++){ //All distance infinity.
        distance[i] = INF;
    }

    set<vector<int>> s;
    distance[source] = 0; //starting node

    s.insert({0,source});
    //wt,vertex

    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);

        visited[x[1]] = true;

        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];

        cout<<u<<" "<<v<<" "<<w<<"\n";

        cost += w;

        for(auto i : adj[x[1]]){
            if(visited[i[0]]) //Already selected as it was the shortest distance
                continue;

            //The below condition will always be true for the first time thus the parent of all vertex will be assigned.
            if(distance[i[0]] > i[1]){ //Checks if previous distance is greater than current distance
                s.erase({distance[i[0]],i[0]});
                distance[i[0]] = i[1]; //Updated the distance to smaller value.
                s.insert({distance[i[0]],i[0]});
                parent[i[0]] = x[1];
            }    
        }
    }
    cout<<"Cost: "<<cost;
}

int main(){
    int n,m;
    cin>>n>>m;

    int u,v,w;
    for(int i=0; i<m; i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    primsMST(0,n); //Starting from any random vertex. Here 0
    return 0;
}