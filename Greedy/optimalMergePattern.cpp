#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    priority_queue<int, vector<int>, greater<int> > minHeap;

    for(int i=0; i<n; i++){
        minHeap.push(a[i]);
    }
    int ans = 0;

    while(minHeap.size()>1){
        int el1 = minHeap.top();
        minHeap.pop();
        int el2 = minHeap.top();
        minHeap.pop();
        ans += el1+el2;
        minHeap.push(el1+el2);
    }

    cout<<ans;
    return 0;
}