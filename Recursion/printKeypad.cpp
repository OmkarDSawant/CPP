#include<bits/stdc++.h>

using namespace std;

vector<string> kpcArray {".;","abc","def","ghi","jkl","mno","pqrs","tu","vwx","yz"};

void printKPC(string que, string ans){

    if(que.length()==0){
        cout<<ans<<"\n";
        return;
    }

    char ch = que[0];
    string ros = que.substr(1);

    string charcode = kpcArray[ch-'0'];

    for(int i=0; i<charcode.length(); i++){
        printKPC(ros,ans+charcode[i]);
    }
}

int main(){

    string str;
    cin>>str;

    printKPC(str,"");

    return 0;
}