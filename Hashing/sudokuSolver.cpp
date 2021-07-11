#include<iostream>
#include<map>
#include<vector>

using namespace std;

void helper(int r, int c, vector<vector<char>> &a, map<pair<int,int>,map<int,int>> &mp, vector<map<int,int>> &row, vector<map<int,int>> &col){
    if(r==9){
        for(auto it:a){
            for(auto i:it){
                cout<<i<<" ";
            }
            cout<<"\n";
        }
        cout<<"============================\n";
        return;
    }
    if(c==9){
        helper(r+1,0,a,mp,row,col);
        return;
    }
    if(a[r][c]!='.'){
        helper(r,c+1,a,mp,row,col);
        return;
    }

    for(int i=1; i<=9; i++){
        if( !mp[{r/3,c/3}][i] && !row[r][i] && !col[c][i]){
            mp[{r/3,c/3}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            a[r][c] = i + '0';
            helper(r,c+1,a,mp,row,col);
            mp[{r/3,c/3}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            a[r][c] = '.';

        }
    }
}

void sudokuSolver(vector<vector<char>> &a){

    map<pair<int,int>,map<int,int>> mp;
    vector<map<int,int>> row(9);
    vector<map<int,int>> col(9);

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(a[i][j] != '.'){
                mp[{i/3,j/3}][a[i][j]-'0'] = 1;
                row[i][a[i][j]-'0'] = 1; 
                col[j][a[i][j]-'0'] = 1;
            }
        }
    }
    helper(0,0,a,mp,row,col);
}

int main(){
    vector<vector<char>> sudoku ={
        {'9','.','6','.','7','.','4','.','3'},
        {'.','.','.','4','.','.','2','.','.'},
        {'.','7','.','.','2','3','.','1','.'},
        {'5','.','.','.','.','.','1','.','.'},
        {'.','4','.','2','.','8','.','6','.'},
        {'.','.','3','.','.','.','.','.','5'},
        {'.','3','.','7','.','.','.','5','.'},
        {'.','.','7','.','.','5','.','.','.'},
        {'4','.','5','.','1','.','7','.','8'}
    };
    sudokuSolver(sudoku);
    return 0;
}