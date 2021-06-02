#include<iostream>
#include<stack>

using namespace std;


bool balanced(string s){
    bool res = true;
    stack<char> st;

    for(int i=0;i<s.length();i++){
        if(s[i]=='{' || s[i]=='[' || s[i]=='('){
            st.push(s[i]);
        }
        else if (s[i]==')')
        {
            if(!st.empty() && st.top()=='('){
                st.pop();
            }else{
                res = false;
                return res;
            }
        }
        else if (!st.empty() && s[i]=='}')
        {
            if(st.top()=='{'){
                st.pop();
            }else{
                res = false;
                return res;
            }
        }
        else if (!st.empty() && s[i]==']')
        {
            if(st.top()=='['){
                st.pop();
            }else{
                res = false;
                return res;
            }
        }
        else{
            res = false;
            return res;
        }
    }
    if(!st.empty()){
        res = false;
        return res;
    }
    return res;
}

int main(){
    cout<<balanced("{[()}]");
    return 0;
}