#include<bits/stdc++.h>

using namespace std;

int n;

//Here each cell is a level with 8 options.
void knightTour(vector<vector<int>> &chess, int row, int col, int move){
    if(row<0 || col<0 || row>=n || col>=n || chess[row][col]>0){
        return;
    }

    if(move == n*n){
        chess[row][col] = move;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<chess[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"==================\n";
        return;
    }

    chess[row][col] = move;
    knightTour(chess,row-2,col+1,move+1);
    knightTour(chess,row-1,col+2,move+1);
    knightTour(chess,row+1,col+2,move+1);
    knightTour(chess,row+2,col+1,move+1);
    knightTour(chess,row+2,col-1,move+1);
    knightTour(chess,row+1,col-2,move+1);
    knightTour(chess,row-1,col-2,move+1);
    knightTour(chess,row-2,col-1,move+1);
    chess[row][col] = 0;

}

int main(){
    
    cin>>n;

    vector<vector<int>> chess(n, vector<int>(n,0));
    

    knightTour(chess,2,2,1);

    return 0;
}