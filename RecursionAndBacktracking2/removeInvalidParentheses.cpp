#include<iostream>
#include<stack>
#include<unordered_set>

using namespace std;

unordered_set<string> unique;

int minRemoval(string str){
    stack<char> st;

    for(int i=0; i<str.size(); i++){
        if(str[i] == '('){
            st.push(str[i]);
        }else if(st.size() == 0){
            st.push(str[i]);
        }else if(st.top() == '('){
            st.pop();
        }else{
            st.push(str[i]);
        }
    }

    return st.size();
}

void solution(string pattern, int count){
    
    if(count==0){
        int cc = minRemoval(pattern);
        if(cc == 0){
            if(unique.find(pattern) == unique.end()){
                unique.insert(pattern);
                cout<<pattern<<"\n";
            }
        }

        return;
    }

    for(int i=0; i<pattern.size(); i++){
        string left = pattern.substr(0,i);
        string right = pattern.substr(i+1);

        solution(left+right, count-1);
    }
}

int main(){

    string pattern;
    cin>>pattern;

    int count = minRemoval(pattern);

    if(count == 0){
        cout<<pattern;
    }else{
        solution(pattern, count);
    }

    return 0;
}