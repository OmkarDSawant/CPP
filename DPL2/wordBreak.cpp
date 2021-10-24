#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;

    unordered_set<string> st;

    string str;
    for(int i=0; i<n; i++){
        cin>>str;
        st.insert(str);
    }

    string word;
    cin>>word;

    vector<int> dp(word.length(),0);

    for(int i=0; i<word.length(); i++){
        for(int j=0; j<=i; j++){
            
            string w2check = word.substr(j,(i-j)+1); 
            if(st.find(w2check) != st.end()){
                if(j>0){
                    dp[i] += dp[j-1];
                }else{
                    dp[i] += 1;
                }
            }

        }
    }

    cout<<dp[word.length()-1];

    return 0;
}