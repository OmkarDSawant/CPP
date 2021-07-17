#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main(){

    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<pair<int,int>> a(n);

        for(int i=0; i<n; i++){
            cin>>a[i].first>>a[i].second;
        }

        int l,p;
        cin>>l>>p;

        for(int i=0; i<n; i++){
            a[i].first = l - a[i].first; //distance between truck and fuel stop.
        }

        sort(a.begin(),a.end());

        int curr = p;
        int ans = 0;
        int flag = 0;
        priority_queue<int,vector<int>> maxHeap;

        for(int i=0; i<n; i++){
            if(curr>=l){
                break;
            }
            while(curr<a[i].first){
                if(maxHeap.empty()){
                    flag = 1;
                    break;
                }
                curr += maxHeap.top();
                maxHeap.pop();
                ans++;
            }
            if(flag){
                break;
            }
            maxHeap.push(a[i].second);
        }
        if(flag){
            cout<<"-1";
            break;
        }
        while(!maxHeap.empty() && curr<l){
            curr += maxHeap.top();
            maxHeap.pop();
            ans++;
        }
        if(curr<l){
            cout<<"-1";
            break;
        }
        cout<<ans;
    }

    return 0;
}