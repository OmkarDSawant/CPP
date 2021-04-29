#include<iostream>

using namespace std;

string arr[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


void phone(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }

    char ch = s[0];
    int num = ch - '0';
    string letters = arr[num];

    string ros = s.substr(1);

    for(int i=0; i<letters.length();i++){
        phone(ros,ans+letters[i]);
    }
}

int main(){
    phone("23","");
    return 0;
}