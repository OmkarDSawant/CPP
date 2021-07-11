#include<iostream>
#include<unordered_map>

using namespace std;

int main(){

    int n;cin>>n;
    int k;cin>>k;
    int a[n];

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    unordered_map<int,int> mp;

    for(int i=0; i<n; i++){

        if(mp[a[i]] == 0){
            if(mp.size() == k){
                break;
            }
            mp[a[i]]++;
        }else{
            mp[a[i]]++;
        }
    }

    unordered_map<int,int> :: iterator it;

    for(it = mp.begin(); it != mp.end(); it++){
        if( (it->second)!=0)
            cout<<it->first<<" -> "<<it->second<<"\n";
    }

    return 0;
}