#include<bits/stdc++.h>

using namespace std;

vector<string> getSubsequence(string str){
    if(str.length()==0){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }

    char ch = str[0];
    string ros = str.substr(1);

    vector<string> ians = getSubsequence(ros);

    vector<string> ans;

    for(auto value : ians){
        ans.push_back(ch + value);
        ans.push_back(value);
    }

    return ans;
}

int main(){
    string str;
    cin>>str;

    vector<string> ans = getSubsequence(str);

    for(auto i : ans){
        cout<<i<<"\n";
    }

    return 0;
}