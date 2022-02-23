#include<iostream>
#include<vector>

using namespace std;

bool isSafe(vector<vector<bool>> &chess, int row, int col){
    for(int i=row, j=col; i>=0; i--){
        if(chess[i][j]){
            return false;
        }
    }

    for(int i=row, j=col; j>=0; j--){
        if(chess[i][j]){
            return false;
        }
    }

    for(int i=row, j=col; i>=0 && j<chess.size(); i--, j++){
        if(chess[i][j]){
            return false;
        }
    }

    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(chess[i][j]){
            return false;
        }
    }

    return true;
}

void generateCombination(int lo, int qpsf, int tq, vector<vector<bool>> &chess){

    if(qpsf == tq){
        for(int i=0; i<chess.size(); i++){
            for(int j=0; j<chess.size(); j++){
                if(chess[i][j]){
                    cout<<"q";
                }else{
                    cout<<"-";
                }
            }
            cout<<"\n";
        }
        cout<<"\n";
        return;
    }

    for(int i = lo+1; i<chess.size()*chess .size(); i++){
        int row = i/chess.size();
        int col = i%chess.size();

        if(isSafe(chess, row, col)){
            chess[row][col] = true;
            generateCombination(i, qpsf+1, tq, chess);
            chess[row][col] = false;
        }
    }
}

int main(){

    int n;
    cin>>n;

    vector<vector<bool>> chess(n, vector<bool>(n, false));

    generateCombination(-1, 0, n, chess);

    return 0;
}