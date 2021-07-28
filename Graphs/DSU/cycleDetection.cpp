#include<iostream>
#include<vector>

using namespace std;

int N = 1e5+6;
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

    int u,v;
    bool cycle = false;
    for(int i=0; i<m; i++){
        cin>>u>>v;
        if(find_set(u) != find_set(v)){
            union_set(u,v);
        }else{
            cycle = true;
            break;
        }  
    }
    if(cycle){
        cout<<"Cycle is present";
    }else{
        cout<<"Cycle is not present";
    }
    return 0;
}
