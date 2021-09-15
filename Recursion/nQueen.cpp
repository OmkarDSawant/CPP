#include<bits/stdc++.h>

using namespace std;

int n;

bool isQueenSafe(int row, int col, vector<vector<int>> &chess){
    for(int trow = row-1; trow>=0; trow--){ //vertical
        if(chess[trow][col]==1){
            return false;
        }
    }

    for(int trow = row-1, tcol = col-1; trow>=0 && tcol>=0; trow-- , tcol--){
        if(chess[trow][tcol]==1){ //diagonal left
            return false;
        }
    }

    for(int trow = row-1, tcol = col+1; trow>=0 && tcol<n; trow--, tcol++){
        if(chess[trow][tcol]==1){ //diagonal right
            return false;
        }
    }

    return true;
}

void nQueen(vector<vector<int>> &chess, int row){

    if(row == n){

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<chess[i][j];
            }
            cout<<"\n";
        }
        cout<<"============\n";
        return;
    }

    for(int col=0; col<n; col++){
        if(isQueenSafe(row,col,chess)){
            chess[row][col] = 1;
            nQueen(chess,row+1);
            chess[row][col] = 0; //Backtracking
        }
    }

}

int main(){
    
    cin>>n;

    vector<vector<int>> chess(n, vector<int>(n,0));

    nQueen(chess,0);

    return 0;
}