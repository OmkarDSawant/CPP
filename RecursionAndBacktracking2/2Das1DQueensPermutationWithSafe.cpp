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

void generateCombination(int lo, int qpsf, int tq, vector<vector<int>> &chess, vector<bool> &queen){

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

    for(int i = 0; i<chess.size()*chess .size(); i++){
        for(int j = 0; j<queen.size(); j++){
            if(queen[j] == false){
                queen[j] = true;
                int row = i/chess.size();
                int col = i%chess.size();

                if(isSafe(chess, row, col)){
                    chess[row][col] = j+1;
                    generateCombination(i, qpsf+1, tq, chess, queen);
                    chess[row][col] = 0;
                }

                queen[j] = false;
            }
        }
    }
}

int main(){

    int n;
    cin>>n;

    vector<vector<int>> chess(n, vector<int>(n, 0));
    vector<bool> queen(n,false);

    generateCombination(-1, 0, n, chess, queen);

    return 0;
}