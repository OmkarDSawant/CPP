#include<iostream>
#include<unordered_set>

using namespace std;

void solution(unordered_set<string> &set, string st, string ans){

    if(st.size() == 0){
        cout<<ans<<"\n";
        return;
    }

    for(int i=0; i<st.size(); i++){
        string left = st.substr(0,i+1);
        if(set.find(left) != set.end()){
            string right = st.substr(left.size());
            solution(set, right, ans+left+" ");
        }
    }
}

int main(){

    int n;
    cin>>n;

    unordered_set<string> set;

    string temp;
    for(int i=0; i<n; i++){
        cin>>temp;
        set.insert(temp);
    }

    string str;
    cin>>str;

    solution(set, str, "");
    return 0;
}