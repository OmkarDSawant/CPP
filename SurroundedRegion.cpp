//Convert O into X if surrounded By X on all sides
// Example
// XXXX
// XOOX
// XXOX
// XOXX
//Ans
// XXXX
// XXXX
// XXXX
// XOXX
#include<iostream>
#include<vector>

using namespace std;

void change(vector<vector<char>> &A, int x, int y){
    A[x][y] = '*';
    int dx[]= {0,0,1,-1};
    int dy[]= {1,-1,0,0};
    for(int i=0; i<4; i++){
        int cx = x + dx[i];
        int cy = y + dy[i];

        if(cx>=0 && cx<A.size() && cy>=0 && cy<A.size() && A[cx][cy] == 'O'){
            change(A,cx,cy);
        }
    }
}
int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<char>> A(r,vector<char> (c));

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>A[i][j];
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if( i==0 || i==r-1 || j==0 || j==c-1){
                if(A[i][j] == 'O'){
                    change(A,i,j);
                }
            }
        }
    }

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(A[i][j] == 'O'){
                A[i][j] = 'X';
            }
            else if(A[i][j] == '*'){
                A[i][j] = 'O';
            }
        }
    }

    cout<<"\n";
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<A[i][j];
        }
        cout<<"\n";
    }

    return 0;
}