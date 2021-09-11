#include<bits/stdc++.h>

using namespace std;

vector<string> getMPaths(int sr, int sc, int dr, int dc){
    if(sr==dr && sc==dc){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }

    
    vector<string> ans;

    for(int i=1; i<=dc-sc; i++){

        vector<string> hpaths = getMPaths(sr,sc+i,dr,dc);

        for(auto val : hpaths){
            ans.push_back("h" + to_string(i) + val);
        }
    }

    for(int i=1; i<=dr-sr; i++){
        
        vector<string> vpaths = getMPaths(sr+i,sc,dr,dc);

        for(auto val : vpaths){
            ans.push_back("v" + to_string(i) + val);
        }
    }

    for(int i=1; i<=dr-sr && i<=dc-sc; i++){
        
        vector<string> dpaths = getMPaths(sr+i,sc+i,dr,dc);

        for(auto val : dpaths){
            ans.push_back("d" + to_string(i) + val);
        }
    }

    return ans;
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<string> ans = getMPaths(0,0,n-1,m-1);

    for(auto val : ans){
        cout<<val<<"\n";
    }

    return 0;
}