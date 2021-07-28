#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 1e5+6;
vector<int> parent(N);
vector<int> sz(N);

void make(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v){
    if(v == parent[v])
        return v;

    return parent[v] = find_set(parent[v]); //Path compression
}

void union_set(int a, int b){ //Union by size
    int x = find_set(a);
    int y = find_set(b);
 
    if( x != y){
        if(sz[x] < sz[y]) //Size of leaders
            swap(x,y);
        parent[y] = x;
        sz[x] += sz[y];
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        make(i); //Initialized all nodes
    }

    vector<vector<int>> edges;

    int u,v,w;
    for(int i=0; i<m; i++){
        cin>>u>>v>>w;
        edges.push_back({w,u,v}); //one row contains 3 elements/columns;
    }

    sort(edges.begin(),edges.end());

    int cost = 0;
    for(auto it : edges){
        int x  = find_set(it[1]);
        int y = find_set(it[2]);
        if(x != y){
            cout<<it[1]<<" "<<it[2]<<"\n";
            cost+=it[0];
            union_set(x,y);
        }else{
            continue;
        }
    }
    cout<<"Cost: "<<cost;

    return 0;
}
