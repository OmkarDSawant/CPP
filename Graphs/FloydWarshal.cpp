// Shortest path between any two vertices u,v
// Uses DP approach
// O(n^3)
// Works both on directed and undirected graph. Also with +ve and -ve weights.

#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main(){
    vector<vector<int>> graph = {
        {0,5,INF,10},
        {INF,0,3,INF},
        {INF,INF,0,1},
        {INF,INF,INF,0}
    };

    int n = graph.size(); //Number of vertices i.e row
    cout<<"Graph size: "<<n<<"\n";

    vector<vector<int>> distance = graph; //Distance of all pair shortest path

    for(int k=0; k<n; k++){ //Intermediatery vertex
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(distance[i][j] > distance[i][k] + distance[k][j]){
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    for(auto row : distance){
        for(auto element : row){
            if(element == INF){
                cout<<"INF ";
            }else{
                cout<<element<<" ";
            }
        }
        cout<<"\n";
    }
        
    
    return 0;
}