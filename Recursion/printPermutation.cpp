#include<bits/stdc++.h>

using namespace std;

void printPermutation(string que, string ans){
    if(que.length()==0){
        cout<<ans<<"\n";
        return;
    }

    for(int i=0; i<que.length(); i++){
        char ch = que[i];
        string ros = que;
        ros.erase(i,1);
        printPermutation(ros,ans+ch);
    }
}

int main(){

    string str;
    cin>>str;

    printPermutation(str,"");

    return 0;
}