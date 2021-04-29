#include<iostream>

using namespace std;

void subSeq(string s, string ans){

    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch = s[0];
    int code = ch;

    string ros = s.substr(1);

    subSeq(ros,ans);
    subSeq(ros,ans+ch);
    subSeq(ros,ans + to_string(code));
}

int main(){
    subSeq("AB","");
    return 0;
}