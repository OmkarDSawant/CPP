#include<bits/stdc++.h>

using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string path){

    if(sr==dr && sc==dc){
        cout<<path<<"\n";
        return;
    }

    if(sr<dr){
        printMazePaths(sr+1,sc,dr,dc,path+"v");
    }
    
    if(sc<dc){
        printMazePaths(sr,sc+1,dr,dc,path+"h");
    }
}

int main(){

    int n,m;
    cin>>n>>m;

    printMazePaths(0,0,n-1,m-1,"");

    return 0;
}