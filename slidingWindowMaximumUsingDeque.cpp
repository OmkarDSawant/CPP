#include<bits/stdc++.h>

using namespace std;

int main(){

    int n,k; cin>>n; cin>>k;

    vector<int> a(n);

    for(auto &i : a){
        cin>>i;
    }

    deque<int> q;
    vector<int> ans;

    //Arrange elements in non increasing order.

    for(int i=0;i<k;i++){
        while(!q.empty() && a[q.back()] < a[i]){
            q.pop_back();
        }
        q.push_back(i); //pushing index for a reason.
    }
    ans.push_back(a[q.front()]);


    for(int i=k;i<n;i++){
        if(q.front()==i-k){ //excluding one element iteratively.
            q.pop_front();
        }

        while(!q.empty() && a[q.back()] < a[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);

    }

    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<"\n";

    return 0;
}