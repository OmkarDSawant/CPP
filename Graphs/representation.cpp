#include<iostream>
#include<vector>

using namespace std;

// const int N = 1e5+2;

int main(){
    int nodes,edges;
    cin>>nodes>>edges;

    // we are not using 0th row and 0th column
    vector<vector<int>> adjm(nodes+1, vector<int>(nodes+1,0));

    for(int i=0; i<edges; i++){
        int x,y;
        cin>>x>>y;

        //Undirected edges.
        adjm[x][y] = 1;
        adjm[y][x] = 1;
    }

    cout<<"\nAdjacency Matrix for the given graph: \n";

    for(int i=1; i<nodes+1; i++){
        for(int j=1; j<nodes+1; j++){
            cout<<adjm[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"\n\nAdjacency List for the given graph: \n";

    vector<int> adj[nodes+1];
    for(int i=1; i<nodes+1; i++){
        for(int j=1; j<nodes+1; j++){
            if(adjm[i][j] == 1){
                adj[i].push_back(j);
            }
        }
    }

    for(int i = 1; i<nodes+1; i++){
        cout<<i<<" -> ";
        for(auto val : adj[i]){
            cout<<val<<" ";
        }
        cout<<"\n";
    }


    return 0;
}