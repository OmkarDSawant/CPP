#include<iostream>
#include<unordered_set>

using namespace std;

void generateSelections(int ls, string ustr, string asf, int cs, int ts){

    
    if(cs == ts){
        cout<<asf<<"\n";
        return;
    }

    for(int i = ls+1; i<ustr.size(); i++){
        generateSelections(i, ustr, asf+ustr[i], cs+1, ts);
    }
}

int main(){

    string str;
    cin>>str;

    int k;
    cin>>k;

    unordered_set<char> st;

    string ustr = "";

    for(int i=0; i<str.size(); i++){
        if( st.find(str[i]) == st.end() ){
            st.insert(str[i]);
            ustr += str[i];
        }
    }

    generateSelections(-1, ustr, "", 0, k);


    return 0;
}