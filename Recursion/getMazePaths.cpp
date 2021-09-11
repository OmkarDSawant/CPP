#include<bits/stdc++.h>

using namespace std;

vector<string> getMazePaths(int sr, int sc, int dr, int dc){

    if(sr==dr && sc==dc){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }

    vector<string> vpaths,hpaths;

    if(sr<dr){
        vpaths = getMazePaths(sr+1,sc,dr,dc);
    }

    if(sc<dc){
        hpaths = getMazePaths(sr,sc+1,dr,dc);
    }

    vector<string> ans;

    for(auto value : vpaths){
        ans.push_back("v"+value);
    }

    for(auto value : hpaths){
        ans.push_back("h"+value);
    }

    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<string> ans = getMazePaths(0,0,n-1,m-1);

    for(auto val : ans){
        cout<<val<<"\n";
    }

    return 0;
}