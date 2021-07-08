#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    int n;cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    unordered_map<int,int> freq;
    for(int i=0; i<n; i++){
        freq[a[i]]++;
    }

    unordered_map<int,int> :: iterator it;

    for(it=freq.begin();it!=freq.end();it++){
        cout<<it->first<<" -> "<<it->second<<"\n";
    }
    return 0;
}