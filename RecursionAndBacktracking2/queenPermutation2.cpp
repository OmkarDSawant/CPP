#include<iostream>
#include<vector>

using namespace std;

void queenPermutation(int qpsf, int tq, vector<bool> &isPlaced, int row, int col, string asf){

    if(row == tq){
        if(qpsf == tq){
            cout<<asf<<"\n";
        }
        return;
    }

    int nr,nc;
    char sep;

    if(col == tq-1){
        nr = row+1;
        nc = 0;
        sep = '\n';
    }else{
        nr = row;
        nc = col+1;
        sep = '\t';
    }

    for(int i=0; i<tq; i++){
        if(!isPlaced[i]){
            isPlaced[i] = true;
            queenPermutation(qpsf + 1, tq, isPlaced, nr, nc, asf + "q" + to_string(i+1) + sep);
            isPlaced[i] = false;
        }
    }

    queenPermutation(qpsf, tq, isPlaced, nr, nc, asf + "-" + sep);
}

int main(){

    int n;
    cin>>n;

    vector<bool> isPlaced(n, false);

    queenPermutation(0, n, isPlaced, 0, 0, "");

    return 0;
}