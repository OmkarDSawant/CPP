#include<iostream>
#include<vector>

using namespace std;

bool isSafe(vector<vector<int>> &chess, int row, int col){
    
    for(int i=row, j=col; i>=0; i--){
        if(chess[i][j]>0){
            return false;
        }
    }

    
    for(int i=row, j=col; j>=0; j--){
        if(chess[i][j]>0){
            return false;
        }
    }

    for(int i=row, j=col; i>=0 && j<chess.size(); i--, j++){
        if(chess[i][j]>0){
            return false;
        }
    }

    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(chess[i][j]>0){
            return false;
        }
    }

    for(int i=row, j=col; j<chess.size(); j++){
        if(chess[i][j]>0){
            return false;
        }
    }

    for(int i=row, j=col; i<chess.size() && j<chess.size(); i++, j++){
        if(chess[i][j]>0){
            return false;
        }
    }

    for(int i=row, j=col; i<chess.size(); i++){
        if(chess[i][j]>0){
            return false;
        }
    }

    for(int i=row, j=col; i<chess.size() && j>=0; i++, j--){
        if(chess[i][j]>0){
            return false;
        }
    }

    return true;
}

void generatePermutation(int qpsf, int tq, vector<vector<int>> &chess){

    if(qpsf == tq){
        for(int i=0; i<chess.size(); i++){
            for(int j=0; j<chess.size(); j++){
                if(chess[i][j]){
                    cout<<"q"<<chess[i][j];
                }else{
                    cout<<"-";
                }
            }
            cout<<"\n";
        }
        cout<<"\n";
        return;
    }

    for(int i=0; i<chess.size()*chess.size(); i++){
        int row = i/chess.size();
        int col = i%chess.size();

        if(chess[row][col] == 0 && isSafe(chess, row, col)){
            chess[row][col] = qpsf+1;
            generatePermutation(qpsf+1, tq, chess);
            chess[row][col] = 0;
        }
    }
}

int main(){

    int n;
    cin>>n;

    vector<vector<int>> chess(n, vector<int>(n, 0));

    generatePermutation(0, n, chess);

    return 0;
}