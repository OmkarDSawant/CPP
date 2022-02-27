#include<iostream>
#include<vector>

using namespace std;

bool isSafe(vector<vector<bool>> &chess, int row, int col){

    if(row>0 && col>1 && chess[row-1][col-2]){
        return  false;
    }

    if(row>1 && col>0 && chess[row-2][col-1]){
        return false;
    }

    int cs = chess.size();

    if(row>0 && col+2<cs && chess[row-1][col+2]){
        return  false;
    }

    if(row>1 && col+1<cs && chess[row-2][col+1]){
        return false;
    }

    return true;

}

void generateCombination(int kpsf, int tk, vector<vector<bool>> &chess, int lo){

    if(kpsf == tk){
        for(int i=0; i<chess.size(); i++){
            for(int j=0; j<chess.size(); j++){
                if(chess[i][j]){
                    cout<<"k";
                }else{
                    cout<<"-";
                }
            }
            cout<<"\n";
        }
        cout<<"\n";
        return;
    }

    for(int i=lo+1; i<chess.size() * chess.size(); i++){
        int row = i/chess.size();
        int col = i%chess.size();

        if(isSafe(chess, row, col)){
            chess[row][col] = true;
            generateCombination(kpsf+1, tk, chess, i);
            chess[row][col] = false;
        }
    }
}

int main(){

    int n;
    cin>>n;

    vector<vector<bool>> chess(n, vector<bool>(n, false));

    generateCombination(0, n, chess, -1);
    return 0;
}