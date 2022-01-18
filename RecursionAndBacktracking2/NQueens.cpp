#include<iostream>
#include<vector>

using namespace std;

void solution(vector<bool> &cols, vector<bool> &ndiag, vector<bool> &rdiag, int row, string asf){

    if(row==cols.size()){
        cout<<asf+".\n";
        return;
    }

    for(int col = 0; col<cols.size(); col++){
        if(ndiag[row+col] == false && rdiag[row-col+cols.size()-1] == false && cols[col] == false){
            ndiag[row+col] = true;
            rdiag[row-col+ cols.size()-1] = true;
            cols[col] = true;
            solution(cols, ndiag, rdiag, row+1, asf +"("+to_string(row)+","+to_string(col)+") ");
            ndiag[row+col] = false;
            rdiag[row-col+cols.size()-1] = false;
            cols[col] = false;
        }
    }
}

int main(){

    int n; 
    cin>>n;

    vector<bool> cols(n,false);
    vector<bool> ndiag(2*n-1,false);
    vector<bool> rdiag(2*n-1,false);

    solution(cols, ndiag, rdiag, 0, "");
    return 0;
}