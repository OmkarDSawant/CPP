#include<bits/stdc++.h>

using namespace std;

vector<string> getPaths(int n){
    if(n==0){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }

    if(n<0){
        vector<string> bres;
        return bres;
    }

    vector<string> paths1 = getPaths(n-1);
    vector<string> paths2 = getPaths(n-2);
    vector<string> paths3 = getPaths(n-3);

    vector<string> ans;

    for(auto value : paths1){
        ans.push_back("1"+value);
    }

    for(auto value : paths2){
        ans.push_back("2"+value);
    }

    for(auto value : paths3){
        ans.push_back("3"+value);
    }

    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<string> ans = getPaths(n);

    for(auto i : ans){
        cout<<i<<"\n";
    }

    return 0;
}