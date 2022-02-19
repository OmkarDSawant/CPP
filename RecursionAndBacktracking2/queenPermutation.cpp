#include<iostream>
#include<vector>

using namespace std;

void queenPermutation(int cq, int tq, vector<vector<int>> &chess){
    if(cq == tq){
        for(int i=0; i<tq; i++){
            for(int j=0; j<tq; j++){
                if(chess[i][j] == 0){
                    cout<<"-";
                }else{
                    cout<<"q"<<chess[i][j];
                }
            }
            cout<<"\n";
        }
        cout<<"\n";

        return;
    }
    for(int i=0; i<tq; i++){
        for(int j=0; j<tq; j++){
            if(chess[i][j] == 0){
                chess[i][j] = cq+1;
                queenPermutation(cq+1, tq, chess);
                chess[i][j] = 0;
            }
        }
    }
}

int main(){

    int n;
    cin>>n;

    vector<vector<int>> chess(n, vector<int>(n,0));

    queenPermutation(0, n, chess);

    return 0;
}