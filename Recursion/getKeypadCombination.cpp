#include<bits/stdc++.h>

using namespace std;

vector<string> kpcArray {".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};

vector<string> getKPC(string str){

    if(str.length()==0){
        vector<string> bres;
        bres.push_back("");
        return bres;
    }
    char ch = str[0];
    string ros = str.substr(1);

    vector<string> ians = getKPC(ros);

    vector<string> ans;
    for(int i=0; i<kpcArray[ch - '0'].length(); i++){
        for(auto value : ians){
            ans.push_back(kpcArray[ch - '0'][i] + value);
        }
    }

    return ans;
}

int main(){
    string str;
    cin>>str;

    vector<string> ans = getKPC(str);

    for(auto i : ans){
        cout<<i<<"\n";
    }

    return 0;
}