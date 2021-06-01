#include<iostream>
#include<stack>
#include<string>

using namespace std;

void reverseSentence(string s){
    stack<string> words;

    for(int i=0;i<s.length();i++){
        
        string word="";
        while(s[i]!=' ' && i<s.length()){
            word+=s[i];
            i++;
        }
        words.push(word);
    }

    while(!words.empty()){
        cout<<words.top()<<" ";
        words.pop();
    }
}

int main(){
    string s = "Hey, how are you doing?";
    reverseSentence(s);
    return 0;
}