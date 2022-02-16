//Levels - Boxes
#include<iostream>
#include<unordered_set>

using namespace std;

void getSelection(int ci, string ustr, string asf, int cs, int ts){

    if(ci == ustr.size()){
        if(cs == ts){
            cout<<asf<<"\n";
        }
        
        return;
    }

    char ch = ustr[ci];

    getSelection(ci+1, ustr, asf + ch, cs+1, ts);
    getSelection(ci+1, ustr, asf, cs, ts);

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

    getSelection(0, ustr, "", 0, k);



    return 0;
}