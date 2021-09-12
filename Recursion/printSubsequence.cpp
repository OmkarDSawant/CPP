#include<bits/stdc++.h>

using namespace std;

void printSS(string que, string ans){
    if(que.length()==0){
        cout<<ans<<"\n";
        return;
    }

    char ch = que[0];
    string ros = que.substr(1);

    printSS(ros,ans + ch);
    printSS(ros,ans);
}

int main(){
    string str;
    cin>>str;

    printSS(str,"");
    return 0;
}