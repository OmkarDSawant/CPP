#include<iostream>

using namespace std;

int maze(int n,int i,int j){//size of maze, starting values

    if(i==(n-1) && j==(n-1)){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }

    
    return maze(n,i+1,j) + maze(n,i,j+1);
}

int main(){
    cout<<maze(3,0,0);
    return 0;
}