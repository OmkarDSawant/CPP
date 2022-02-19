#include<iostream>

using namespace std;

void queenCombination(int qpsf, int tq, int row, int col, string asf){

    if(row == tq){
        if(qpsf == tq){
            cout<<asf<<"\n";
        }

        return;
    }

    int nr,nc;

    string yasf, nasf;

    if(col == tq-1){
        nr = row+1;
        nc=0;
        yasf = "q\n";
        nasf = "-\n";
    }else{
        nc = col+1;
        nr=row;
        yasf = "q";
        nasf = "-";
    }

    queenCombination(qpsf+1, tq, nr, nc, asf + yasf);
    queenCombination(qpsf, tq, nr, nc, asf + nasf);
}

int main(){

    int n;
    cin>>n;

    queenCombination(0, n, 0, 0, "");

    return 0;
}