#include<iostream>
#include<vector>

using namespace std;

bool isValid(int i, int j, int val, vector<vector<int>> &arr){
    //column search
    for(int row=0; row<arr.size(); row++){
        if(arr[row][j] == val){
            return false;
        }
    }

    //row search
    for(int col=0; col<arr.size(); col++){
        if(arr[i][col] == val){
            return false;
        }
    }

    //submatrix search
    int x = (i/3)*3;
    int y = (j/3)*3;
    for(int i=x; i<x+3; i++){
        for(int j=y; j<y+3; j++){
            if(arr[i][j] == val){
                return false;
            }
        }
    }

    return true;
}

void display(vector<vector<int>> &arr){
    cout<<"\n\n";
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[0].size(); j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void solution(vector<vector<int>> &arr, int i, int j){
    int ni,nj;
    ni = i;
    nj = j;

    if(i==arr.size()){
        display(arr);
    }else if(j==arr[0].size()-1){
        ni++;
        nj=0;
    }else{
        nj++;
    }

    if(arr[i][j]!=0){
        solution(arr,ni,nj);
    }else{
        for(int po=1; po<=9; po++){
            if(isValid(i, j, po, arr)){
                arr[i][j] = po;
                solution(arr,ni,nj);
                arr[i][j] = 0;
            }
        }
    }

    
}

int main(){

    int row,col;
    cin>>row>>col;

    vector<vector<int>> arr(row, vector<int>(col));

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>arr[i][j];
        }
    }

    solution(arr,0,0);

    return 0;
}