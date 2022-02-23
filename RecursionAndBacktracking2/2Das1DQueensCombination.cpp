#include<iostream>
#include<vector>

using namespace std;

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
        chess[row][col] = true;
        generateCombination(i, qpsf+1, tq, chess);
        chess[row][col] = false;
    }
}

int main(){

    int n;
    cin>>n;

    vector<vector<bool>> chess(n, vector<bool>(n, false));

    generateCombination(-1, 0, n, chess);

    return 0;
}