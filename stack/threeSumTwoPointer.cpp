#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,target;cin>>n;cin>>target;
    bool ans=false;

    vector<int> a(n);

    for(auto &i : a){
        cin>>i;
    }

    sort(a.begin(),a.end()); //N logN

    for(int i=0;i<n;i++){
        int lo=i+1;
        int hi=n-1;

        while(lo<hi){
            int current = a[i]+a[lo]+a[hi];

            if(current==target){
                ans=true;
                cout<<ans;
                return 0;
            }
            else if(current<target){
                lo++;
            }
            else{
                hi--;
            }
        }
    }
    cout<<ans;

    return 0;
}