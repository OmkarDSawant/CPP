#include<bits/stdc++.h>

using namespace std;

void printPaths(int n, string path){
    if(n==0){
        cout<<path<<"\n";
        return;
    }

    if(n<0){
        return;
    }

    printPaths(n-1,path+"1");
    printPaths(n-2,path+"2");
    printPaths(n-3,path+"3");
}

int main(){
    int n;
    cin>>n;

    printPaths(n,"");

    return 0;
}