#include<bits/stdc++.h>

using namespace std;

//Variation of sliding window.
int main(){
    int n,k;cin>>n;cin>>k;
    vector<int> a(n);

    for(auto &i : a){
        cin>>i;
    }

    int i=0;
    int zerocount = 0;
    int ans=0;

    for(int j=0;j<n;j++){
        if(a[j]==0){
            zerocount++;
        }
        while(zerocount>k){
            if(a[i]==0){
                zerocount--;
            }
            i++;
        }
        ans = max(ans,j-i+1);
    }
    cout<<ans;
    return 0;
}