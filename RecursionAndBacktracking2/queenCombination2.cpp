#include<iostream>
#include<vector>

using namespace std;

void queenCombination(int row, int col, int qpsf, int tq, vector<vector<bool>> &chess){

    if(qpsf == tq){
        for(int i=0; i<tq; i++){
            for(int j=0; j<tq; j++){
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

    for(int j = col+1; j<tq; j++){
        if(chess[row][j] == false){
            chess[row][j] = true;
            queenCombination(row, j, qpsf+1, tq, chess);
            chess[row][j] = false;
        }
    }

    for(int i = row+1; i<tq; i++){
        for(int j=0; j<tq; j++){
            if(chess[i][j] == false){
                chess[i][j] = true;
                queenCombination(i, j, qpsf+1, tq, chess);
                chess[i][j] = false;
            }
        }
    }
}

int main(){

    int n;
    cin>>n;

    vector<vector<bool>> chess(n, vector<bool>(n, false));

    queenCombination(0, -1, 0, n, chess);
    return 0;
}