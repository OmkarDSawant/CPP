#include<bits/stdc++.h>

using namespace std;

void printMazeWithJumps(int sr, int sc, int dr, int dc, string path){

    if(sr==dr && sc==dc){
        cout<<path<<"\n";
        return;
    }

    for(int i=1; i <= dr-sr; i++){
        printMazeWithJumps(sr+i,sc,dr,dc,path+'v'+to_string(i));
    }

    for(int i=1; i <= dc-sc; i++){
        printMazeWithJumps(sr,sc+i,dr,dc,path+'h'+to_string(i));
    }

    for(int i=1; i <= dc-sc && i<= dr-sr; i++){
        printMazeWithJumps(sr+i,sc+i,dr,dc,path+'d'+to_string(i));
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    printMazeWithJumps(1,1,n,m,"");

    return 0;
}