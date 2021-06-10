#include<bits/stdc++.h>

using namespace std;
//Variation of sliding window
int main(){

    string s;cin>>s;

    vector<int> dict (256,-1);
    int start = -1;
    int ans = 0;

    for(int i=0;i<s.size();i++){
        if(dict[s[i]]>start){
            start = dict[s[i]];
        }
        dict[s[i]]=i;
        ans=max(ans,i-start);
    }

    cout<<ans;

    return 0;
}