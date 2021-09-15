#include<bits/stdc++.h>

using namespace std;

int n,m;

void floodFill(int row, int col, vector<vector<int>> &maze, vector<vector<bool>> &visited, string path){

    if(row<0 || col<0 || row==n || col==m || maze[row][col]==1 || visited[row][col]==true){ //In this order only.
        return;
    }

    if(row==n-1 && col==m-1){
        cout<<path<<"\n";
        return;
    }

    visited[row][col] = true;

    floodFill(row-1,col,maze,visited,path+"t");
    floodFill(row,col-1,maze,visited,path+"l");
    floodFill(row+1,col,maze,visited,path+"d");
    floodFill(row,col+1,maze,visited,path+"r");

    visited[row][col] = false;

}

int main(){
    
    cin>>n>>m;

    vector<vector<int>> arr(n,vector<int>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    vector<vector<bool>> visited(n,vector<bool>(m,false));

    floodFill(0,0,arr,visited,"");

    return 0;
}