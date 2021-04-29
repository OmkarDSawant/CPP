#include<iostream>

using namespace std;

string removeDup(string s){
    if(s.length()==0){
        return "";
    }

    char ch = s[0];
    string ros = removeDup(s.substr(1));
    if(ch==ros[0]){
        return ros;
    }else{
        return (ch+ros);
    }
}

int main(){
    cout<<removeDup("aaabbbcccddefff");
    return 0;
}