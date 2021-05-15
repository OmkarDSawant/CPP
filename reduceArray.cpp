#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool myCompare(pair<int,int>p1,pair<int,int>p2){
    return p1.first<p2.first;
}

int main(){
    int arr[]={4,8,3,5,7,1,2};
    //sizeof returns total size i.e (no.of elements * datatype)
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<pair<int,int>> v;
    
    for(int i=0;i<n;i++){
        v.push_back(make_pair(arr[i],i));
    }

    sort(v.begin(),v.end(),myCompare);

    for(int i=0;i<n;i++){
        arr[v[i].second] = i;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

    return 0;
}